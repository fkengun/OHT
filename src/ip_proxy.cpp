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
    string opcode = zpack.opcode();
    if (opcode == Const::ZSC_OPC_SRVUPDT) {
        string entry_str = zpack.client_ip();
        entry_str += ",";
        entry_str += zpack.client_port();
        ConfEntry ce;
        ce.assign(entry_str);
        cout << "OHT: receive update msg for " << ce.toString() << endl;
        ConfHandler::updateServerVector(ce);
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
    //    int sock = getSockCached(he.host, he.port);
    //    reuseSock(sock);
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof (struct sockaddr_in)); /*zero the struct*/
    dest.sin_family = AF_INET; /*storing the server info in sockaddr_in structure*/
    dest.sin_port = htons(he.port);

    struct hostent * hinfo = gethostbyname(he.host.c_str());
    if (hinfo == NULL) {
        cerr << "TCPProxy::makeClientSocket(): ";
        herror(he.host.c_str());
        return;
    }

    memcpy(&dest.sin_addr, hinfo->h_addr, sizeof (dest.sin_addr));

    int sock = socket(PF_INET, SOCK_STREAM, 0); //try change here.................................................

    if (sock < 0) {
        cerr << "TCPProxy::makeClientSocket(): error on ::socket(...): "
                << endl;
        return;
    }

    int ret_con = connect(sock, (struct sockaddr *) &dest, sizeof (sockaddr));

    if (ret_con < 0) {
        cerr << "TCPProxy::makeClientSocket(): error on ::connect(...): "
                << endl;
        return;
    }

    /* make the socket reusable */
    int reuse_addr = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,
            sizeof (reuse_addr));
    if (ret < 0) {
        cerr << "reuse socket failed: [" << sock << "], " << endl;
        return;
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

