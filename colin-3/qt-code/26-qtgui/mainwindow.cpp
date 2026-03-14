#include "mainwindow.h"
#include "ui_mainwindow.h"//根据界面后生成的头文件,ctrl+鼠标左键

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) //调用父类的构造函数
    , ui(new Ui::MainWindow) //主界面指针new对象
{
    //建立主界面
    ui->setupUi(this);//建立界面
    //涉及到主界面的操作代码,应该写在这行的下面
}

MainWindow::~MainWindow()
{
    delete ui;
}
