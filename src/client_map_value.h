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
 *  client_map_value.h
 *
 *  Created on: Nov 21, 2013
 *      Author: Tianyang
 *      Contributor: Tony, KWang, DZhao, fk
 */

#ifndef CLIENT_MAP_VALUE
#define CLIENT_MAP_VALUE


#include <stddef.h>
#include <string>
#include <sys/types.h>
#include "zpack.pb.h"
#include <sys/time.h>


using namespace std;



class Client_map_value {

public:
	Client_map_value(ZPack zpack, int stat);
	//~Client_map_value();
	int getstatus();
	long gettimevalue();
	int getRetryNumber();
	void increRetryNumber();

private:
	ZPack z;
	int status;
	struct timeval tv;
	int retryNumber;

};


#endif
