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
 * ZHTUtil.cpp
 *
 *  Created on: Jun 25, 2013
 *      Author: Tony
 *      Contributor: Xiaobingo, KWang, DZhao
 */

#include <time.h>
#include <sys/time.h>

#include "ZHTUtil.h"

#include "Util.h"
#include "ConfHandler.h"

#define __STDC_FORMAT_MACROS
#include <inttypes.h>

#include <arpa/inet.h>
#include <algorithm>
#include <netdb.h>

#include  "zpack.pb.h"

using namespace iit::datasys::zht::dm;

ZHTUtil::ZHTUtil() {
}

ZHTUtil::~ZHTUtil() {
}

HostEntity ZHTUtil::getHostEntityByKey(const string& msg) {
	struct timeval tv;
	ZPack zpack;
	zpack.ParseFromString(msg); //to debug

	uint64_t hascode = HashUtil::genHash(zpack.key());
	size_t node_size = ConfHandler::NeighborVector.size();

	int repNum = atoi(ConfHandler::getNumReplicaFromConf().c_str());
	int index = hascode % repNum;
	index = index * repNum;

	//printf("OHT: hashcode %" PRIu64 ", node_size %d, index %d\n", hascode, node_size, index);
	printf("OHT: hashcode ,node_size %d, index %d, rep %d\n", node_size, index, repNum);
	// OHT: if the proxy is down, use another replica
	if (ConfHandler::NeighborVector.at(index).mark() == 1) {
		printf("OHT: get Host entity by key error\n");

		int randomNumber=0;

		randomNumber = rand()%(repNum-1)+1;
		//for(int i = 0 ; i < 100 ; i ++)
			//printf("%d\n",rand()%(repNum-1));
		index += randomNumber;
		printf("OHT: getHostentity %d\n",index);
	}
	ConfEntry ce = ConfHandler::NeighborVector.at(index);

	return buildHostEntity(ce.name(), atoi(ce.value().c_str()));

}

/* added by fk for OHT, used in proxy to locate the server */
HostEntity ZHTUtil::getServerEntityByKey(const string& msg) {

	ZPack zpack;
	zpack.ParseFromString(msg); //to debug

	uint64_t hascode = HashUtil::genHash(zpack.key());
	size_t node_size = ConfHandler::PrimaryServerVector.size();
	int index = hascode % node_size;
	//printf("OHT: hashcode %" PRIu64 ", node_size %d, index %d\n", hascode, node_size, index);

	ConfEntry ce = ConfHandler::PrimaryServerVector.at(index);

	return buildHostEntity(ce.name(), atoi(ce.value().c_str()));
}
/* end add */

HostEntity ZHTUtil::buildHostEntity(const string& host, const uint& port) {

	HostEntity he;

	/*
	 struct sockaddr_in si_other;
	 hostent *record;
	 in_addr *address;
	 string ip_address;

	 record = gethostbyname(host.c_str());
	 address = (in_addr *) record->h_addr;
	 ip_address = inet_ntoa(*address);

	 memset((char *) &si_other, 0, sizeof(si_other));
	 si_other.sin_family = AF_INET;
	 si_other.sin_port = htons(port);
	 if (inet_aton(ip_address.c_str(), &si_other.sin_addr) == 0) {
	 fprintf(stderr, "inet_aton() failed\n");
	 }

	 he.si = si_other;
	 he.host = host;
	 he.port = port;
	 he.valid = true;
	 he.sock = -1;*/

	he.host = host;
	he.port = port;
	he.sock = -1;

	return he;
}

const uint IdHelper::ID_LEN = 20;

IdHelper::IdHelper() {
}

IdHelper::~IdHelper() {
}

uint64_t IdHelper::genId() {

	return HashUtil::genHash(HashUtil::randomString(62).c_str());
}

