#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include<Winsock2.h>
#include<process.h>
#include<iostream>
#include"def.h"

using namespace std;


class INetMediator;
class INet {
public:
	//构造函数
	INet():m_sock(INVALID_SOCKET), m_handle(nullptr), m_bRunning(true), m_pMediator(nullptr){}

	//析构函数
	virtual ~INet() {}

	//初始化网络
	virtual bool initNet() = 0;

	//关闭网络
	virtual void unInitNet() = 0;

	//发送数据
	virtual bool sendData(char* data,int len,long to) = 0;
	//接收数据
	virtual void recvData() = 0;

protected:
	//父类未定义的套接字
	SOCKET m_sock;

	//父类句柄,用于线程
	HANDLE m_handle;

	//父类线程标记位,默认true
	bool m_bRunning;

	INetMediator* m_pMediator;
};
