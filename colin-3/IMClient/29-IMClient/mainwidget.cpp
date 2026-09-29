#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "frienditem.h"
#include<QCursor>
#include<QDebug>
#include<QInputDialog>
#include<QMessageBox>
#include<QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QLabel>
#include<QPushButton>
#include<QComboBox>
#include<QLineEdit>

#define MENU_ADD_FRI "添加好友"
#define MENU_SYS_SET "系统设置"

MainWidget::MainWidget(QWidget *parent): QWidget(parent), ui(new Ui::MainWidget),m_pMenu(new QMenu)
{
    ui->setupUi(this);

    connect(ui->pb_menu,SIGNAL(clicked()),this,SLOT(slots_showMenu()));
    connect(ui->pb_f1,SIGNAL(clicked()),this,SLOT(slots_friendMoments()));
    connect(ui->pb_f2,SIGNAL(clicked()),this,SLOT(slots_groupChat()));
    connect(ui->pb_f3,SIGNAL(clicked()),this,SLOT(slots_fileAssistant()));

    m_pMenu->addAction(MENU_ADD_FRI);
    m_pMenu->addAction(MENU_SYS_SET);

    //m_pMenu->triggered(QAction *action);
    connect(m_pMenu,SIGNAL(triggered(QAction*)),this,SLOT(slots_dealMenu(QAction*)));

    // 初始化"空间"Tab页的占位内容
    QVBoxLayout* spaceLayout = new QVBoxLayout(ui->tab_space);
    QLabel* spaceLabel = new QLabel("空间功能开发中,敬请期待!");
    spaceLabel->setAlignment(Qt::AlignCenter);
    spaceLabel->setFont(QFont("微软雅黑",14));
    spaceLayout->addWidget(spaceLabel);

    // 初始化"消息"Tab页的占位内容
    QVBoxLayout* msgLayout = new QVBoxLayout(ui->tab_msg);
    QLabel* msgLabel = new QLabel("消息中心开发中,敬请期待!");
    msgLabel->setAlignment(Qt::AlignCenter);
    msgLabel->setFont(QFont("微软雅黑",14));
    msgLayout->addWidget(msgLabel);
}

MainWidget::~MainWidget()
{
    qDebug()<<"调用~MainWidget:主窗口回收";
    delete ui;
    //回收菜单
    if(m_pMenu){
        delete m_pMenu;
        m_pMenu = nullptr;
    }


    //遍历删除所有的item
    for(pair<int,FriendItem*> pr:m_friendLstMap){
        delete pr.second;
    }

}

void MainWidget::setMyInfo(int iconid,const QString &nick,const QString& feeling ){
    ui->pb_img->setIcon(QIcon(QString(":/tx/%1.png").arg(iconid)));
    ui->l_nick->setText(nick);
    ui->le_feeling->setText(feeling);

    //存储

    m_iconId = iconid;//头像id
    m_nick = nick; //昵称id
    m_feeling = feeling;//签名
}

void MainWidget::setFriendInfo(int friendid,int iconid,int status,const QString &nick,const QString& feeling ){
    //判断好友信息是否已经存在
    if(m_friendLstMap.count(friendid)){
        //重新设置信息(更新朋友信息)
        m_friendLstMap[friendid]->setFriendInfo(iconid,status,nick,feeling);
    }else{
        //创建朋友
        FriendItem* pfriItem = new FriendItem;

        //设置朋友信息到窗口上
        pfriItem->setFriendInfo(iconid,status,nick,feeling);
        pfriItem->setFriendId(friendid);


        //创建列表项目,并添加朋友信息
        QListWidgetItem* pitem = new QListWidgetItem;
        ui->lw_friendlist->addItem(pitem);
        ui->lw_friendlist->setItemWidget(pitem,pfriItem);

        //调整QlistWidgetItem的高度 调整为和FriendItem一样高
        //针对的是每个列表项（行）的高度调整。
        QRect rect = pfriItem->geometry();
        pitem->setSizeHint(QSize(rect.width(),rect.height()));

        connect(pfriItem,SIGNAL(signals_sendMsgAndId(int,QString)),this,SIGNAL(signals_sendMsgAndIdToKernel(int,QString)));

        //储存朋友信息,,键值id 实值 朋友item'指针
        m_friendLstMap.insert(pair<int,FriendItem*>(friendid,pfriItem));
    }
}

void MainWidget::setChatMsg(int friendid,QString text){
    //m_friendLstMap 中找键值
    if(m_friendLstMap.count(friendid)){
        m_friendLstMap[friendid]->setFriendChatMsg(text);
    }
}

void MainWidget::slots_showMenu(){
    //显示菜单
    //m_pMenu->show();

    //获取光标位置,
    QPoint po = QCursor::pos();
    QSize size = m_pMenu->sizeHint();
    po.setY(po.y() - size.height());
    //qDebug()<<"po:"<<po;
    m_pMenu->exec(po); //popup显示

}

