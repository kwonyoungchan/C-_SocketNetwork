#pragma once
#include"Common.h"

#define PORT 7777
#define BUF_SIZE 1024

class Socket
{
private:
	WSADATA wsaData ;
	SOCKADDR_IN socketAddress;
	SOCKADDR* sockAddr;
public:
	Socket();
	~Socket();

	void setSockAddrforServer(int _port);
	void setSockAddrforClient(char* _ipAddress, int _port);
	SOCKADDR_IN getSockAddress();
	SOCKADDR* getSOCKADDR();
	virtual void binding() = 0;

	virtual void receivePacket(char* buffer) = 0;
	virtual void sendPacket(const char* buffer) = 0;
	void showPacketData(const char* data);
};

class UDP : public Socket
{
private:
	SOCKET socketUDP =NULL;
	SOCKADDR_IN senderAddressUDP ;
	int senderAddrSize = sizeof(senderAddressUDP);
public:
	UDP();

	virtual void binding() override;
	virtual void receivePacket(char* buffer) override;
	virtual void sendPacket(const char* buffer) override;

};

class TCP :public Socket
{
private:
	SOCKET socketTCP =NULL;
	SOCKET socketClient;
	SOCKADDR_IN senderAddressTCP;
	int senderAddrSize = sizeof(senderAddressTCP);
public:
	TCP();
	virtual void binding() override;
	void TCPListen();
	void TCPAccept();
	void TCPConnect();
	virtual void receivePacket(char* buffer) override;
	virtual void sendPacket(const char* buffer) override;
};