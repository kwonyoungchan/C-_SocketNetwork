#pragma warning(disable :4996)
#include "Common.h"
Socket::Socket()
{
	int socketChecker = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (socketChecker != 0) cout << "winsock ���� ����" << endl;
}

Socket::~Socket()
{
	WSACleanup();
}

void Socket::setSockAddrforServer(int _port)
{
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	socketAddress.sin_port = htons(_port);
}

void Socket::setSockAddrforClient(char* _ipAddress, int _port)
{
	socketAddress.sin_family = AF_INET;
	socketAddress.sin_addr.S_un.S_addr = inet_addr(_ipAddress);
	socketAddress.sin_port = htons(_port);
}

SOCKADDR_IN Socket::getSockAddress()
{
	return socketAddress;
}


SOCKADDR* Socket::getSOCKADDR()
{
	SOCKADDR_IN SocketAddressTemp = getSockAddress();
	sockAddr = (SOCKADDR*)&SocketAddressTemp;
	return sockAddr;
}


void Socket::showPacketData(const char* data)
{
	cout << "������ ���� : " << data << endl;
}

UDP::UDP()
{
	socketUDP = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
}

void UDP::binding()
{
	
	if (::bind(socketUDP, getSOCKADDR(), sizeof(getSockAddress())) == SOCKET_ERROR)
	{
		cout << "���ε� �ȵ�" << endl;
		return;
	}
}

void UDP::receivePacket(char* buffer)
{
	int recvLength = recvfrom(socketUDP, buffer, BUF_SIZE, 0, (SOCKADDR*)&senderAddressUDP, &senderAddrSize);
	if (recvLength == SOCKET_ERROR)
	{
		cout << "���� ����" << WSAGetLastError() << endl;
	}
	else
	{
		showPacketData(buffer);
	}
}

void UDP::sendPacket(const char* buffer)
{
	if (strlen(buffer) == 0)
	{
		  buffer = "none";
	}
	SOCKADDR_IN lValue = getSockAddress();
	sendto(socketUDP, buffer, BUF_SIZE, 0,(SOCKADDR*)&lValue, sizeof(getSockAddress()));
}



TCP::TCP()
{
	socketTCP = socket(BUF_SIZE, SOCK_STREAM, IPPROTO_TCP);
};

void TCP::binding()
{
	
	if (::bind(socketTCP, getSOCKADDR(), sizeof(getSockAddress())) == SOCKET_ERROR)
	{
		cout<<"���ε� �ȵ�"<<endl;
		return;
	}
}

void TCP::TCPListen()
{
	listen(socketTCP, SOMAXCONN);
}

void TCP::TCPAccept()
{
	socketClient = accept(socketTCP, (SOCKADDR*)&senderAddressTCP, &senderAddrSize);
}

void TCP::TCPConnect()
{
	connect(socketTCP, getSOCKADDR(), sizeof(getSockAddress()));
}

void TCP::receivePacket(char* buffer)
{
	int recvResult = recv(socketClient, buffer, BUF_SIZE, 0);
	if (recvResult == SOCKET_ERROR)
	{
		cout << "���� ����" << WSAGetLastError() << endl;
	}
	else
	{
		showPacketData(buffer);
	}
}

void TCP::sendPacket(const char* buffer)
{
	int sendResult = send(socketTCP, buffer, strlen(buffer), 0);
	if (sendResult == SOCKET_ERROR)
	{
		cout << "���۰� �����" << WSAGetLastError() << endl;
	}
	else
	{
		showPacketData(buffer);
	}
}
