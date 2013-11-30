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
 * cpp_zhtclient.cpp
 *
 *  Created on: Sep 16, 2012
 *      Author: Xiaobingo
 *      Contributor: Tony, KWang, DZhao
 */

#include "cpp_zhtclient.h"

#include  <stdlib.h>
#include <string>
#include <string.h>
/* added by fk for OHT */
#include <sys/socket.h>
#include <netinet/in.h>
#include <errno.h>
#include <pthread.h>

#include "bigdata_transfer.h"
/* end add */

#include "zpack.pb.h"
#include "ConfHandler.h"
#include "ZHTUtil.h"
#include "Env.h"
#include "StrTokenizer.h"
#include <map>
using namespace iit::datasys::zht::dm;

ZHTClient::ZHTClient() :
	_proxy(0), _msg_maxsize(0) {

}

ZHTClient::ZHTClient(const string& zhtConf, const string& neighborConf) {

	init(zhtConf, neighborConf);
}

ZHTClient::~ZHTClient() {

	if (_proxy != NULL) {

		delete _proxy;
		_proxy = NULL;
	}
}

int ZHTClient::init(const string& zhtConf, const string& neighborConf) {

	ConfHandler::initConf(zhtConf, neighborConf);

	_msg_maxsize = Env::get_msg_maxsize();

	_proxy = ProxyStubFactory::createProxy();

	requestMap[0] = 0;
	pthread_t id1;
	pthread_create(&id1, NULL, ZHTClient::listeningSocket, NULL);

	if (_proxy == 0)
		return -1;
	else
		return 0;
}

int ZHTClient::init(const char *zhtConf, const char *neighborConf) {

	string szhtconf(zhtConf);
	string sneighborconf(neighborConf);

	int rc = init(szhtconf, sneighborconf);
	sem_init(&mutex, 0, 1);
	return rc;
}

int ZHTClient::commonOp(const string &opcode, const string &key,
		const string &val, const string &val2, string &result, int lease) {

	if (opcode != Const::ZSC_OPC_LOOKUP && opcode != Const::ZSC_OPC_REMOVE
			&& opcode != Const::ZSC_OPC_INSERT && opcode
			!= Const::ZSC_OPC_APPEND && opcode != Const::ZSC_OPC_CMPSWP
			&& opcode != Const::ZSC_OPC_STCHGCB)
		return Const::toInt(Const::ZSC_REC_UOPC);

	string sstatus = commonOpInternal(opcode, key, val, val2, result, lease);

	int status = Const::ZSI_REC_CLTFAIL;
	if (!sstatus.empty())
		status = Const::toInt(sstatus);

	return status;
}

int ZHTClient::lookup(const string &key, string &result) {

	string val;
	string val2;
	int rc = commonOp(Const::ZSC_OPC_LOOKUP, key, val, val2, result, 1);

	result = extract_value(result);

	return rc;
}

int ZHTClient::lookup(const char *key, char *result) {

	string skey(key);
	string sresult;

	int rc = lookup(skey, sresult);

	strncpy(result, sresult.c_str(), sresult.size() + 1);

	return rc;
}

int ZHTClient::remove(const string &key) {

	string val;
	string val2;
	string result;
	int rc = commonOp(Const::ZSC_OPC_REMOVE, key, val, val2, result, 1);

	return rc;
}

int ZHTClient::remove(const char *key) {

	string skey(key);

	int rc = remove(skey);

	return rc;
}

int ZHTClient::insert(const string &key, const string &val) {

	string val2;
	string result;
	int rc = commonOp(Const::ZSC_OPC_INSERT, key, val, val2, result, 1);

	return rc;
}

int ZHTClient::insert(const char *key, const char *val) {

	string skey(key);
	string sval(val);

	int rc = insert(skey, sval);

	return rc;
}

int ZHTClient::append(const string &key, const string &val) {

	string val2;
	string result;
	int rc = commonOp(Const::ZSC_OPC_APPEND, key, val, val2, result, 1);

	return rc;
}

int ZHTClient::append(const char *key, const char *val) {

	string skey(key);
	string sval(val);

	int rc = append(skey, sval);

	return rc;
}