void MainWidget::slots_dealMenu(QAction *p){
    qDebug()<<"slots_dealMenu";
    if(p->text() == MENU_ADD_FRI){

        QString frinick = QInputDialog::getText(this,"添加好友","请输入好友昵称");

        frinick = frinick.trimmed();//去除两边空白符

        if(frinick.isEmpty()){
            QMessageBox::warning(this,"警告","好友昵称不能为空");
            return;
        }

        //判断是否已经是好友
        //遍历map
        for(pair<int,FriendItem*> pr : m_friendLstMap){
            if(pr.second->getNick() == frinick){
                QMessageBox::warning(this,"警告","已经是你好友了");
                return;
            }
        }


        //判断是否是自己
        if(frinick == m_nick){
            QMessageBox::warning(this,"警告","不能添加自己为好友");
            return;
        }

        //todo:发送给kerner 然后发送给服务端
        emit signals_addFriend(frinick);


    }else if(p->text() == MENU_SYS_SET){
        // 弹出系统设置对话框
        QDialog* dlg = new QDialog(this);
        dlg->setWindowTitle("系统设置");
        dlg->setFixedSize(350,300);
        dlg->setFont(QFont("微软雅黑",12));

        QVBoxLayout* mainLayout = new QVBoxLayout(dlg);

        // 昵称设置
        QHBoxLayout* nickLayout = new QHBoxLayout;
        nickLayout->addWidget(new QLabel("昵称:"));
        QLineEdit* nickEdit = new QLineEdit(m_nick);
        nickLayout->addWidget(nickEdit);
        mainLayout->addLayout(nickLayout);

        // 个性签名设置
        QHBoxLayout* feelingLayout = new QHBoxLayout;
        feelingLayout->addWidget(new QLabel("签名:"));
        QLineEdit* feelingEdit = new QLineEdit(m_feeling);
        feelingLayout->addWidget(feelingEdit);
        mainLayout->addLayout(feelingLayout);

        // 头像选择
        QHBoxLayout* iconLayout = new QHBoxLayout;
        iconLayout->addWidget(new QLabel("头像:"));
        QComboBox* iconCombo = new QComboBox;
        for(int i=0;i<=36;++i){
            iconCombo->addItem(QIcon(QString(":/tx/%1.png").arg(i)),QString::number(i));
        }
        iconCombo->setCurrentIndex(m_iconId);
        iconLayout->addWidget(iconCombo);
        mainLayout->addLayout(iconLayout);

        mainLayout->addStretch();

        // 确定/取消按钮
        QHBoxLayout* btnLayout = new QHBoxLayout;
        QPushButton* okBtn = new QPushButton("确定");
        QPushButton* cancelBtn = new QPushButton("取消");
        btnLayout->addStretch();
        btnLayout->addWidget(okBtn);
        btnLayout->addWidget(cancelBtn);
        mainLayout->addLayout(btnLayout);

        connect(okBtn,&QPushButton::clicked,dlg,&QDialog::accept);
        connect(cancelBtn,&QPushButton::clicked,dlg,&QDialog::reject);

        if(dlg->exec() == QDialog::Accepted){
            // 更新昵称
            QString newNick = nickEdit->text().trimmed();
            if(!newNick.isEmpty() && newNick != m_nick){
                m_nick = newNick;
                ui->l_nick->setText(m_nick);
            }
            // 更新签名
            QString newFeeling = feelingEdit->text().trimmed();
            if(newFeeling != m_feeling){
                m_feeling = newFeeling;
                ui->le_feeling->setText(m_feeling);
            }
            // 更新头像
            int newIcon = iconCombo->currentData().toInt();
            if(newIcon != m_iconId){
                m_iconId = newIcon;
                ui->pb_img->setIcon(QIcon(QString(":/tx/%1.png").arg(m_iconId)));
            }
            QMessageBox::information(this,"提示","设置已保存!");
        }
        delete dlg;
    }
}

// 好友动态按钮
void MainWidget::slots_friendMoments(){
    QMessageBox::information(this,"好友动态","好友动态功能开发中,敬请期待!");
}

// 群聊按钮
void MainWidget::slots_groupChat(){
    QMessageBox::information(this,"群聊","群聊功能开发中,敬请期待!");
}

// 文件助手按钮
void MainWidget::slots_fileAssistant(){
    QMessageBox::information(this,"文件助手","文件助手功能开发中,敬请期待!");
}

void MainWidget::setFriendOffline(int friendid){
    if(m_friendLstMap.count(friendid)){
        //设置朋友下线
        m_friendLstMap[friendid]->setFriendOff();
    }
}

void MainWidget::closeEvent(QCloseEvent *event){
    //qDebug()<<"closeEvent触发";

    //发射下线信号给kernel
    emit signals_userOffline();

}

