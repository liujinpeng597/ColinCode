#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<Winsock2.h>

using namespace std;

#pragma comment(lib,"Ws2_32.lib")

int main() {
	WORD version = MAKEWORD(2, 2);
	WSADATA data{};
	int err = WSAStartup(version, &data);
	if (err != 0) {
		cout << "WSAStartup fail" << endl;
		return 1;
	}

	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2) {
		cout << "WSAStartup success" << endl;
	}
	else {
		cout << "WSAStartup fail" << endl;
		WSACleanup();
		return 1;
	}


	SOCKET s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (s == INVALID_SOCKET) {
		cout << "socket error:" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	else {
		cout << "socket success" << endl;
	}


	int recvNum = 0;
	int sendNum = 0;
	char recvBuf[1024] = "";
	char sendBuf[1024] = "";
	sockaddr_in addrFrom = {};


	addrFrom.sin_family = AF_INET;
	addrFrom.sin_port = htons(12345);
	addrFrom.sin_addr.S_un.S_addr = inet_addr("192.168.1.69");

	//发直接广播
	//addrFrom.sin_addr.S_un.S_addr = inet_addr("192.168.1.255");
	//发有限广播
	addrFrom.sin_addr.S_un.S_addr = inet_addr("255.255.255.255");
	//申请广播权限
	BOOL val = true;
	setsockopt(s, SOL_SOCKET, SO_BROADCAST, (char*)&val, sizeof(val));


	int size = sizeof(addrFrom);
	while (true) {
		//3.发送数据
		cout << "请输入你要发送给服务端的数据:" << endl;
		cin >> sendBuf;
		sendNum = sendto(s,sendBuf,sizeof(sendBuf),0, (sockaddr*)&addrFrom/*IPV4转网络字节序的32位整数*/,size);
		if (SOCKET_ERROR == sendNum) {
			cout << "send error:" << WSAGetLastError() << endl;
			break;
		}

		//4.接收数据
		/*recvNum = recvfrom(s,recvBuf,sizeof(recvBuf),0,(sockaddr*)&addrFrom,&size);
		if (recvNum > 0) {
			cout << "ip:" << inet_ntoa(addrFrom.sin_addr) << "recv data:" << recvBuf << endl;
		}
		else {
			cout << "recv error:" << WSAGetLastError() << endl;
		}*/
	}
	closesocket(s);
	WSACleanup();
	return 0;
}