string ZHTClient::extract_value(const string &returnStr) {

	string val;

	StrTokenizer strtok(returnStr, ":");
	/*
	 * hello,zht:hello,ZHT ==> zht:ZHT
	 * */

	if (strtok.has_more_tokens()) {

		while (strtok.has_more_tokens()) {

			ZPack zpack;
			zpack.ParseFromString(strtok.next_token());

			if (zpack.valnull())
				val.append("");
			else
				val.append(zpack.val());

			val.append(":");
		}

		size_t found = val.find_last_of(":");
		val = val.substr(0, found);

	} else {

		ZPack zpack;
		zpack.ParseFromString(returnStr);

		if (zpack.valnull())
			val = "";
		else
			val = zpack.val();
	}

	return val;
}

int ZHTClient::compare_swap(const string &key, const string &seen_val,
		const string &new_val, string &result) {

	int rc = commonOp(Const::ZSC_OPC_CMPSWP, key, seen_val, new_val, result, 1);

	result = extract_value(result);

	return rc;
}

int ZHTClient::compare_swap(const char *key, const char *seen_val,
		const char *new_val, char *result) {

	string skey(key);
	string sseen_val(seen_val);
	string snew_val(new_val);
	string sresult;

	int rc = compare_swap(skey, sseen_val, snew_val, sresult);

	strncpy(result, sresult.c_str(), sresult.size() + 1);

	return rc;
}

int ZHTClient::state_change_callback(const string &key,
		const string &expected_val, int lease) {

	string val2;
	string result;

	int rc = commonOp(Const::ZSC_OPC_STCHGCB, key, expected_val, val2, result,
			lease);

	return rc;
}

int ZHTClient::state_change_callback(const char *key, const char *expeded_val,
		int lease) {

	string skey(key);
	string sexpeded_val(expeded_val);

	int rc = state_change_callback(skey, sexpeded_val, lease);

	return rc;
}

// oht: thread for a server socket
void * ZHTClient::listeningSocket(void *) {
	int port = 55555;
	struct sockaddr_in svrAdd_in;
	int svrSock = -1;
	printf("success 1\n");
	memset(&svrAdd_in, 0, sizeof(struct sockaddr_in));
	svrAdd_in.sin_family = AF_INET;
	svrAdd_in.sin_addr.s_addr = INADDR_ANY;
	svrAdd_in.sin_port = htons(port);
	printf("success 2\n");
	svrSock = socket(AF_INET, SOCK_STREAM, 0);
	printf("success 3\n");
	printf("svrSock: %d\n", svrSock);
	//ZHTClient::requestMap[2]=1;
	if (bind(svrSock, (struct sockaddr*) &svrAdd_in, sizeof(struct sockaddr))
			< 0) {
		perror("bind error");
	}
	printf("bind \n");

	if (listen(svrSock, 5) < 0) {
		printf("listen error\n");
	}
	printf("listen \n");

	/* make the socket reusable */
	int reuse_addr = 1;
	int ret = setsockopt(svrSock, SOL_SOCKET, SO_REUSEADDR, &reuse_addr,
			sizeof(reuse_addr));
	if (ret < 0) {
		cerr << "reuse socket failed: [" << svrSock << "], " << endl;
		return NULL;
	}

	sockaddr *in_addr = (sockaddr *) calloc(1, sizeof(struct sockaddr));
	socklen_t in_len = sizeof(struct sockaddr);
	int infd;
	//char *my_buf = (char*) calloc(Env::(), sizeof(char));
	//size_t my_msz = Env::get_msg_maxsize();
	char *my_buf = (char*) calloc(100, sizeof(char));
	size_t my_msz = 100;
	int counter = 0;

	while (true) {
		infd = accept(svrSock, in_addr, &in_len);

		/* make the socket reusable */
		int client_reuse = 1;
		int client_ret = setsockopt(infd, SOL_SOCKET, SO_REUSEADDR,
				&client_reuse, sizeof(client_reuse));
		if (client_ret < 0) {
			cerr << "reuse socket failed: [" << infd << "], " << endl;
			return NULL;
		}

		//printf("accept \n");
		recv(infd, my_buf, my_msz, 0);
		printf("OHT: sock is %d\n", infd);
		BdRecvBase *pbrb = new BdRecvFromServer();
		bool ready = false;
		string bd = pbrb->getBdStr(NULL, my_buf, my_msz, ready);
		//printf("%d\n",Const::toInt(bd.substr(0,3)));
		//printf("received something\n");
		// printf("thread counter %d\n",counter++);


		close(infd);
	}

	close(svrSock);
	close(infd);
	printf("OHT: listen socket is closed\n");
}

