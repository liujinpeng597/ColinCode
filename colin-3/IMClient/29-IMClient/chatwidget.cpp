#include "chatwidget.h"
#include "ui_chatwidget.h"
#include<QMessageBox>
#include<QDebug>
#include<QTime>

ChatWidget::ChatWidget(QWidget *parent): QWidget(parent), ui(new Ui::ChatWidget)
{
    ui->setupUi(this);

    connect(ui->pb_send,SIGNAL(clicked()),this,SLOT(slots_sendMsg()));
    connect(ui->pb_clear,SIGNAL(clicked()),this,SLOT(slots_clearMsg()));
}

ChatWidget::~ChatWidget()
{
    qDebug()<<"调用~ChatWidget:聊天窗口回收";
    delete ui;
}

//设置窗口标题
void ChatWidget::setChatTitle(const QString & title){
    setWindowTitle(title);
}

// 聊天窗口 - 发送按钮点击触发的槽函数
// 核心功能：处理用户消息发送的完整流程（校验->格式化->显示->清空->转发）
void ChatWidget::slots_sendMsg(){
    // 1. 空消息校验：避免发送空内容
    // 先获取纯文本内容（仅用于判空，忽略格式）
    QString text = ui->te_msg->toPlainText();
    if(text.isEmpty()){
        QMessageBox::warning(this,"警告","发送内容不能为空");
        return;
    }

    // 2. 获取带格式的消息内容：保留用户输入的富文本格式（如字体、颜色等）
    text = ui->te_msg->toHtml();

    // 3. 聊天记录格式化：拼接发送者、发送时间、消息内容（富文本格式）
    // 格式说明：灰色显示"我[时分秒]："，黑色粗体（4号字）显示消息内容
    QString str = QString("<font color = 'gray'>我[%1]:</font>") + "<p><font font_weight:bold size='4' color = 'black'>" + text + "</font>";
    // 填充当前时间（格式：时:分:秒）
    str =  str.arg(QTime::currentTime().toString("hh:mm:ss"));

    // 4. 本地聊天记录显示：将格式化后的消息追加到聊天记录框
    ui->tb_chatrecord->append(str);
    // 清空输入框：准备下次输入
    ui->te_msg->clear();

    // 5. 消息转发给内核：通过信号将带格式的消息传递给内核
    // 备注：内核负责后续的网络发送逻辑（实际项目需补充服务端通信代码）
    emit signals_sendMsg(text);
}

void ChatWidget::slots_clearMsg(){
    ui->te_msg->clear(); //清空输入的聊天内容
}

void ChatWidget::setChatText(QString s){
    ui->tb_chatrecord->append(s);
}

