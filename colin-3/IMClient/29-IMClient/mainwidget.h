#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include"frienditem.h"
#include<map>
#include<QMenu>
using namespace std;

namespace Ui {
class MainWidget;
}

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

    void setMyInfo(int iconid,const QString &nick,const QString& feeling );
    void setFriendInfo(int friendid,int iconid,int status,const QString &nick,const QString& feeling );
    void setChatMsg(int,QString);

    void setFriendOffline(int friendid);
public slots:
    //当点击菜单按钮时 显示真正的菜单
    void slots_showMenu();

    void slots_dealMenu(QAction *);

signals:
    void signals_sendMsgAndIdToKernel(int,QString);
    void signals_addFriend(QString);
    void signals_userOffline();//无参数 通知kernel当前用户下线

public://窗口关闭时触发的事件 虚函数需要重写父类的虚函数(多态)
    virtual void closeEvent(QCloseEvent *event);


private:
    Ui::MainWidget *ui;

    int m_userId; //当前登录用户的id
    int m_iconId;//头像id
    QString m_nick; //昵称id
    QString m_feeling;//签名
    map<int,FriendItem*> m_friendLstMap; //储存朋友列表

    QMenu * m_pMenu;

public: //提供get/set接口

    // 直接在头文件定义了获取用户ID的方法（因逻辑简单）
    // 功能：返回当前登录用户的ID
    int getUserId(){return m_userId;}
    void setUserId(int userid){m_userId = userid;}

    QString getUserNick(){return m_nick;}
    void setUserNick(const QString& nick){m_nick = nick;}



};

#endif // MAINWIDGET_H
