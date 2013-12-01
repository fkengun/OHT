/*
 * Copyright 2010-2020 DatasysLab@iit.edu(http://datasys.cs.iit.edu/index.html)
 *      Director: Ioan Raicu(iraicu@cs.iit.edu)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * This file is part of ZHT library(http://datasys.cs.iit.edu/projects/ZHT/index.html).
 *      Tonglin Li(tli13@hawk.iit.edu) with nickname Tony,
 *      Xiaobing Zhou(xzhou40@hawk.iit.edu) with nickname Xiaobingo,
 *      Ke Wang(kwang22@hawk.iit.edu) with nickname KWang,
 *      Dongfang Zhao(dzhao8@@hawk.iit.edu) with nickname DZhao,
 *      Ioan Raicu(iraicu@cs.iit.edu).
 *
 * ip_proxy.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: fkengun
 *      Contributor: Tony
 */

#include "ip_proxy.h"

#include  "ProxyStubFactory.h"

/* added by fk for OHT */
#include "Env.h"
#include "Const.h"
#include "ZHTUtil.h"
#include "ConfEntry.h"
#include "ConfHandler.h"
#include "zpack.pb.h"
#include "ip_proxy_stub.h"
#include "bigdata_transfer.h"
#include <netdb.h>
#include <sys/socket.h>
#include <iostream>
/* end add */

#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
using namespace iit::datasys::zht::dm;

IPProxy::IPProxy() :
_stub(ProxyStubFactory::createStub()),
_proxy(ProxyStubFactory::createProxy()) {
    count = 0;
    local_port = "";
}

IPProxy::~IPProxy() {

    if (_stub != NULL) {

        delete _stub;
        _stub = NULL;
    }
    if (_proxy != NULL) {

        delete _proxy;
        _proxy = NULL;
    }

}

void IPProxy::process(const int& fd, const char * const buf, sockaddr sender) {

    if (_stub == 0) {

        fprintf(stderr,
                "IPServer::process(): error on ProxyStubFactory::createStub().\n");
        return;
    }

    ProtoAddr pa;
    pa.fd = fd;
    pa.sender = calloc(1, sizeof (sockaddr));
    memcpy(pa.sender, &sender, sizeof (sockaddr));

    /* added by fk for OHT, set local port */
    if (local_port.length() == 0)
        local_port = getLocalPort(fd);
    /* end add */

    string bufstr(buf);
    //_stub->recvsend(pa, bufstr.c_str()); // commented by fk for hierarchical proxy
    forward(pa, bufstr.c_str());
}

/* added by fk for OHT */
void IPProxy::forward(ProtoAddr addr, const void *recvbuf) {
    //printf("OHT: forward invoked\n");
    //printf("\nOHT: recvbuf: %s\n\n", recvbuf);

    string recvstr((char *) recvbuf);
    ZPack zpack;
    ZHTUtil zu;

    /* update server vector when receive a special zapck */
    zpack.ParseFromString(recvstr);
    string opcode = zpack.opcode();
    if (opcode == Const::ZSC_OPC_SRVUPDT) {
        string entry_str = zpack.client_ip();
        entry_str += ",";
        char p_port[10];
        sprintf(p_port, "%d", zpack.client_port());
        entry_str += p_port;
        ConfEntry ce;
        ce.assign(entry_str);
        cout << "OHT: receive update msg for " << ce.toString() << endl;
        ConfHandler::updateServerVector(ce, ConfHandler::othersServerVector);
        ConfHandler::updateServerVector(ce, ConfHandler::othersServerVector);
        /* send an acknowledge to original proxy */
        string result("result");
        _stub->sendBack(addr, result.data(), result.size());
        cout << "OHT: an ack has been sent back to original proxy" << endl;

        return;
    }

    /* send an acknowledge to client */
    string result("result");
    _stub->sendBack(addr, result.data(), result.size());
    //cout << "OHT: an ack: " << count++ << " has been sent back to client"  << endl;

    /* calculate the dest server */
    zpack.ParseFromString(recvstr);
    HostEntity he = zu.getServerEntityByKey(recvstr);
    //cout << "OHT: Forwarding to server: " << he.host.c_str() << ", port: " << he.port << endl;

    /* connect with server */
    int sock = _proxy->makeClientSocket(he.host, he.port);
    if (sock < 0) {
        /* send update msg to other proxies when fails to connect a server */
        cout << "OHT: find failure server " << he.host << ", " << he.port << endl;
        ConfEntry ce;
        char p_port[10];
        sprintf(p_port, "%d", he.port);
        string portStr = p_port;
        ce.name(he.host);
        ce.value(portStr);
        ConfHandler::updateServerVector(ce, ConfHandler::myServerVector);
        bcastServerUpdate(he.host, he.port);
    } else {
        _proxy->reuseSock(sock);
    }

    /* add IP address and port to zpack msg */
    HostEntity client;
    getClientEntityBySock(addr.fd, client);
    zpack.set_client_ip(client.host);
    zpack.set_client_port(client.port);

    /* forward the request to server */
    recvstr = zpack.SerializeAsString();
    char *buf = (char*) calloc(Env::get_msg_maxsize(), sizeof (char));
    size_t msz = Env::get_msg_maxsize();
    _proxy->recvforward(recvstr.c_str(), recvstr.size(), buf, msz);

    free(buf);
    //cout << "OHT: Request has been forward to server successfully" << endl;

    close(sock);
    //cout << "OHT: socket has been closed" << endl;
}

