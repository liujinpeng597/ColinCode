// #include <QCoreApplication>
// #include<windows.h>
// #include<qDebug>

// bool isTheradQuit = false;

// //线程回调函数
// DWORD(WINAPI ThreadProc)(void* p){
//     int nn = *(int*)p;
//     // for(int i = 0;i<nn;++i){
//     //     qDebug()<<"--子线程--"<<"i:"<<i;
//     //     Sleep(1000);
//     // }

//     while(!isTheradQuit){
//         qDebug()<<"子线程 --";
//         Sleep(1000);
//     }

//     Sleep(8000);

//     //可能有风险,强制结束线程导致以下代码不会执行 如delete函数 容易出现内存泄漏

//     qDebug()<<"线程即将退出";
//     return 0;
// }



// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);

//     int n = 20;

//     //主线程

//     //创建线程(window api),返回线程的句柄
//     HANDLE handle = ::CreateThread(
//         nullptr,    /*安全属性,nullptr:默认安全属性*/
//         0,          /*线程栈大小,0:使用默认大小1M*/
//         &ThreadProc,/*线程函数的地址*/
//         &n,         /*线程函数的参数*/
//         0,          /*创建标志,0:创建完线程后立即执行*/
//         nullptr     /*线程id*/
//         );

//     for(int i = 0;i<n;++i){
//         qDebug()<<"----------------------主线程-------------------->"<<"i:"<<i;

//         //控制子线程
//         //挂起线程,会将挂起计数器的值++
//         //返回的是挂起之前的值

//         // if(i == 3){
//         //     DWORD n1 = ::SuspendThread(handle);
//         //     qDebug()<<"n1 = "<<n1;
//         // }

//         // //挂起线程
//         // if(i == 5){
//         //     DWORD n2 = ::SuspendThread(handle);
//         //     qDebug()<<"n2 = "<<n2;
//         // }

//         // //恢复线程
//         // if(i == 8){
//         //     DWORD n3 = ResumeThread(handle);
//         //     qDebug()<<"n3 = "<<n3;
//         // }

//         // //恢复线程
//         // if(i == 10){
//         //     DWORD n4 = ResumeThread(handle);
//         //     qDebug()<<"n4 = "<<n4;
//         // }

//         //可以挂起多次,挂起几次就要恢复几次,这样线程才能执行
//         //创建线程的时候,【挂起计数器】的值,如果值为0,则代表线程运行


//         if(i == 5){
//             qDebug()<<"即将通知子线程退出";
//             isTheradQuit = true;

//             //如果知道某个子线程是否退出了
//             DWORD flag = WaitForSingleObject(handle,5000/*等待多少毫秒*/); //阻塞函数
//             if(flag == WAIT_OBJECT_0){//在规定时间内正常退出了
//                 qDebug()<<"等到了子线程退出";
//             }else if(flag == WAIT_TIMEOUT){//在规定的时间内 没有等到子线程的退出
//                 //强制手段,让线程退出
//                 qDebug()<<"等待超时了,强制退出";
//                 ::TerminateThread(handle,-1);
//             }
//         }
//         Sleep(1000);
//     }

//     if(handle){
//         ::CloseHandle(handle); //回收线程相关的系统资源
//         handle = nullptr;
//     }

//     return a.exec();
// }
