#include "loginwidget.h"
#include "ui_loginwidget.h"
#include<QMessageBox>
#include<QDebug>

//构造函数
LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);
}

//析构函数
LoginWidget::~LoginWidget()
{
    qDebug()<<"调用~LoginWidget:登录窗口回收";
    delete ui;
}

// 点击注册按钮时触发的槽函数（校验注册信息并发送注册请求）
void LoginWidget::on_pb_register_clicked(){
    // 获取注册信息（昵称、手机号、密码、确认密码）
    QString nick = ui->le_nick->text();
    QString tel = ui->le_register_tel->text();
    QString pass = ui->le_register_pass->text();
    QString passAgain = ui->le_pass_again->text();

    // 校验信息完整性
    if(nick.isEmpty()||tel.isEmpty()||pass.isEmpty()||passAgain.isEmpty()){
        QMessageBox::warning(this,"警告","注册信息不可为空！");
        return ;
    }

    // 校验手机号格式（11位数字）
    if(tel.size()!=11){
        QMessageBox::warning(this,"警告","手机号太长或太短,请输入11位手机号！");
        return ;
    }
    for(int i=0;i<11;++i){
        if(tel[i]<"0"||tel[i]>"9"){
            QMessageBox::warning(this,"警告","手机号只能是数字！");
            return ;
        }
    }

    // 校验两次输入的密码是否一致
    if(pass!=passAgain){
        QMessageBox::warning(this,"警告","两次输入密码不一致,请重新输入!");
        return;
    }

    // 发送注册信号给内核，由内核处理后续逻辑
    emit signals_register(nick,tel,pass);
}

//点击(注册)清空
void LoginWidget::on_pb_register_clear_clicked()
{
    ui->le_nick->clear();  //清空组件内容
    ui->le_register_tel->clear();
    ui->le_register_pass->clear();
    ui->le_pass_again->clear();
}

//点击(登录)登录
void LoginWidget::on_pb_login_clicked()
{
    QString tel = ui->le_tel->text();
    QString pass = ui->le_pass->text();
    if(tel.isEmpty()||pass.isEmpty()){
        QMessageBox::warning(this,"警告","手机号只能是数字!");
        return;
    }

    //todo:服务端
    emit signals_login(tel,pass);//给kernel发射信号

}

//点击(登录)清空
void LoginWidget::on_pb_clear_clicked()
{
    ui->le_pass->clear();
    ui->le_tel->clear();
}

void LoginWidget::closeEvent(QCloseEvent *event){
    //通知kernel回收资源
    emit signals_closeWindow();
}
