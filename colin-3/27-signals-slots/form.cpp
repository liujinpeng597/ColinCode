#include "form.h"
#include "ui_form.h"
#include<qDebug>

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::slots_recvNumber(int num){
    qDebug()<<"num:"<<num;
    //将收到的数字显示到窗口的LCD组件上
    ui->lcdNumber->display(num);
}
