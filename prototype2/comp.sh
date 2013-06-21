mpicxx spock2.cpp ProxyStubFactory.cpp Protocol.cpp mq_proxy_stub.cpp mpi_proxy_stub.cpp ipc_plus.cpp -o spock2
echo "spock2 compiled"

mpicxx mpi_server.cpp -o mpi_server
echo "mpi_servercompiled"

#./spock2

mpiexec -np 4 ./mpi_server : ./spock2

