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
 * ConfHandler.h
 *
 *  Created on: Aug 7, 2012
 *      Author: Xiaobingo
 *      Contributor: Tony, KWang, DZhao
 */

#ifndef CONFIGHANDLER_H_
#define CONFIGHANDLER_H_

#include "ConfEntry.h"

#include <map>
#include <vector>
#include <string>
#include <sys/types.h>

#include "Const-impl.h"

using namespace std;

namespace iit {
namespace datasys {
namespace zht {
namespace dm {

class ConfHandler {
public:
	typedef map<string, ConfEntry> MAP;
	typedef pair<string, ConfEntry> PAIR;
	typedef MAP::iterator MIT;
	typedef MAP::reverse_iterator MRIT;

	typedef vector<ConfEntry> VEC;

	typedef ConfEntry MYTABLE[3][3];
	typedef VEC::iterator VIT;
	typedef VEC::reverse_iterator VRIT;


public:
	ConfHandler();
	virtual ~ConfHandler();

	static void initConf(string zhtConf, string neighborConf);
	static void initProxyConf(string zhtConf, string neighborConf, string serverconf); // added by fk, for OHT
	static string getPortFromConf();
	static string getProtocolFromConf();
	static string getNeighborReplicaNumFromConf(); // added by fk for OHT
    static void splitServerVector(string myPort); // added by fk for OHT, split all servers into primaryservervector and replicaservervector
    static int getIndexOfProxy(string myPort); // added by fk for OHT, find index of self in neighbors
    static void updateServerVector(ConfEntry faultyServer, VEC &serverVector); // added by fk for OHT, mark faulty server in replica server vector
	static string get_zhtconf_parameter(const string &paraname);

private:
	static void setNeighborSeeds(const string& neighborCfg);
	static void setServerSeeds(const string& serverCfg); // added by fk, for OHT
	static void setZHTParameters(const string& zhtConfig);
	static void setNeighborVector(VEC &neighborVector);
	static void setServerVector(VEC &replicaServerVector); // added by fk, for OHT
	static void setNodeParameters(const string& nodeConfig);

	static void pickNodeParameters();
	static void pickZHTParameters();

	static void setParametersInternal(string configFile, MAP& configMap);

public:
	static VEC NeighborVector;
	static MAP NeighborSeeds;
	static MYTABLE mytable;
	/* added by fk, variables for server list info */
    static VEC myServerVector;
    static VEC othersServerVector;
	static MAP ServerSeeds;
    static int ReplicaNumServer;
	/* end add */
	static MAP ZHTParameters;
	static MAP NodeParameters;

public:

public:
	static string CONF_ZHT;
	static string CONF_NODE;
	static string CONF_NEIGHBOR;
    static string CONF_SERVER;      /* added by fk, for OHT */
	static string NOVOHT_FILE;

public:
	static string NC_FILECLIENT_PATH;
	static string NC_FILESERVER_PATH;
	static uint NC_FILESERVER_PORT;

	static uint ZC_MAX_ZHT;
	static uint ZC_NUM_REPLICAS;
	static uint ZC_REPLICATION_TYPE;
	static uint NC_ZHT_CAPACITY;
	static string ZC_HTDATA_PATH;
	static uint ZC_MIGSLP_TIME;

private:
	static bool BEEN_INIT;
};

} /* namespace dm */
} /* namespace zht */
} /* namespace datasys */
} /* namespace iit */
#endif /* CONFIGHANDLER_H_ */
