/*
 * bigdata_transfer.h
 *
 *  Created on: Jun 25, 2013
 *      Author: Xiaobing Zhou
 */

#ifndef BIGDATA_TRANSFER_H_
#define BIGDATA_TRANSFER_H_

#include "meta.pb.h"

#include <sys/types.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

class Blob {
public:
	Blob(const string& blob);
	Blob(const uint64_t& uuid, const size_t& seqNum, const size_t& total,
			const string& value);

	virtual ~Blob();

public:
	uint64_t uuid() const;
	void uuid(const uint64_t& uuid);

	size_t seqNum() const;
	void seqNum(const size_t& seqNum);

	size_t total() const;
	void total(const size_t& total);

	string value() const;
	void value(const string& value);

	size_t size() const;
	void size(const size_t& size);

	string toString() const;
	Blob& assign(const string& blob);

	static uint getHeaderLen();

public:
	static uint getUuidLen();
	static uint getCountLen();
	static uint getSizeLen();

	string getUuidFormat() const;
	string getCountFormat() const;
	string getSizeFormat() const;

	string format(const string& format, const size_t& value) const;

private:
	uint64_t _uuid; //62 chars,
	size_t _seqNum; //7 chars, like 1000000, max msg is 1000000*1K = 1G
	size_t _total; //7 chars, like 1000000, max msg is 1000000*1K = 1G
	size_t _size; //4 chars, like 1024
	string _value; //
};

/*BdSendBase: big data send base class*/
class BdSendBase {
public:
	typedef vector<Blob> VEC;
	typedef vector<Blob>::const_iterator VI;
	typedef vector<Blob>::reverse_iterator VRI;

public:
	BdSendBase(const char *msg);
	BdSendBase(const string& msg);
	virtual ~BdSendBase();

	int bsend(int sock) const;
	int bsend(const char* host, int port, int sock) const;

protected:
	virtual int recAck(int sock, const uint64_t& ackid,
			const bool& terminate) const = 0;

private:
	void split();

private:
	VEC _blobs;
	string _msg;

private:
	uint BLOB_SIZE;
};

/*BdSendToClient: big data send to client*/
class BdSendToClient: public BdSendBase {
public:
	BdSendToClient(const char *msg);
	BdSendToClient(const string& msg);
	~BdSendToClient();

protected:
	int recAck(int sock, const uint64_t& ackid, const bool& terminate) const;
};

/*BdSendToServer: big data send to server*/
class BdSendToServer: public BdSendBase {
public:
	BdSendToServer(const char *msg);
	BdSendToServer(const string& msg);
	~BdSendToServer();

protected:
	int recAck(int sock, const uint64_t& ackid, const bool& terminate) const;
};

/*BdRecvBase: big data receive base class*/
class BdRecvBase {

public:
	class classcomp {
	public:
		bool operator()(const Blob& lhs, const Blob& rhs) const;
	};

public:
	typedef set<Blob, classcomp> SET;
	typedef set<Blob, classcomp>::iterator SI;
	typedef set<Blob, classcomp>::reverse_iterator SRI;
	typedef map<uint64_t, SET> MAP;
	typedef map<uint64_t, SET>::iterator MI;
	typedef map<uint64_t, SET>::reverse_iterator MRI;

public:
	BdRecvBase();
	virtual ~BdRecvBase();

	string getBdStr(int sock, const char * const buf, size_t count,
			bool& ready);

protected:
	virtual int sendAck(int sock, const uint64_t& ackid) const = 0;

private:
	string combineBlobs(const uint64_t& uuid);
	void deleteBlobs(const uint64_t& uuid);

private:
	MAP _BdMap;
};

/*BdRecvFromClient: big data receive from client*/
class BdRecvFromClient: public BdRecvBase {
protected:
	int sendAck(int sock, const uint64_t& ackid) const;
};

/*BdRecvFromServer: big data receive from server*/
class BdRecvFromServer: public BdRecvBase {
protected:
	int sendAck(int sock, const uint64_t& ackid) const;
};

template<class ID>
class AckQueue {
public:
	typedef queue<Package> QU;
	typedef map<ID, QU> MAP;
	typedef typename map<ID, QU>::iterator MI;
	typedef typename map<ID, QU>::const_iterator MCI;
	typedef typename map<ID, QU>::reverse_iterator MRI;

public:
	AckQueue();
	~AckQueue();

	bool empty(const ID& id) const;
	size_t size(const ID& id) const;
	const Package& front(const ID& id) const;
	const Package& back(const ID& id) const;

	void push(const ID& id, Package ack);
	void pop(const ID& id);

	void rmQueue(const ID& id);

private:
	MAP _QMap;

};
#endif /* BIGDATA_TRANSFER_H_ */