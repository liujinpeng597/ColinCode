#pragma once
#include"INet.h"
#include<map>
#include<list>

class TcpServer :public INet {
public:
	TcpServer(INetMediator* p);
	~TcpServer();

	//初始化网络
	bool initNet();

	//关闭网络
	void unInitNet();

	//发送数据
	bool sendData(char* data, int len, long to);

	//接收数据
	void recvData();

	// 接收客户端连接的线程函数
	static unsigned __stdcall acceptThread(void* lpVoid);

	// 接收数据的线程函数
	static unsigned __stdcall recvThread(void* lpVoid);

protected:
	map<unsigned int, SOCKET> m_mapThreadIdToSocket;

	list<HANDLE> m_listHandle;
};