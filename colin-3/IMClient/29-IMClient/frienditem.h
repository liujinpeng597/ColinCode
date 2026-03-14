#ifndef FRIENDITEM_H
#define FRIENDITEM_H

#include <QWidget>
#include "chatwidget.h"

namespace Ui {
class FriendItem;
}

class FriendItem : public QWidget
{
    Q_OBJECT

public:
    explicit FriendItem(QWidget *parent = nullptr);
    ~FriendItem();

    //添加设置朋友信息
    void setFriendInfo(int iconid,int status,const QString &nick,const QString &feeling);

    void setFriendId(int friendId){m_friendId = friendId;}
    int getFriendId(){return m_friendId;}

    void setFriendChatMsg(QString);

    QString getNick(){return m_nick;}
    void setNick(const QString & nick){m_nick = nick;}

    //设置朋友下线(将头像变灰,将m_status变灰)
    void setFriendOff();

private slots:
    void on_pb_friimg_clicked();

    //接收来自chatwidget的聊天内容
    void slots_sendMsgAndId(QString);

signals:
    //向mainwidget发送聊天内容和朋友id
    void signals_sendMsgAndId(int,QString);

private:
    Ui::FriendItem *ui;
    int m_friendId;//储存朋友的id信息
    int m_iconiId;//头像id
    int m_status;//朋友的登录状态
    QString m_nick;//朋友的昵称
    QString m_feeling;//朋友的签名

    ChatWidget* m_pChat;
};

#endif // FRIENDITEM_H
