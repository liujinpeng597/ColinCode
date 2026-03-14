#pragma once
#ifndef __DEF_H__
#define __DEF_H__

//1. 它是 “暗号本”：统一协议号（避免传错消息）
//2. 它是 “状态标签”：统一结果码（避免理解偏差）
//3. 它是 “快递盒子模板”：统一数据格式（避免拆错包裹）

//UDP协议端口号
#define UDP_PROT 12345
//Tcp协议端口号
#define TCP_PROT 54321
//等待连接最大数
#define WAIT_CONNECT_MAX (300) 

// 协议号基准值
#define DEF_PROT_BASE 1000
// 注册请求协议号
#define DEF_PROT_REGISTER_RQ (DEF_PROT_BASE+0)
#define DEF_PROT_REGISTER_RS (DEF_PROT_BASE+1)
//登录请求协议号
#define DEF_PROT_LOGIN_RQ (DEF_PROT_BASE+2)
#define DEF_PROT_LOGIN_RS (DEF_PROT_BASE+3)
//朋友信息
#define DEF_PROT_FRIEND_INFO (DEF_PROT_BASE+4)
//聊天请求
#define DEF_PROT_CHAT_INFO_RQ (DEF_PROT_BASE+5)
//聊天请求的回复
#define DEF_PROT_CHAT_INFO_RS (DEF_PROT_BASE+6)
//注册结果状态码
#define REGISTER_RESULT_SUCC 0// 注册成功
#define REGISTER_RESULT_FAIL_NAME 1// 注册失败
#define REGISTER_RESULT_FAIL_TEL 2// 注册失败
//登录结果状态码
#define LOGIN_RESULT_SUCC 0
#define LOGIN_RESULT_NOEXIST 1
#define LOGIN_RESULT_PASSERR 2
//朋友状态
#define FRIEND_STATUS_ONLINE 1
#define FRIEND_STATUS_OFFLINE 0
//发送聊天内容的大小
#define MSG_LEN (1024*4)
//1成功 0失败
#define CHAT_RESULT_SUCC 1
#define CHAT_RESULT_FAIL 0
//请求添加好友
#define DEF_PROT_ADD_FRIEND_RQ (DEF_PROT_BASE+7)
//添加好友回复
#define DEF_PROT_ADD_FRIEND_RS (DEF_PROT_BASE+8)
//用户下线
#define DEF_PROT_ADD_FRIEND_OFFLINE (DEF_PROT_BASE+9)
//添加好友回复的结果
#define ADDFRI_RESULT_ACCEPT 0
#define ADDFRI_RESULT_REJECT 1
#define ADDFRI_RESULT_OFFLINE 2
#define ADDFRI_RESULT_NOEXIST 3

#define isOnline 1// 在线
#define notOnline 0// 离线

// 协议类型标识（用于区分不同协议）
using prot_type = unsigned int;

// 注册请求协议：客户端向服务端发送的注册信息
struct PROT_REGISTER_RQ{
    prot_type prottype;//协议类型
    char nick[30];     //昵称
    char tel[15];      //电话号码
    char pass[15];     //密码

    // 构造函数：初始化成员变量
    //因为nick,te;,pass都是数组 所以用大括号初始化
    PROT_REGISTER_RQ():prottype(DEF_PROT_REGISTER_RQ),nick{0},tel{0},pass{0}{}
};

// 注册回复协议：服务端向客户端返回的注册结果
struct PROT_REGISTER_RS{
    prot_type prottype; //协议类型
    int result; //回复注册的结果
    PROT_REGISTER_RS():prottype(DEF_PROT_REGISTER_RS),result{REGISTER_RESULT_SUCC}{}
};

// 登录请求协议：客户端向服务端发送的登录信息
struct PROT_LOGIN_RQ{
    prot_type prottype;//协议类型
    char tel[15];      //电话号码
    char pass[15];     //密码
    PROT_LOGIN_RQ():prottype(DEF_PROT_LOGIN_RQ),tel{0},pass{0}{}
};

// 登录回复协议：服务端向客户端返回的登录结果
struct PROT_LOGIN_RS{
    prot_type prottype;//协议类型
    int userid;      //登陆成功时,会返回当前登录用户的id
    int result;     //登录结果
    PROT_LOGIN_RS():prottype(DEF_PROT_LOGIN_RS),userid(0),result(LOGIN_RESULT_SUCC){}
};

// 用户信息协议：用于传递用户（自己或好友）的详细信息
struct PROT_FRIEND_INFO{
    prot_type prottype;//协议类型
    int friendid; //朋友的id
    int iconid; //头像id
    int status; //状态 0,离线 1,在线
    char nick[30];
    char feeling[100];//个性签名
    int online_status;

    PROT_FRIEND_INFO():
        prottype(DEF_PROT_FRIEND_INFO),
        friendid(0),
        iconid(0),
        status(FRIEND_STATUS_ONLINE),
        nick{0},
        feeling{0},
        online_status(notOnline)
    {}
};

// 聊天请求协议：客户端向服务端发送的聊天消息
struct PROT_CHAT_INFO_RQ{
    prot_type prottype; //协议类型
    int myid; //我的id
    int friendid; //朋友 接收方的id
    char msg[MSG_LEN];//聊天内容
    PROT_CHAT_INFO_RQ()
    :
        prottype(DEF_PROT_CHAT_INFO_RQ)
        ,myid(0)
        ,friendid(0)
        ,msg{0}
    {}
};

// 聊天回复协议：服务端向客户端转发的聊天消息
struct PROT_CHAT_INFO_RS{
    prot_type prottype; //协议类型
    int myid; //我的id
    int friendid; //朋友 接收方的id
    int result; //1成功 0失败
    PROT_CHAT_INFO_RS()
        :
        prottype(DEF_PROT_CHAT_INFO_RS)
        ,myid(0)
        ,friendid(0)
        ,result(CHAT_RESULT_SUCC)
    {}
};

// 添加好友请求协议：客户端向服务端发送的添加好友申请
struct PROT_ADD_FRIEND_RQ{

    prot_type prottype; //协议类型
    int myid;
    char mynick[30];
    char frinick[30];
    PROT_ADD_FRIEND_RQ():prottype(DEF_PROT_ADD_FRIEND_RQ)
        ,myid(0)
        ,mynick{0}
        ,frinick{0}
    {}
};

// 添加好友回复协议：服务端向客户端返回的添加好友结果
struct PROT_ADD_FRIEND_RS{
    prot_type prottype;//协议类型
    int result;
    int destid;
    char destnick[30];
    int myid;
    char mynick[30];
    PROT_ADD_FRIEND_RS():prottype(DEF_PROT_ADD_FRIEND_RS)
        ,result(ADDFRI_RESULT_ACCEPT)
        ,destid(0)
        ,destnick{0}
        ,myid(0)
        ,mynick{0}
    {}
};

// 用户下线协议：客户端或服务端发送的用户下线通知
struct PROT_FRIEND_OFFLINE{
    prot_type prottype;
    int offuserid;
    char offusernick[30];
    PROT_FRIEND_OFFLINE():
        prottype(DEF_PROT_ADD_FRIEND_OFFLINE),
        offuserid(0)
        ,offusernick{0}
    {}
};

#endif // DEF_H
