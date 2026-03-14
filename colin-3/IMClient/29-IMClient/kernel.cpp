#include "kernel.h"
#include<QDebug>
#include"net/def.h"
#include"./mediator/TcpClientMediator.h"
#include<QMessageBox>
#include<QTextCodec>

//向服务端发送信号宏
#define SENDCLIENTDATA(PROT_TYPE,PROT_NAME)\
{\
        int len = sizeof(PROT_TYPE);\
        char* pbuf = new char[len]();\
        memcpy_s(pbuf,len,&PROT_NAME,len);\
        emit signals_sendClientData(pbuf,len,0);\
}\

//创建登录框初始化构建信号与槽
Kernel::Kernel(QObject *parent): QObject{parent},m_pLogin(new LoginWidget),m_pMainWidget(new MainWidget)/*创建登录框*/{

    //--------绑定所有的协议和处理函数-----------------------------------

    m_pArrFunc[DEF_PROT_REGISTER_RS         - DEF_PROT_BASE] = & Kernel::deal_protRegisterRs;
    m_pArrFunc[DEF_PROT_LOGIN_RS            - DEF_PROT_BASE] = & Kernel::deal_protLoginRs;
    m_pArrFunc[DEF_PROT_FRIEND_INFO         - DEF_PROT_BASE] = & Kernel::deal_protFriendInfo;
    m_pArrFunc[DEF_PROT_CHAT_INFO_RS        - DEF_PROT_BASE] = & Kernel::deal_protChatInfoRs;
    m_pArrFunc[DEF_PROT_CHAT_INFO_RQ        - DEF_PROT_BASE] = & Kernel::deal_protChatInfoRq;
    m_pArrFunc[DEF_PROT_ADD_FRIEND_RS       - DEF_PROT_BASE] = & Kernel::deal_protAddFriendRs;
    m_pArrFunc[DEF_PROT_ADD_FRIEND_RQ       - DEF_PROT_BASE] = & Kernel::deal_protAddFriendRq;
    m_pArrFunc[DEF_PROT_ADD_FRIEND_OFFLINE  - DEF_PROT_BASE] = & Kernel::deal_protFriendOffline;

    //--------------------------------------------------------
    m_pLogin->show(); //显示登录框

    //绑定 登录框注册信息
    /*此对象   --发送->  此信号  --给-->                        此对象 ---中-->  此槽函数 */
    connect(m_pLogin,       SIGNAL(signals_register(QString,QString,QString)),this,         SLOT(slots_sendRegisterInfo(QString,QString,QString)));
    connect(m_pLogin,       SIGNAL(signals_login(QString,QString)),this,                    SLOT(slots_sendLoginInfo(QString,QString)));
    connect(this,           SIGNAL(signals_sendClientData(char*,int,unsigned long)),this,   SLOT(slots_recvServerData(char*,int,unsigned long)));
    connect(m_pMainWidget,  SIGNAL(signals_sendMsgAndIdToKernel(int,QString)),this,         SLOT(slots_sendServerMsg(int,QString)));
    connect(m_pMainWidget,  SIGNAL(signals_addFriend(QString)),this,                        SLOT(slots_addFriend(QString)));
    connect(m_pMainWidget,  SIGNAL(signals_userOffline()),this,                             SLOT(slots_sendUserOffline()));
    connect(m_pLogin,       SIGNAL(signals_closeWindow()),this,                             SLOT(slots_delete()));

    //打开网络
    m_pMediator = new TcpClientMediator;
    if(!m_pMediator->openNet()){
        QMessageBox::about(m_pLogin,"提示","打开网络失败");
        exit(1);
    }
    //连接处理服务端数据的信号和槽函数
    connect(m_pMediator,SIGNAL(signals_recvServerData(char* ,int ,unsigned long )),
            this,SLOT(slots_recvServerData(char* ,int ,unsigned long )));


}

//向服务端发送注册信息
void Kernel::slots_sendRegisterInfo(QString nick,QString tel,QString pass){
    qDebug()<<"nick:"<<nick<<",tel:"<<tel<<",pass:"<<pass;

    // 创建注册请求协议对象（来自def.h的结构体）
    PROT_REGISTER_RQ registerRq;

    //nick.toStdString().c_str();//QString -> string -> const char*

    //定义注册请求的协议 并填充数据

    // 关键步骤：将Qt的QString（输入框数据）转成C风格字符串，填充到协议结构体中
    // strcpy_s：安全的字符串拷贝函数（参数：目标数组、数组长度、源字符串）
    //strcpy_s(registerRq.nick,30,nick.toStdString().c_str());
    utf8ToGb2312(nick,registerRq.nick,30); //包括转码和拷贝
    strcpy_s(registerRq.tel,15,tel.toStdString().c_str());
    strcpy_s(registerRq.pass,15,pass.toStdString().c_str());

    // 把结构体发送给服务端
    m_pMediator->sendData((char*)&registerRq,sizeof(registerRq),1);

}

