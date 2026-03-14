#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class LoginWidget;
}
QT_END_NAMESPACE

class LoginWidget : public QWidget
{
    Q_OBJECT

public:
    LoginWidget(QWidget *parent = nullptr);
    ~LoginWidget();

private slots: //槽函数
    //点击(注册)注册
    void on_pb_register_clicked();

    //点击(注册)清空
    void on_pb_register_clear_clicked();

    //点击(登录)登录
    void on_pb_login_clicked();

    //点击(登录)清空
    void on_pb_clear_clicked();

signals:
    //定义发送给kernel的注册信号
    void signals_register(QString,QString,QString);
    void signals_login(QString,QString);
    void signals_closeWindow();

public:
    virtual void closeEvent(QCloseEvent *event);


private:
    Ui::LoginWidget *ui;
};
#endif // LOGINWIDGET_H