string ZHTClient::commonOpInternal(const string &opcode, const string &key,
		const string &val, const string &val2, string &result, int lease) {

	ZPack zpack;
	zpack.set_opcode(opcode); //"001": lookup, "002": remove, "003": insert, "004": append, "005", compare_swap
	zpack.set_replicanum(3);
	if (key.empty())
		return Const::ZSC_REC_EMPTYKEY; //-1, empty key not allowed.
	else
		zpack.set_key(key);

	if (val.empty()) {

		zpack.set_val("^"); //coup, to fix ridiculous bug of protobuf! //to debug
		zpack.set_valnull(true);
	} else {

		zpack.set_val(val);
		zpack.set_valnull(false);
	}
	if (val2.empty()) {

		zpack.set_newval("?"); //coup, to fix ridiculous bug of protobuf! //to debug
		zpack.set_newvalnull(true);
	} else {

		zpack.set_newval(val2);
		zpack.set_newvalnull(false);
	}

	zpack.set_lease(Const::toString(lease));

	string msg = zpack.SerializeAsString();

	/*ZPack tmp;
	 tmp.ParseFromString(msg);
	 printf("{%s}:{%s,%s}\n", tmp.key().c_str(), tmp.val().c_str(),
	 tmp.newval().c_str());*/

	char *buf = (char*) calloc(_msg_maxsize, sizeof(char));
	size_t msz = _msg_maxsize;

	/*send to and receive from*/

	// oht: revise here
	// int sentSize = sendTo(sock, sendbuf, sendcount);
	//_proxy->sendrecv(msg.c_str(), msg.size(), buf, msz);
	// 1. send and recv
	if ( _proxy->sendrecv(msg.c_str(), msg.size(), buf, msz) == false) {

		ZHTUtil zu;
		HostEntity he = zu.getHostEntityByKey(msg);
		char intStr[10];
		sprintf(intStr,"%d",he.port);
		string strPort=intStr;
		int proxyIndex = ConfHandler::getIndexOfProxy(strPort);


		printf("OHT commonOpInternal %d\n",proxyIndex);
		ConfHandler::NeighborVector.at(proxyIndex).setMark();
		//printf("OHT:: client %d error\n",ConfHandler::NeighborVector.at(proxyIndex).value());
		cout<<"OHT:: client sendrecv error "<< ConfHandler::NeighborVector.at(proxyIndex).value()<<endl;
	}

	printf("oht send recv :%s\n", buf);
	// 2. set up a server socket

	//	// 3. wait for a connection
	//	if (infd == -1) {
	//
	//		free(in_addr);
	//
	//		if ((errno == EAGAIN) || (errno == EWOULDBLOCK)) {
	//
	//			/* We have processed all incoming connections. */
	//			break;
	//		} else {
	//
	//			perror("accept");
	//			break;
	//		}
	//	}


	// 4. receive message from the


	/*...parse status and result*/
	string sstatus;

	string srecv(buf);

	if (srecv.empty()) {

		sstatus = Const::ZSC_REC_SRVEXP;
	} else {

		result = srecv.substr(3); //the left, if any, is lookup result or second-try zpack
		sstatus = srecv.substr(0, 3); //status returned, the first three chars, like 001, -98...
	}

	free(buf);
	return sstatus;
}

int ZHTClient::teardown() {

	sleep(3); // added by fk for OHT, just for test

	if (_proxy->teardown())
		return 0;
	else
		return -1;
}
