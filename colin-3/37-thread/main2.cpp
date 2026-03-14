// #include<QDebug>
// #include<windows.h>

// /*
// 解决线程并发的问题

// 线程同步:原子访问
// */

// int n = 0;

// DWORD(WINAPI ThreadProc)(void* p){
//     for(int i = 0;i<100;++i){
//         //++n;
//         ::_InterlockedIncrement((long*)&n);
//         qDebug()<<"n = "<<n;
//         Sleep(50);
//     }
//     return 0;
// }


// int main(){

//     //创建线程(window api),返回线程的句柄
//     HANDLE handle1 = ::CreateThread(nullptr,0,&ThreadProc,nullptr,0,nullptr);
//     HANDLE handle2 = ::CreateThread(nullptr,0,&ThreadProc,nullptr,0,nullptr);
//     HANDLE handle3 = ::CreateThread(nullptr,0,&ThreadProc,nullptr,0,nullptr);

//     if(WaitForSingleObject(handle1,10000) == WAIT_OBJECT_0){
//         if(handle1){
//             CloseHandle(handle1);
//             handle1 = nullptr;
//         }
//     }
//     if(WaitForSingleObject(handle2,10000) == WAIT_OBJECT_0){
//         if(handle2){
//             CloseHandle(handle2);
//             handle2 = nullptr;
//         }
//     }
//     if(WaitForSingleObject(handle3,10000) == WAIT_OBJECT_0){
//         if(handle3){
//             CloseHandle(handle3);
//             handle3 = nullptr;
//         }
//     }

//     return 0;
// }
