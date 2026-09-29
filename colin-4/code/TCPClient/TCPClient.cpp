#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<Winsock2.h>
#pragma comment(lib,"Ws2_32.lib")
using namespace std;

int main() {
	//加载库
	WORD version = MAKEWORD(2, 2);
	WSADATA data = {};
	int err = WSAStartup(version, &data);
	if (err != 0) {
		cout << "WSAStartup fail" << endl;
		return 1;
	}
	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2) {
		cout << "WSAStartup version success." << endl;
	}
	else {
		cout << "WSAStartup version error" << endl;
		WSACleanup();
		return 1;
	}
	//创建套接字
	SOCKET s1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == s1) {
		cout << "socket error: " << WSAGetLastError() << endl;
	}
	else {
		cout << "socket success." << endl;
	}

	//连接服务器(已知服务器ip和端口)
	sockaddr_in serverAddr = {};
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.S_un.S_addr = inet_addr("192.168.10.20");
	serverAddr.sin_port = htons(54321);
	err = connect(s1, (sockaddr*) & serverAddr,sizeof(serverAddr));
	if (err == SOCKET_ERROR) {
		cout << "connect error: " << WSAGetLastError() << endl;
		closesocket(s1);
		WSACleanup();
		return 1;
	}
	cout << "connect success." << endl;

	char sendBuf[1024] = { 0 };
	char recvBuf[1024] = { 0 };
	while (true) {
		//从窗口读取要发送的数据
		cout << "输入你要发送给服务端的消息: ";
		cin >> sendBuf;
		//发送数据
		int sendLen = send(s1, sendBuf, sizeof(sendBuf),0);
		if (sendLen == SOCKET_ERROR) {
			cout << "send error" << WSAGetLastError() << endl;
			break;
		}
		//接收数据
		int recvLen = recv(s1, recvBuf, sizeof(recvBuf), 0);
		if (recvLen == SOCKET_ERROR) {
			cout << "recv error" << WSAGetLastError() << endl;
			break;
		}
	}

	closesocket(s1);
	WSACleanup();

	return 0;
}
