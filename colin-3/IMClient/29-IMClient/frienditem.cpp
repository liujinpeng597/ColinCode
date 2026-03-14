#include "frienditem.h"
#include "ui_frienditem.h"
#include "net/def.h"
#include<QBitmap>
#include<qDebug>
#include<QTime>

FriendItem::FriendItem(QWidget *parent): QWidget(parent), ui(new Ui::FriendItem),m_pChat(new ChatWidget)
{
    ui->setupUi(this);
    connect(m_pChat,SIGNAL(signals_sendMsg(QString)),this,SLOT(slots_sendMsgAndId(QString)));
}

FriendItem::~FriendItem()
{
    qDebug()<<"调用~FriendItem:朋友列表回收";
    delete ui;

    if(m_pChat){
        delete m_pChat;
        m_pChat = nullptr;
    }
}

// 设置朋友信息（头像、昵称、签名及在线状态展示）
void FriendItem::setFriendInfo(int iconid,int status,const QString &nick,const QString &feeling){

    // 设置头像（根据在线状态显示不同效果）
    if (status == FRIEND_STATUS_ONLINE) { // 在线状态（使用def.h中定义的宏）
        ui->pb_friimg->setIcon(QIcon(QString(":/tx/%1.png").arg(iconid)));
    } else if(status == FRIEND_STATUS_OFFLINE){ // 离线状态
        QBitmap bit(QString(":/tx/%1.png").arg(iconid));
        ui->pb_friimg->setIcon(bit);
    }

    // 设置昵称显示
    ui->l_frinick->setText(nick);

    // 设置签名显示（离线时添加[离线]前缀）
    QString showFeeling = feeling;
    if(status == FRIEND_STATUS_OFFLINE){//如果不在线
        showFeeling = "[离线]" + showFeeling;
    }
    ui->l_frifeeling->setText(showFeeling);

    // 存储朋友的信息（本地缓存，用于后续刷新或逻辑处理）
    m_iconiId = iconid;// 头像id
     m_status = status;// 朋友的登录状态
     m_nick = nick;// 朋友的昵称
    m_feeling = feeling;// 朋友的签名


}

//点击头像触发显示聊天框
void FriendItem::on_pb_friimg_clicked(){
    if(m_status == FRIEND_STATUS_ONLINE){
        m_pChat->setChatTitle("与 "+m_nick+" 的聊天框");
        m_pChat->show();
    }else if(m_status == FRIEND_STATUS_OFFLINE){
        m_pChat->setChatTitle("与 "+m_nick+" 的聊天框 [离线]");
        m_pChat->show();
    }
}

void FriendItem::slots_sendMsgAndId(QString text){
    // qDebug()<<"text:"<<text;

    emit signals_sendMsgAndId(m_friendId,text);
}

void FriendItem::setFriendChatMsg(QString text){
    QString s = m_nick + "[%1]: " + text;
    m_pChat->setChatText("<font color = 'gray'>"+s.arg(QTime::currentTime().toString("hh:mm:ss"))+"</font>");
}

void FriendItem::setFriendOff(){

        QBitmap bit(QString(":/tx/%1.png").arg(m_iconiId));
        ui->pb_friimg->setIcon(bit);

        m_status = FRIEND_STATUS_OFFLINE;
}
