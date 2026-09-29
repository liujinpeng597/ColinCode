#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<iostream>
#include<Winsock2.h>

using namespace std;

#pragma comment(lib,"Ws2_32.lib")

int main() {
	//1.加载库
		//参数1,版本号
	WORD version = MAKEWORD(2, 2);
	//参数2,WSADATA结构体
	WSADATA data{};
	int err = WSAStartup(version, &data);

	//判断返回值
	if (err != 0) {
		cout << "WSAStartup fail" << endl;
		return 1;
	}

	//判断版本号
	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2) {
		cout << "WSAStartup success" << endl;
	}
	else {
		cout << "WSAStartup fail" << endl;
		//卸载库
		WSACleanup();
		return 1;
	}

	//2.创建套接字
	SOCKET s = socket(AF_INET/*IPV4*/, SOCK_DGRAM/*UDP*/, IPPROTO_UDP/*使用UDP*/);
	
	//判断是否创建成功
	if (s == INVALID_SOCKET){
		cout << "socket error:" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	else {
		cout << "socket success" << endl;
	}

	//3.绑定ip和端口(告诉操作系统,当前进程要使用哪个ip和端口号)
	//创建结构体 给结构体内容赋值
	sockaddr_in addr = {};
	//地址类型IPV4
	addr.sin_family = AF_INET;//地址家族,AF_INET代表使用IPV4地址类型
	//要用的端口号
	addr.sin_port = htons(12345); //网络字节序:大端存储,htons转换成网络字节序
	//要用的ip地址
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //绑定所有网卡

	//绑定 套接字s 绑定结构体 结构体中有套接字s需要的东西 算出结构体长度
	err = bind(s,(sockaddr*) & addr, sizeof(addr));

	//判断是否绑定成功
	if (SOCKET_ERROR == err) {
		//bind 失败通常是因为端口被占用、权限不足等
		cout << "bind error:" << WSAGetLastError() << endl;
		//关闭套接字,卸载库
		closesocket(s);
		WSACleanup();
		return 1;
	}
	else {
		cout << "bind success" << endl;
	}

	//查询发送缓冲区和接收缓冲区的大小是64K
	int recvSize = 0;
	int sendSize = 0;
	int size1 = sizeof(recvSize);
	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (char*)&recvSize, &size1);
	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (char*)&sendSize, &size1);
	cout << "recvSize:" << recvSize << " sendSize:" << sendSize << endl;
	//阻塞和非阻塞
	//阻塞：等待的事情没有发生的过程中，就一直在这等待。特点：1.等待的事情发生的时候第一时间知道  2.阻塞过程不占用CPU
	//非阻塞：等待的事情没有发生的过程中，可以做其他的事情。特点：1.等待的事情发生的时候不知道  2.非阻塞过程占用CPU
	//socket默认是阻塞模式，所以发送和接收数据都是阻塞的
	//设置套接字为非阻塞模式
	/*u_long iMode = 1;
	ioctlsocket(s, FIONBIO, &iMode);*/

	//发送数据的阻塞和非阻塞
	//发送数据的阻塞：发送缓冲区不足够大的时候，等缓冲区空间足够大再往里拷贝数据
	//发送数据的非阻塞：发送缓冲区不足够大的时候，有多大空间拷贝多少数据，剩余数据自己处理

	
	int recvNum = 0;
	int sendNum = 0;
	char recvBuf[1024] = "";
	char sendBuf[1024] = "";
	sockaddr_in addrFrom = {};
	int size = sizeof(addrFrom);
	while (true) {
		//4.接收数据
		recvNum = recvfrom(s, 
			recvBuf, //准备的空间,用来存放要接收的数据 
			sizeof(recvBuf), //准备的空间大小
			0, //初始化标志位,0代表使用默认方式
			(sockaddr*)&addrFrom,//接收到的数据是从哪来的,对端的地址信息 
			&size);
		if (recvNum > 0) {
			//接收到数据,打印收到的数据
			//ip地址有两种类型,十进制四等分字符串,ulong类型
			//inet_addr(): 从字符串转换到ulong
			//inet_ntoa():从ulong到字符串
			cout << "ip:" << inet_ntoa(addrFrom.sin_addr) << "recv data:" << recvBuf << endl;
		}
		else {
			cout << "recv error:" << WSAGetLastError() << endl;
		}
		//从界面上输入要发送的字符串
		/*cin >> sendBuf;*/

		////5.发送数据
		//sendNum = sendto(s, 
		//	sendBuf/*要发送的数据*/,
		//	sizeof(sendBuf),
		//	0/*初始化标志位,0代表使用默认方式*/,
		//	(sockaddr*)&addrFrom/*数据要发给谁,对端的地址信息*/, 
		//	size);

		//if (SOCKET_ERROR == sendNum) {
		//	cout << "send error:" << WSAGetLastError() << endl;
		//	break;
		//}
	}
	closesocket(s);
	WSACleanup();
	return 0;
}