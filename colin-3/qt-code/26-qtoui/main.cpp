#include <QCoreApplication>
#include<iostream>
using namespace std;

//argc:命令行参数数量
//argv:描述具体的命令行
//默认会带一个命令函参数:生成的可执行程序的路径和名称
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    for(int i = 0;i<argc;++i){
        cout<<"out:"<<argv[i]<<endl;
    }
    return a.exec();
}
