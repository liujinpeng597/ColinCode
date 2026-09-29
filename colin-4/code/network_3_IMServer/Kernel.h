#pragma once
#include<iostream>
#include"mediator/INetMediator.h"
#include"net/def.h"
#include"MySQL/CMySql.h"
#include<map>
using namespace std;
class Kernel
{
public:
	static Kernel* pKernel;
	Kernel();
	~Kernel();

	//打开服务端
	bool startServer();

	//关闭服务端
	void closeServer();

	//初始化函数指针数组
	void setProtocolArry();

	//根据自己的id获取自己的信息和好友的信息
	void getUserInfoAndFriendInfo(int id);

	//根据id查询用户信息
	void getInfoById(int id, PROT_FRIEND_INFO* info);

	//分发处理所有接收到的数据
	void dealData(char* data,int len,long from);

	//处理注册请求
	void dealRegisterRq(char* data, int len, long from);

	//处理登录请求
	void dealLoginRq(char* data, int len, long from);

	//处理下线请求
	void dealOfflineRq(char* data, int len, long from);

	//处理聊天请求
	void dealChatRq(char* data, int len, long from);

	//处理聊天回复
	void dealAddFriendRs(char* data, int len, long from);

	//处理下聊天请求
	void dealAddFriendRq(char* data, int len, long from);

	//定义函数指针
	typedef void (Kernel::* PFUN)(char* data, int len, long from);
private:
	INetMediator* m_pMediator;
	//定义数据库对象
	CMySql m_sql;
	//定义含函数指针数组
	PFUN m_arrFun[DEF_PROT_COUNT];
	//保存用户id和客户端的socket(登录成功的时候保存,下线的时候从map中删除)
	map<int, SOCKET>m_mapIdToSocket;
};

