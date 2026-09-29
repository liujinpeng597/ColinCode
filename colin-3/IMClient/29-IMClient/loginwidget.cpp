#include "loginwidget.h"
#include "ui_loginwidget.h"
#include<QMessageBox>
#include<QDebug>
#include<QSettings>
#include<QTimer>

//构造函数
LoginWidget::LoginWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWidget)
{
    ui->setupUi(this);

    // 登录按钮支持回车键触发(设为默认按钮)
    ui->pb_login->setDefault(true);

    // 加载记住的密码
    loadSettings();
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
        QMessageBox::warning(this,"警告","手机号或密码不能为空!");
        return;
    }

    //保存登录信息
    saveSettings();

    //给kernel发射信号
    emit signals_login(tel,pass);

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

// 记住密码复选框状态变化
void LoginWidget::on_cb_remember_pass_stateChanged(int state){
    // 勾选记住密码时,自动勾选自动登录(可选)
    if(state == Qt::Checked){
        ui->cb_auto_login->setEnabled(true);
    }else{
        // 取消记住密码时,同时取消自动登录
        ui->cb_auto_login->setChecked(false);
        ui->cb_auto_login->setEnabled(false);
    }
}

// 加载保存的登录信息
void LoginWidget::loadSettings(){
    QSettings settings("IMClient","LoginInfo");
    bool remember = settings.value("rememberPass",false).toBool();
    bool autoLogin = settings.value("autoLogin",false).toBool();

    ui->cb_remember_pass->setChecked(remember);
    ui->cb_auto_login->setEnabled(remember);
    ui->cb_auto_login->setChecked(autoLogin && remember);

    if(remember){
        QString tel = settings.value("tel","").toString();
        QString pass = settings.value("pass","").toString();
        ui->le_tel->setText(tel);
        ui->le_pass->setText(pass);

        // 如果勾选了自动登录,则自动触发登录
        if(autoLogin && !tel.isEmpty() && !pass.isEmpty()){
            // 延迟触发登录(等窗口完全初始化后)
            QTimer::singleShot(500,this,[this](){
                emit signals_login(ui->le_tel->text(),ui->le_pass->text());
            });
        }
    }
}

// 保存登录信息
void LoginWidget::saveSettings(){
    QSettings settings("IMClient","LoginInfo");
    bool remember = ui->cb_remember_pass->isChecked();

    settings.setValue("rememberPass",remember);
    if(remember){
        settings.setValue("tel",ui->le_tel->text());
        settings.setValue("pass",ui->le_pass->text());
        settings.setValue("autoLogin",ui->cb_auto_login->isChecked());
    }else{
        settings.remove("tel");
        settings.remove("pass");
        settings.setValue("autoLogin",false);
    }
}
