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
 * client_map_value.cpp
 *
 *  Created on: Nov 21, 2013
 *      Author: yangkklt
 */



#include  <stdlib.h>
#include  <string.h>

/* added by tianyang for OHT */

#include <sys/socket.h>
#include <errno.h>
#include "client_map_value.h"

using namespace std;

Client_map_value::Client_map_value (ZPack zpack, int stat ){

//	optional bytes opcode = 1; //001:lookup, 002:remove, 003:insert, 004:append, 005:compare_swap
//	optional bytes key = 2;
//	optional bytes val = 3;
//	optional bytes newval = 4; //used by compare_swap
//	optional bytes lease = 5; //used by state_changed_callback
//	optional bool valnull = 6;
//	optional bool newvalnull = 7; //used by compare_swap
//	optional int32 replicanum = 8;
//        optional bytes client_ip = 9; //used by OHT
//        optional int32 client_port = 10; //used by OHT
//        optional int32 seq_num = 11; //used by OHT



	z.set_opcode(zpack.opcode());
	z.set_key(zpack.key());
	z.set_val(zpack.val());
	z.set_newval(zpack.newval());
	z.set_lease(zpack.lease());
	z.set_valnull(zpack.newvalnull());
	z.set_replicanum(zpack.replicanum());
	z.set_client_ip(zpack.client_ip());
	z.set_client_port(zpack.client_port());
	z.set_seq_num(zpack.seq_num());

	status = stat;

	gettimeofday(&tv, NULL);
	retryNumber = 0;
}


int Client_map_value::getstatus()
{
	return status;
}

long Client_map_value::gettimevalue()
{
	return tv.tv_sec;
}


int Client_map_value::getRetryNumber(){
	return retryNumber;
}


void Client_map_value::increRetryNumber(){
	retryNumber ++;
}



