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
 * ipc_proxy.h
 *
 *  Created on: Oct 5, 2013
 *      Author: fkengun
 *      Contributor: Tony
 */

#ifndef IPRPOXY_H_
#define IPRPOXY_H_

#include "ZProcessor.h"
#include "proxy_stub.h"
/* added by fk for OHT */
#include "ZHTUtil.h"
/* end add */

using namespace iit::datasys::zht::dm;

/*
 *
 */
class IPProxy: public ZProcessor {
public:
	IPProxy();
	virtual ~IPProxy();

	virtual void process(const int& fd, const char * const buf, sockaddr sender);

private:
        void forward(ProtoAddr addr, const void *recvbuf); // added by fk for OHT
        void getClientEntityBySock(int sock, HostEntity& he); // added by fk for OHT

	ProtoStub *_stub;
        ProtoProxy *_proxy; // added by fk for OHT, proxy node needs both stub and proxy
        int count;
};

#endif /* IPRPOXY_H_ */
