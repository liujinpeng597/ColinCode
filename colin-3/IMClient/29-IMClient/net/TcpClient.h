#pragma once
#include"INet.h"

class TcpClient :public INet {
public:
	//构造函数
	TcpClient(INetMediator* p);

	//析构函数
	~TcpClient();

	//初始化网络
	bool initNet();

	//关闭网络
	void unInitNet();

	//发送数据
	bool sendData(char* data, int len, long to);

	//接收数据
	void recvData();

	//接收数据线程
	static unsigned __stdcall recvThread(void* lpVoid);

protected:
	
};