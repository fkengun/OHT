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
 * ip_server.cpp
 *
 *  Created on: Jul 5, 2013
 *      Author: Xiaobingo
 *      Contributor: Tony, KWang, DZhao
 */

#include "ip_server.h"

#include  "ProxyStubFactory.h"
#include "ZHTUtil.h"
#include "zpack.pb.h"

#include <string.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>

/* added by fk for OHT */
#include <netdb.h>
/* end add */

using namespace std;

IPServer::IPServer() :
_stub(ProxyStubFactory::createStub()) {
    count = 0; // added by fk for OHT
}

IPServer::~IPServer() {

    if (_stub != NULL) {

        delete _stub;
        _stub = NULL;
    }
}

void IPServer::process(const int& fd, const char * const buf, sockaddr sender) {

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
    /* added by fk for OHT*/
    string result("result");
    _stub->sendBack(pa, result.data(), result.size());
    //printf("OHT: socket fd %d\n", pa.fd);
    //printf("OHT: msg received %s", bufstr.c_str());
    respond(bufstr.c_str(), pa);
    /* end add */
    _stub->recvsend(pa, bufstr.c_str());

    close(pa.fd);
}

void IPServer::respond(const char * const buf, ProtoAddr& addr) {
    /* get the dest client from zpack */
    string msg((char *) buf);
    ZPack zpack;
    HostEntity client;
    
    zpack.ParseFromString(msg);
    client.host = zpack.client_ip();
    client.port = zpack.client_port();
    printf("OHT: Respond to client: %s, port: %d, count: %d\n", client.host.c_str(), client.port, count++);
    
    /* connect with the client */
    struct sockaddr_in dest;
    memset(&dest, 0, sizeof (struct sockaddr_in)); /*zero the struct*/
    dest.sin_family = PF_INET; /*storing the server info in sockaddr_in structure*/
    dest.sin_port = htons(client.port);

    struct hostent * hinfo = gethostbyname(client.host.c_str());
    if (hinfo == NULL) {
        fprintf(stderr, "TCPProxy::makeClientSocket(): \n");
        herror(client.host.c_str());
        return;
    }

    memcpy(&dest.sin_addr, hinfo->h_addr, sizeof (dest.sin_addr));

    int sock = socket(PF_INET, SOCK_STREAM, 0); //try change here.................................................

    if (sock < 0) {
        perror("TCPProxy::makeClientSocket(): error on ::socket(...): ");
        return;
    }

    int ret_con = connect(sock, (struct sockaddr *) &dest, sizeof (sockaddr));

    if (ret_con < 0) {
        printf("OHT: cannot connection with client\n");
        perror("TCPProxy::makeClientSocket(): error on ::connect(...): ");
        return;
    }

    /* make the socket reusable */
    int reuse_addr = 1;
    int ret = setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,
            sizeof (reuse_addr));
    if (ret < 0) {
        perror("reuse socket failed: ");
        return;
    }
    
    /* set the address */
    addr.fd = sock;
    addr.sender = calloc(1, sizeof (sockaddr));
    memcpy(addr.sender, &dest, sizeof (sockaddr));
}
