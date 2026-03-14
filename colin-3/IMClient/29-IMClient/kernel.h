#ifndef KERNEL_H
#define KERNEL_H

#include <QObject>
#include"loginwidget.h"
#include"mainwidget.h"
#include<QTimer>
#include"./mediator/INetMediator.h"

#define DEAL_FUNC_LEN 10

class Kernel : public QObject
{
    Q_OBJECT
public:
    explicit Kernel(QObject *parent = nullptr);

    //类成员函数指针的别名
    using P_DEAL_FUNC = void (Kernel::*)(char* pbuf,int len,unsigned long);
    P_DEAL_FUNC m_pArrFunc[DEAL_FUNC_LEN];

public://处理服务端返回的数据
    void deal_protRegisterRs(char* pbuf,int len,unsigned long);
    void deal_protLoginRs(char* pbuf,int len,unsigned long);
    void deal_protFriendInfo(char* pbuf,int len,unsigned long);
    void deal_protChatInfoRs(char* pbuf,int len,unsigned long);
    void deal_protChatInfoRq(char* pbuf,int len,unsigned long);
    void deal_protAddFriendRs(char* pbuf,int len,unsigned long);
    void deal_protAddFriendRq(char* pbuf,int len,unsigned long);
    void deal_protFriendOffline(char* pbuf,int len,unsigned long);

    //gb2312转utf-8
    QString gb2312ToUtf8(char* src);
    //utf-8转gb2312
    void utf8ToGb2312(QString src,char* dst,int len);


public slots:
    //先接受登录框的信号,发送给服务端,注册信息
    void slots_sendRegisterInfo(QString,QString,QString);
    //先接受登录框的信号,发送给服务端,登录信息
    void slots_sendLoginInfo(QString,QString);

    //处理服务端发过来的数据
    void slots_recvServerData(char*,int,unsigned long);

    //接收来自mainwidget的聊天内容并发送给服务端
    void slots_sendServerMsg(int,QString);

    //接收添加朋友的昵称 并添加好友请求发送给服务端
    void slots_addFriend(QString);

    //定时器模拟别人添加我为好友
    void slots_timerAddFriend();

    void slots_timerFriendOnline();

    void slots_timerFriendOffline();

    //用户下线
    void slots_sendUserOffline();
    //回收资源
    void slots_delete();
signals:

    void signals_sendClientData(char*,int,unsigned long);


public:
    LoginWidget* m_pLogin;
    MainWidget* m_pMainWidget;//主聊天窗口
    INetMediator* m_pMediator;

    QTimer m_timerAddFri;//定时让别人添加我为好友
    QTimer m_timerFriOnline; //模拟好友定时上线
    QTimer m_timerFriOffline;//模拟还有下线

};

#endif // KERNEL_H