//向服务端发送登录信息
void Kernel::slots_sendLoginInfo(QString tel,QString pass){

    qDebug()<<"tel:"<<tel<<",pass:"<<pass;
    //创建登录请求对象
    PROT_LOGIN_RQ loginRq;
    //将数据拷贝到登录请求对象
    strcpy_s(loginRq.tel,15,tel.toStdString().c_str());
    strcpy_s(loginRq.pass,15,pass.toStdString().c_str());
    //qDebug调试
    qDebug()<<"服务器收到登录的请求:"<<loginRq.tel<<","<<loginRq.pass;

    m_pMediator->sendData((char*)&loginRq,sizeof(loginRq),2);
}

//进入slots_recvServerData判断是何种信号//客户端 接收 服务端信号
//统一接收服务端的数据
void Kernel::slots_recvServerData(char* pbuf,int len,unsigned long from){

    qDebug()<<__func__;
    // 1.取出结构体中的协议类型
    prot_type type = *(prot_type*)pbuf;
    prot_type pt = *(prot_type*)pbuf;
    qDebug()<<"pt:"<<pt;
    if(pt>=DEF_PROT_BASE)
        (this->*m_pArrFunc[pt-DEF_PROT_BASE])(pbuf,len,from);
    else
        QMessageBox::critical(nullptr,"错误","解析的协议类型非法");
    //回收缓冲区
    if(pbuf)
    {
        delete []pbuf;
    }
}

//id乱码 因为未储存
void Kernel::slots_sendServerMsg(int friendid,QString text){
    qDebug()<<"Kernel::slots_sendServerMsg:"<<friendid<<","<<text;

    //定义聊天请求
    PROT_CHAT_INFO_RQ chatinfoRq;
    chatinfoRq.myid = m_pMainWidget->getUserId();
    chatinfoRq.friendid = friendid;
    strcpy_s(chatinfoRq.msg,MSG_LEN,text.toStdString().c_str());

    // 把聊天请求发给服务端
    m_pMediator->sendData((char*)&chatinfoRq,sizeof(chatinfoRq),4);
}

void Kernel::slots_addFriend(QString frinick){
    qDebug()<<"slots_addFriend:"<<frinick;

    PROT_ADD_FRIEND_RQ addFriRq;
    addFriRq.myid = m_pMainWidget->getUserId();
    strcpy_s(addFriRq.mynick,30,m_pMainWidget->getUserNick().toStdString().c_str());
    utf8ToGb2312(frinick,addFriRq.frinick,30);
    //strcpy_s(addFriRq.frinick,30,frinick.toStdString().c_str());
    //把添加好友请求发给服务端
    m_pMediator->sendData((char*)&addFriRq,sizeof(addFriRq),4);
}

void Kernel::slots_timerAddFriend()
{
    qDebug()<<"slots_timerAddFriend";

    //小王，添加刘宇为好友
    PROT_ADD_FRIEND_RQ addFriRq;
    addFriRq.myid=20;
    strcpy_s(addFriRq.mynick,30,"小王");
    strcpy_s(addFriRq.frinick,30,"张三");

    SENDCLIENTDATA(PROT_ADD_FRIEND_RQ,addFriRq);

}

void Kernel::slots_timerFriendOnline()
{
    PROT_FRIEND_INFO myfri2;
    myfri2.friendid = 11;
    myfri2.iconid = 21;
    myfri2.status = FRIEND_STATUS_ONLINE;
    strcpy_s(myfri2.nick,30,"刘金朋1");
    strcpy_s(myfri2.feeling,100,"111");
    //发送至slots_recvServerData
    SENDCLIENTDATA(PROT_FRIEND_INFO,myfri2);
}

void Kernel::slots_timerFriendOffline()
{
    PROT_FRIEND_OFFLINE friOff;
    friOff.offuserid=12;
    SENDCLIENTDATA(PROT_FRIEND_OFFLINE,friOff);
}

