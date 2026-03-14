//#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>//父类的头文件,Q开头是系统默认的文件

QT_BEGIN_NAMESPACE
//定义了命名空间,里面声明了【主界面】的类
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
//定义了【主窗口】的类
class MainWindow : public QMainWindow//继承主窗口父类
{
    //使用了和qt信号槽相关的一个宏
    Q_OBJECT

public:
    //声明了带参数的构造,参数为指定当前主窗口的父窗口,
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;//定义了【主界面】的指针,是包含(主窗口中包含了主界面)
};
#endif // MAINWINDOW_H