void IPProxy::getClientEntityBySock(int sock, HostEntity& he) {
    socklen_t len;
    struct sockaddr_storage addr;
    char ipstr[INET6_ADDRSTRLEN];
    int port;

    len = sizeof addr;
    getpeername(sock, (struct sockaddr*) &addr, &len);

    // deal with both IPv4 and IPv6:
    if (addr.ss_family == AF_INET) {
        struct sockaddr_in *s = (struct sockaddr_in *) &addr;
        port = ntohs(s->sin_port);
        inet_ntop(AF_INET, &s->sin_addr, ipstr, sizeof ipstr);
    } else { // AF_INET6
        struct sockaddr_in6 *s = (struct sockaddr_in6 *) &addr;
        port = ntohs(s->sin6_port);
        inet_ntop(AF_INET6, &s->sin6_addr, ipstr, sizeof ipstr);
    }

    he.host = string(ipstr);
    he.port = port;
    //printf("Peer IP address: %s, port: %d\n", ipstr, port);
}

void IPProxy::bcastServerUpdate(string ip, int port) {
    ZPack zpack;

    zpack.set_opcode(Const::ZSC_OPC_SRVUPDT);
    zpack.set_client_ip(ip.c_str());
    zpack.set_client_port(port);
    string msg = zpack.SerializeAsString();

    int sock;
    char *buf = (char*) calloc(Env::get_msg_maxsize(), sizeof (char));
    size_t msz = Env::get_msg_maxsize();
    int selfIdx = ConfHandler::getIndexOfProxy(this->local_port);
    cout << "OHT: my index in neighbor list is " << selfIdx << endl;
    for (int i = 0; i < ConfHandler::NeighborVector.size(); i++) {
        if (i == selfIdx)
            continue;

        string neighborIp;
        int neighborPort;
        getAddrFromConfEntry(ConfHandler::NeighborVector[i], neighborIp, neighborPort);
        sock = _proxy->makeClientSocket(neighborIp, neighborPort);
        if (sock >= 0) {
            _proxy->reuseSock(sock);
            cout << "OHT: create sock with " << neighborIp << ", " << neighborPort << " succeed" << endl;
            BdSendBase *pbsb = new BdSendToServer((char*) msg.c_str());
            int sentSize = pbsb->bsend(sock);
            delete pbsb;
            pbsb = NULL;

            //prompt errors
            if (sentSize < msg.length()) {

                //todo: bug prone
                /*cerr << "TCPProxy::sendTo(): error on BdSendToServer::bsend(...): "
                 << strerror(errno) << endl;*/
            }

            _proxy->recvFrom(sock, buf);
        } else {
            cout << "OHT: create sock with " << neighborIp << ", " << neighborPort << " fails" << endl;
        }

        close(sock);
    }
    free(buf);
}

string IPProxy::getLocalPort(int sock) {
    struct sockaddr_in sin;
    socklen_t addrlen = sizeof (sin);
    if (getsockname(sock, (struct sockaddr *) &sin, &addrlen) == 0 &&
            sin.sin_family == AF_INET &&
            addrlen == sizeof (sin)) {
        int port = ntohs(sin.sin_port);
        printf("OHT: local port is %d\n", port);
        char p_port[10];
        sprintf(p_port, "%d", port);
        string portStr = p_port;
        return portStr;
    } else
        ; // handle error
}

void IPProxy::getAddrFromConfEntry(ConfEntry ce, string &ip, int &port) {
    cout << "OHT: get addr info for " << ce.toString() << " ..." << endl;
    string entryStr = ce.toString();
    string delimiter = ",";
    ip = entryStr.substr(0, entryStr.find(delimiter));
    if (ip == "localhost")
        ip = "127.0.0.1";
    port = atoi(entryStr.substr(entryStr.find(delimiter) + 1).c_str());
}