void Kernel::slots_sendUserOffline()
{
    //定义下线的协议结构
    PROT_FRIEND_OFFLINE userOff;
    userOff.offuserid=m_pMainWidget->getUserId();

    // 给服务端发送下线请求
    m_pMediator->sendData((char*)&userOff,sizeof(userOff),2);



#define SAFE_DELETE(POINT)\
    if(POINT){\
            delete POINT;\
            POINT=nullptr;\
    }
    //回收各种资源
    //回收登录框
    SAFE_DELETE(m_pLogin);
    SAFE_DELETE(m_pMainWidget);


}

void Kernel::slots_delete(){
    //回收各种资源
    //回收登录框
    SAFE_DELETE(m_pLogin);
    SAFE_DELETE(m_pMainWidget);
}
//--------------所有的deal函数-------------------------------------------------------

void Kernel::deal_protRegisterRs(char*pbuf,int len,unsigned long){
    PROT_REGISTER_RS* pRegisterRs = (PROT_REGISTER_RS*)pbuf;
    if(pRegisterRs->result == REGISTER_RESULT_SUCC){//注册成功
        QMessageBox::information(nullptr,"提示","注册成功");
    }else if(pRegisterRs->result == REGISTER_RESULT_FAIL_NAME){//注册失败
        QMessageBox::information(nullptr,"提示","注册失败，昵称已被注册");
    }else if(pRegisterRs->result == REGISTER_RESULT_FAIL_TEL){//注册失败
        QMessageBox::information(nullptr,"提示","注册失败，手机号已被注册");
    }
}
void Kernel::deal_protLoginRs(char*pbuf,int len,unsigned long)
{
    PROT_LOGIN_RS* pLoginRs = (PROT_LOGIN_RS*)pbuf;
    if(pLoginRs->result == LOGIN_RESULT_SUCC){//登录成功

        //存储用户id
        m_pMainWidget->setUserId(pLoginRs->userid);

        //显示主聊天窗口
        m_pMainWidget->show();

        //隐藏登录窗口
        m_pLogin->hide();

        qDebug()<<"存储用户id:"<<m_pMainWidget->getUserId();

        //          //--------------------------------------
        //          connect(&m_timerAddFri,SIGNAL( timeout() ),this,SLOT( slots_timerAddFriend() ) );
        //         //让定时器，只是生效一次即可
        //          m_timerAddFri.setSingleShot(true);
        //          m_timerAddFri.start(5000); //登陆成功五秒后 会有别人添加你为好友 （会发送添加好友的请求）


        //          connect(&m_timerFriOnline,SIGNAL( timeout() ),this,SLOT( slots_timerFriOnline() ) );
        //          m_timerFriOnline.setSingleShot(true);
        //          m_timerFriOnline.start(8000);


        //          connect(&m_timerFriOffline,SIGNAL( timeout() ),this,SLOT( slots_timerFriOffline() ) );
        //          m_timerFriOffline.setSingleShot(true);
        //          m_timerFriOffline.start(10000);


        //          QMessageBox::information(nullptr,"提示","登陆成功");

    }else if(pLoginRs->result == LOGIN_RESULT_NOEXIST){//用户名不存在
        QMessageBox::information(nullptr,"提示","用户名不存在");
    }else if(pLoginRs->result == LOGIN_RESULT_PASSERR){//密码错误
        QMessageBox::information(nullptr,"提示","密码错误");
    }
}
void Kernel::deal_protFriendInfo(char*pbuf,int len,unsigned long)
{
    PROT_FRIEND_INFO* pmyinfo = (PROT_FRIEND_INFO*)pbuf;
    QString nick=gb2312ToUtf8(pmyinfo->nick);
    QString feeling=gb2312ToUtf8(pmyinfo->feeling);
    //判断是自己还是朋友
    //这段代码的核心是 「比较两个数据是否相等」—— 用 MainWidget 窗口中存储的「当前登录用户 ID」，
    //和服务器返回的「好友 / 自己的 ID」做对比，从而判断这条数据是属于「当前登录用户自己」还是「好友」。
    if(m_pMainWidget->getUserId() == pmyinfo->friendid){//自己
        m_pMainWidget->setMyInfo(pmyinfo->iconid,nick,feeling);
    }else{//朋友
        m_pMainWidget->setFriendInfo(
            pmyinfo->friendid,
            pmyinfo->iconid,
            pmyinfo->status,
            nick,
            feeling
            );
    }
}
void Kernel::deal_protChatInfoRs(char*pbuf,int len,unsigned long)
{
    PROT_CHAT_INFO_RS* pChatinfoRs = (PROT_CHAT_INFO_RS*)pbuf;
    qDebug()<<"收到了本次请求的回复 朋友:"<<pChatinfoRs->myid<<",我: "<<pChatinfoRs->friendid<<",result"<<pChatinfoRs->result;
    if(pChatinfoRs->result == CHAT_RESULT_SUCC){//已送达
        m_pMainWidget->setChatMsg(pChatinfoRs->myid,"已送达");
    }else if(pChatinfoRs->result == CHAT_RESULT_FAIL){//已下线
        m_pMainWidget->setChatMsg(pChatinfoRs->myid,"已下线");
    }
}
void Kernel::deal_protChatInfoRq(char*pbuf,int len,unsigned long)
{
    //收到了朋友的聊天请求
    PROT_CHAT_INFO_RQ* pChatinfoRq = (PROT_CHAT_INFO_RQ*)pbuf;
    //pChatinfoRq->msg;
    m_pMainWidget->setChatMsg(pChatinfoRq->myid,QString("<p><font font_weight:bold size='4'>%1</font></p >").arg(pChatinfoRq->msg));
}
void Kernel::deal_protAddFriendRs(char*pbuf,int len,unsigned long)
{
    qDebug()<<"收到添加好友的回复";
    PROT_ADD_FRIEND_RS* pAddFriRs = (PROT_ADD_FRIEND_RS*)pbuf;

    if(pAddFriRs->result == ADDFRI_RESULT_ACCEPT){
        //qDebug()<<"同意";
        QMessageBox::information(nullptr,"提示",QString("%1同意了你的好友申请").arg(pAddFriRs->mynick));
    }else if(pAddFriRs->result == ADDFRI_RESULT_OFFLINE){
        //qDebug()<<"用户不在线";
        QMessageBox::information(nullptr,"提示",QString("用户%1不在线").arg(gb2312ToUtf8(pAddFriRs->mynick)));
    }else if(pAddFriRs->result == ADDFRI_RESULT_NOEXIST){
        //qDebug()<<"用户不存在";
        QMessageBox::information(nullptr,"提示",QString("用户%1不存在").arg(gb2312ToUtf8(pAddFriRs->mynick)));
    }else if(pAddFriRs->result == ADDFRI_RESULT_REJECT){
        //qDebug()<<"用户不同意";
        QMessageBox::information(nullptr,"提示",QString("%1拒绝了你的好友申请").arg(pAddFriRs->mynick));
    }
}
void Kernel::deal_protAddFriendRq(char*pbuf,int len,unsigned long)
{
    PROT_ADD_FRIEND_RQ*pFriRq=(PROT_ADD_FRIEND_RQ*)pbuf;
    auto but=QMessageBox::information(nullptr,"添加好友请求",QString("%1请求添加好友，是否同意").arg(pFriRq->mynick),
                                        QMessageBox::Yes|QMessageBox::No);

    PROT_ADD_FRIEND_RS addFriRs;
    addFriRs.destid=pFriRq->myid;
    strcpy_s(addFriRs.destnick,30,pFriRq->mynick);
    addFriRs.myid=m_pMainWidget->getUserId();
    strcpy_s(addFriRs.mynick,30,m_pMainWidget->getUserNick().toStdString().c_str());

    if(but==QMessageBox::Yes)
    {
        addFriRs.result=ADDFRI_RESULT_ACCEPT;
    }else if(but==QMessageBox::No)
    {
        addFriRs.result=ADDFRI_RESULT_REJECT;
    }
    //把添加结果返回给服务端
    m_pMediator->sendData((char*)&addFriRs,sizeof(addFriRs),3);
}
void Kernel::deal_protFriendOffline(char*pbuf,int len,unsigned long)
{
    PROT_FRIEND_OFFLINE*pfriOff=(PROT_FRIEND_OFFLINE*)pbuf;
    qDebug()<<QString("收到朋友(%1)下线的通知").arg(pfriOff->offuserid);

    m_pMainWidget->setFriendOffline(pfriOff->offuserid);

}

// gb2312转utf8
QString Kernel::gb2312ToUtf8(char *stc)
{
    QTextCodec* dc = QTextCodec::codecForName("gb2312");
    return dc->toUnicode(stc);
}

// utf8转gb2312
void Kernel::utf8ToGb2312(QString src, char *dst, int len)
{
    QTextCodec* dc = QTextCodec::codecForName("gb2312");
    QByteArray ba = dc->fromUnicode(src);
    strcpy_s(dst, len, ba.data());
}

