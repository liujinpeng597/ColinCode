#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<Winsock2.h>
#pragma comment(lib, "Ws2_32.lib")
using namespace std;

int main() {
	//1.加载库
	WORD version = MAKEWORD(2, 2);
	WSADATA  data = {};
	int err = WSAStartup(version, &data);
	if (0 != err) {
		cout << "WSAStartup fail" << endl;
		return 1;
	}
	if (HIBYTE(data.wVersion) == 2 && 2 == LOBYTE(data.wVersion)) {
		cout << "WSAStartup success" << endl;
	}
	else {
		cout << "WSAStartup version error" << endl;
		WSACleanup();
		return 1;
	}

	//2.创建套接字
	SOCKET s1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == s1) {
		cout << "socket error:" << WSAGetLastError() << endl;
	}
	else {
		cout << "socket success" << endl;
	}

	//3.绑定ip和端口
	sockaddr_in addr = {};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(54321);
	addr.sin_addr.S_un.S_addr = ADDR_ANY;
	err = bind(s1, (sockaddr*)&addr, sizeof(addr));
	if (SOCKET_ERROR == err) {
		cout << "bind error:" << WSAGetLastError() << endl;
		closesocket(s1);
		WSACleanup();
		return 1;
	}
	else {
		cout << "bind success" << endl;
	}

	//4.监听
	err = listen(s1, 100/*等待连接的最大长度,一个时刻只能与一个客户端建立连接*/);
	if (SOCKET_ERROR == err) {
		cout << "listen error:" << WSAGetLastError() << endl;
		closesocket(s1);
		WSACleanup();
		return 1;
	}
	else {
		cout << "listen success" << endl;
	}

	//5.接收连接
	sockaddr_in addrClient = {};
	int size = sizeof(addrClient);
	SOCKET s2 = accept(s1, (sockaddr*)&addrClient, &size);
	if (INVALID_SOCKET == s2) {
		cout << "accept error:" << WSAGetLastError() << endl;
		closesocket(s1);
		WSACleanup();
		return 1;
	}
	else {
		//只有在服务端打印出客户端的ip地址，才说明服务端和客户端连接成功
		cout << "client ip:" << inet_ntoa(addrClient.sin_addr) << endl;
	}

	int nRecvNum = 0;
	int nSendNum = 0;
	char recvBuf[1024] = {};
	char sendBuf[1024] = {};
	while (true) {
		//6.接收数据
		nRecvNum = recv(s2,recvBuf,sizeof(recvBuf),0);
		if (nRecvNum > 0) {
			cout << "client say:" << recvBuf << endl;
		}else {
			cout << "recv fail" << endl;
		}
		

		//7.发送数据
		cin >> sendBuf;
		nSendNum = send(s2,sendBuf,sizeof(sendBuf),0);
		if (nSendNum == SOCKET_ERROR) {
			cout << "send error:" << WSAGetLastError() << endl;
		}
		else {
			cout << "send success" << endl;
		}
	}

	//8.关闭套接字，卸载库
	closesocket(s1);
	closesocket(s2);
	WSACleanup();
	return 0;
}