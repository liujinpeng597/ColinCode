#pragma once
#include"INetMediator.h"

class TcpClientMediator : public INetMediator {
    Q_OBJECT
public:
	TcpClientMediator();
	~TcpClientMediator();

	// 打开网络
	bool openNet();

	// 关闭网络
	void closeNet();

	// 发送数据
	bool sendData(char* data, int len, long to);

	// 把接收到的数据传给核心处理类
	// data:要传的数据
	// len:数据的长度
	// from:数据从哪里来
	void transmitData(char* data, int len, long from);

signals:
    // 把接收到的数据发给kernel
    void signals_recvServerData(char* data,int len,unsigned long from);
};
