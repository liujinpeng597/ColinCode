#include "mainwindow.h"

#include <QApplication>

#include"form.h"

#include<qDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Form form;//定义另一个窗口的对象
    form.show();

    QObject::connect(&w,SIGNAL(signals_sendNumber(int)),&form,SLOT(slots_recvNumber(int)));
    qDebug()<<"发射信号已连接";

    return a.exec();
}
