#include "loginwidget.h"

#include <QApplication>

#include"kernel.h"

// 程序主入口
int main(int argc, char *argv[])
{
    // 初始化Qt应用
    QApplication a(argc, argv);

    // 创建内核对象（内核是程序核心控制类，管理所有业务逻辑）
    Kernel kernel;

    // 启动应用事件循环
    return a.exec();
}
