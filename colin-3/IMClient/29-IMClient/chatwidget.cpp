#include "chatwidget.h"
#include "ui_chatwidget.h"
#include<QMessageBox>
#include<QDebug>
#include<QTime>
#include<QFileDialog>
#include<QFontDialog>
#include<QColorDialog>
#include<QMenu>
#include<QGridLayout>
#include<QTextCharFormat>

ChatWidget::ChatWidget(QWidget *parent): QWidget(parent), ui(new Ui::ChatWidget)
{
    ui->setupUi(this);

    connect(ui->pb_send,SIGNAL(clicked()),this,SLOT(slots_sendMsg()));
    connect(ui->pb_clear,SIGNAL(clicked()),this,SLOT(slots_clearMsg()));
    connect(ui->pb_file,SIGNAL(clicked()),this,SLOT(slots_fileTransfer()));
    connect(ui->pb_emo,SIGNAL(clicked()),this,SLOT(slots_emojiPicker()));
    connect(ui->pb_videochat,SIGNAL(clicked()),this,SLOT(slots_videoChat()));
    connect(ui->pb_bold,SIGNAL(clicked()),this,SLOT(slots_boldText()));
    connect(ui->pb_font,SIGNAL(clicked()),this,SLOT(slots_fontDialog()));
    connect(ui->pb_color,SIGNAL(clicked()),this,SLOT(slots_colorDialog()));
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

// 文件传输按钮:选择文件并显示路径
void ChatWidget::slots_fileTransfer(){
    QString filePath = QFileDialog::getOpenFileName(this,"选择要发送的文件");
    if(filePath.isEmpty()){
        return;
    }
    // 在聊天记录中显示文件传输提示
    QString str = QString("<font color='blue'>[文件传输] %1</font>").arg(filePath);
    ui->tb_chatrecord->append(str);
    // TODO: 实际文件传输需要服务端支持
    QMessageBox::information(this,"提示","文件路径已记录,实际文件传输功能需要服务端支持");
}

// 表情按钮:弹出简易表情选择菜单
void ChatWidget::slots_emojiPicker(){
    QMenu emoMenu(this);

    // 常用表情列表
    QStringList emojis = {
        "😀","😂","🤣","😊","😍","🤩","😘","😜",
        "😎","🤔","😴","😭","😤","🥰","😱","🤗",
        "👍","👎","👏","🙌","💪","🤝","❤️","💔",
        "🔥","⭐","🎉","🎊","🌹","💯","✅","❌"
    };

    // 每行8个表情
    QWidget* emoWidget = new QWidget;
    QGridLayout* layout = new QGridLayout(emoWidget);
    layout->setSpacing(2);

    for(int i = 0; i < emojis.size(); ++i){
        QPushButton* btn = new QPushButton(emojis[i]);
        btn->setFixedSize(40,40);
        btn->setFont(QFont("Segoe UI Emoji",14));
        btn->setStyleSheet("border:none; background:transparent;");
        connect(btn,&QPushButton::clicked,[this,emojis,i,&emoMenu](){
            // 在当前光标位置插入表情
            QTextCursor cursor = ui->te_msg->textCursor();
            cursor.insertText(emojis[i]);
            emoMenu.close();
        });
        layout->addWidget(btn,i/8,i%8);
    }

    // 包装成 QWidgetAction
    QWidgetAction* action = new QWidgetAction(&emoMenu);
    action->setDefaultWidget(emoWidget);
    emoMenu.addAction(action);

    // 在表情按钮下方弹出
    emoMenu.exec(ui->pb_emo->mapToGlobal(QPoint(0,ui->pb_emo->height())));
}

// 视频聊天按钮:提示开发中
void ChatWidget::slots_videoChat(){
    QMessageBox::information(this,"提示","视频聊天功能开发中,敬请期待!");
}

// 加粗按钮:切换选中文本的粗体状态
void ChatWidget::slots_boldText(){
    QTextCharFormat fmt;
    QTextCursor cursor = ui->te_msg->textCursor();

    // 如果当前已加粗则取消,否则加粗
    if(cursor.charFormat().fontWeight() == QFont::Bold){
        fmt.setFontWeight(QFont::Normal);
    }else{
        fmt.setFontWeight(QFont::Bold);
    }
    cursor.mergeCharFormat(fmt);
    ui->te_msg->mergeCurrentCharFormat(fmt);
}

// 字体按钮:弹出字体选择对话框
void ChatWidget::slots_fontDialog(){
    bool ok;
    QFont font = QFontDialog::getFont(&ok,ui->te_msg->currentFont(),this,"选择字体");
    if(ok){
        QTextCharFormat fmt;
        fmt.setFont(font);
        QTextCursor cursor = ui->te_msg->textCursor();
        cursor.mergeCharFormat(fmt);
        ui->te_msg->mergeCurrentCharFormat(fmt);
    }
}

// 颜色按钮:弹出颜色选择对话框
void ChatWidget::slots_colorDialog(){
    QColor color = QColorDialog::getColor(ui->te_msg->textColor(),this,"选择文字颜色");
    if(color.isValid()){
        QTextCharFormat fmt;
        fmt.setForeground(color);
        QTextCursor cursor = ui->te_msg->textCursor();
        cursor.mergeCharFormat(fmt);
        ui->te_msg->mergeCurrentCharFormat(fmt);
    }
}

