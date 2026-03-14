#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;  //定义主窗口对象
    w.show(); //显示主窗口
    return a.exec();
}
