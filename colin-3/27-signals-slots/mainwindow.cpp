#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
using namespace std;
#include<QDebug>
#include<QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //重点！connect函数
    //将这个信号stateChange(int)和这个槽函数slots_ctrlLineEdit(int check)绑定关联
    connect(/*信号的发出者*/                                       ui->checkBox,
            /*发出的信号,宏参数中放的是信号函数名和参数列表,不要有形参名*/SIGNAL(stateChanged(int)),
            /*接收者*/                                            this,
            /*接收的槽函数*/                                       SLOT(slots_ctrlLineEdit(int))
            );

    ui->checkBox->setTristate(true);

    //设置标题,设置提示的文本。
    m_msgBox.setWindowTitle("666这是标题");
    m_msgBox.setText("看你身后");
    //设置自定义按钮
    pOk = m_msgBox.addButton("看！",QMessageBox::YesRole);
    pNo = m_msgBox.addButton("不看！",QMessageBox::NoRole);

    //信号
    // void buttonClicked(QAbstractButton *button);

    //槽函数:void slots_dealButton(QAbstractButton *button);

    auto con = connect(&m_msgBox,SIGNAL(buttonClicked(QAbstractButton *)),this,SLOT(slots_dealButton(QAbstractButton *)) );
    if(con){ // con 类似bool类型
        //如果是true
        qDebug()<<"绑定成功";
    }else{
        qDebug()<<"绑定失败";
    }

}
//自定义处理弹出框按钮点击的槽函数
void MainWindow::slots_dealButton(QAbstractButton *button){
    //要判断点击了哪个按钮
    if(button == pOk){
        qDebug()<<"点击了看!";
    }else if(button == pNo){
        qDebug()<<"点击了不看!";
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    //qDebug() == cout;
    //主要用于调试
    qDebug()<<"on_pushButton_2_clicked";

}

//QLineEdit textChanged(QString) 让这个编辑框只能输入数字
//函数名有要求:on_发出信号的对象名_发出的信号函数名
void MainWindow::on_lineEdit_textChanged(const QString &str)
{
    //QString Qt中封装好的字符串类
    qDebug()<<"str="<<str;
    if(str.size()>0){
        //要截取字符创最后一个字符
        //str.mid(1,3);//从哪个位置截取,截取多长
        //str.left(); //左截取多长
        QString r = str.right(1); //右截取多长
        if(r>="0" && r<="9"){
            qDebug()<<"是合法的数字";
        }else{
            qDebug()<<"是非法的数字";
            QString l = str.left(str.size()-1);//左边截取长度-1位
            //123a截取123
            //先找到组件 设置为新的文本
            ui->lineEdit->blockSignals(true);
            //setText(l)会再次触发textChanged信号！
            ui->lineEdit->setText(l);
            ui->lineEdit->blockSignals(false);
        }
    }
}

//信号:stateChange(int),手写槽
//手动添加的槽函数
void MainWindow::slots_ctrlLineEdit(int check){
    qDebug()<<"slots_ctrlLineEdit(int check)"<<check;
    //控制输入框是否可编辑
    if(check == 2){//勾选 让编辑框不可编辑
        ui->lineEdit->setDisabled(true);
    }else if(check == 0){//取消勾选 让编辑框可以编辑
        ui->lineEdit->setDisabled(false);
    }else if(check == 1){//半选状态
        //提示:QMessageBox::information(this/*父窗口*/,/*标题*/ "提示",/*提示内容*/"这是一个半选状态");
        //警告:QMessageBox::warning(this/*父窗口*/,/*标题*/ "警告",/*提示内容*/"这是一个半选状态");
        // QMessageBox::StandardButton but = QMessageBox::critical(this/*父窗口*/,/*标题*/ "错误",/*提示内容*/"这是一个半选状态",QMessageBox::Yes|QMessageBox::No);//用位或的形式指定多个按钮

        // if(but == QMessageBox::Yes){
        //     qDebug()<<"点击了Yes";
        // }else if(but == QMessageBox::No){
        //     qDebug()<<"点击了No";
        // }
        m_msgBox.show();//显示自定义弹出框
    }
}

//发射信号按钮槽函数
void MainWindow::on_pb_emitSignal_clicked(){
    //要发射我的自定义信号,和调用普通函数写法一样

    //获取编辑框上的数字

    QString s = ui->lineEdit->text();
    int num = s.toInt();

    emit signals_sendNumber(num); //另一个窗口接收,
    qDebug()<<"另一个窗口已经接收";
}

