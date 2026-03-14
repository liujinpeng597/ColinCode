#pragma once
#include<QObject>
class INet;
class INetMediator : public QObject{
    Q_OBJECT
public:
    INetMediator();
    virtual ~INetMediator();

	// 打开网络
	virtual bool openNet() = 0;

	// 关闭网络
	virtual void closeNet() = 0;

	// 发送数据
	virtual bool sendData(char* data, int len, long to) = 0;

	// 把接收到的数据传给核心处理类
	// data:要传的数据
	// len:数据的长度
	// from:数据从哪里来
	virtual void transmitData(char* data, int len, long from) = 0;
protected:
	INet* m_pNet;
};
