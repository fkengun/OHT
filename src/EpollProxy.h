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
 * EpollProxy.h
 *
 *  Created on: Oct 5, 2012
 *      Author: fkengun
 *      Contributor: Tony
 */

#ifndef EPOLLPROXY_H_
#define EPOLLPROXY_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include "ZProcessor.h"
#include <queue>

#include "bigdata_transfer.h"
#include "EpollServer.h"

using namespace std;

namespace iit {
namespace datasys {
namespace zht {
namespace dm {

/*
 *
 */
class EpollProxy {
public:
	EpollProxy(const char *port, ZProcessor *processor);
	virtual ~EpollProxy();

	void serve();

private:
	int create_and_bind(const char *port);
	int create_and_bind(const char *host, const char *port);
	int make_socket_non_blocking(const int& sfd);
	int makeSvrSocket();
	int reuseSock(int sock);
	void init_thread();

private:
	static void* threadedServe(void *arg);

private:
	EpollProxy();

private:
	bool _tcp;
	const char *_port;
	BdRecvBase *pbrb;
	ZProcessor *_ZProcessor;
	queue<EventData> _eventQueue;

private:
	static const int MAX_EVENTS;

};

} /* namespace dm */
} /* namespace zht */
} /* namespace datasys */
} /* namespace iit */
#endif /* EPOLLPROXY_H_ */
