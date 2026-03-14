#pragma once
#include"INet.h"

class Udp : public INet {
public:
	Udp(INetMediator* m_pMediator);
	~Udp();

	//初始化网络
	bool initNet();

	//关闭网络
	void unInitNet();

	//发送数据
	bool sendData(char* data, int len, long to);

	//接收数据
	void recvData();

	static unsigned __stdcall recvThread(void* lpVoid);
};