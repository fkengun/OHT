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
 * ZHTProxy.cpp
 *
 *  Created on: Oct 5, 2013
 *      Author: fkengun
 *      Contributor: Tony
 */

#include <getopt.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
using namespace std;

#ifdef PF_INET
#include "EpollProxy.h"
#include "ip_proxy.h"
#elif MPI_INET
#include "mpi_server.h"
#endif

#include "ConfHandler.h"
using namespace iit::datasys::zht::dm;

void printUsage(char *argv_0);

int main(int argc, char **argv) {

	extern char *optarg;

	int printHelp = 0;
	string protocol;
	string port_from_input;
	string port_from_conf;
	string zhtConf;
	string neighborConf;
	string serverConf; // added by fk, server list conf file for OHT
    string replicaNumServer; // added by fk for OHT, replica level for proxy
	string novohtDbFile;

	int c;
	while ((c = getopt(argc, argv, "z:n:s:r:p:f:h")) != -1) {
		switch (c) {
		case 'z':
			zhtConf = string(optarg);
			break;
		case 'n':
			neighborConf = string(optarg);
			break;
		/* added by fk, option for proxy in OHT */
		case 's':
			serverConf = string(optarg);
			break;
        case 'r':
            replicaNumServer = string(optarg);
            break;
		/* end add */
		case 'p':
			port_from_input = string(optarg);
			break;
		case 'f':
			novohtDbFile = string(optarg);
			break;
		case 'h':
			printHelp = 1;
			break;
		default:
			fprintf(stderr, "Illegal argument \"%c\"\n", c);
			printUsage(argv[0]);
			exit(1);
		}
	}

	int helpPrinted = 0;
	if (printHelp) {
		printUsage(argv[0]);
		helpPrinted = 1;
	}

	try {
		if (!zhtConf.empty() && !neighborConf.empty()) {

			ConfHandler::NOVOHT_FILE = Const::trim(novohtDbFile);

			/*init config*/
			ConfHandler::initProxyConf(zhtConf, neighborConf, serverConf); // modified by fk, add server list conf file for OHT 
            ConfHandler::ReplicaNumServer = atoi(replicaNumServer.c_str()); // added by fk for OHT, replica level for proxy

			/*get protocol and port*/
			protocol = ConfHandler::getProtocolFromConf();

			/*get port, port defined interactively overrides that in configure*/
			port_from_conf = ConfHandler::getPortFromConf();

			if (port_from_conf.empty()) {

				cout << "zht.conf: port not configured" << endl;
			}

			string port =
					!port_from_input.empty() ? port_from_input : port_from_conf;

            /* added by fk for OHT, split server vector into two parts */
            ConfHandler::splitServerVector(port);
            // test vector update
//            ConfEntry ce("localhost,50002");
//            ConfHandler::updateServerVector(ce);
            /* end add */

			if (port.empty()) {

				cout << "zht proxy: port not defined by user" << endl;
				exit(1);
			}

			/*make sure protocol defined*/
			if (protocol.empty()) {

				cout << "zht.conf: protocol not configured" << endl;
				exit(1);
			}

			char buf[100];
			memset(buf, 0, sizeof(buf));

			/*prompt zht proxy startup message for different protocols*/
			if (protocol == Const::PROTO_VAL_MPI) {

				sprintf(buf, "ZHT proxy- <protocol:%s> started...",
						protocol.c_str());
			} else {

				sprintf(buf,
						"ZHT proxy- <localhost:%s> <protocol:%s> started...",
						port.c_str(), protocol.c_str());
			}

			cout << buf << endl;

#ifdef PF_INET

			EpollProxy ep(port.c_str(), new IPProxy());
			ep.serve();
#elif MPI_INET

			MPIServer mpis(argc, argv);
			mpis.serve();
#endif

		} else {

			if (!helpPrinted)
				printUsage(argv[0]);
		}
	} catch (exception& e) {

		fprintf(stderr, "%s, exception caught:\n\t%s", "ZHTProxy::main",
				e.what());
	}

}

void printUsage(char *argv_0) {

	fprintf(stdout, "Usage:\n%s %s\n", argv_0,
			"-z zht.conf -n neighbor.conf [-p port] [-f novoht_db_file] [-h(help)]");
}
