#include"TcpServer.h"
#include"../mediator/TcpServerMediator.h"
//构造函数
TcpServer::TcpServer(INetMediator* p) {
    m_pMediator = p;
}

//析构函数
TcpServer::~TcpServer() {

}

// 初始化网络（加载库、创建套接字、绑定、监听、创建接收连接线程）
bool TcpServer::initNet() {
	// 1.加载库
    WORD version = MAKEWORD(2, 2);
    WSADATA data = {};
    int err = WSAStartup(version, &data);
    if (err != 0) {
        cout << "TcpServer WSAStartup fail." << endl;
        return false;
    }
    if (HIBYTE(data.wVersion) != 2 || LOBYTE(data.wVersion) != 2) {
        cout << "TcpServer WSAStartup version error." << endl;
        WSACleanup();
        return false;
    }
    cout << "TcpServer WSAStartup version success." << endl;
    
    // 2.创建套接字
    m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == m_sock) {
        cout << "TcpServer socket error:" << WSAGetLastError() << endl;
        WSACleanup();
        return false;
    }
    cout << "TcpServer socket success." << endl;

    // 3.绑定服务端ip和端口号
    sockaddr_in addrServer = {};
    addrServer.sin_family = AF_INET;
    addrServer.sin_addr.S_un.S_addr = INADDR_ANY;  // 监听所有网卡
    addrServer.sin_port = htons(TCP_PROT);         // 绑定指定端口
    //bind绑定函数 显式的绑定某一端口
    //connect连接函数 隐式的分配端口号
    err = bind(m_sock, (sockaddr*)&addrServer, sizeof(addrServer));
    if (err == SOCKET_ERROR) {
        cout << "TcpServer bind error:" << WSAGetLastError() << endl;
        closesocket(m_sock);
        WSACleanup();
        return false;
    }
    cout << "TcpServer bind success." << endl;

    // 4.监听
    err = listen(m_sock, WAIT_CONNECT_MAX);  // 最大等待连接数300
    if (err == SOCKET_ERROR) {
        cout << "TcpServer listen error:" << WSAGetLastError() << endl;
        closesocket(m_sock);
        WSACleanup();
        return false;
    }

    // 5.接收连接的线程
    m_handle = (HANDLE)_beginthreadex(nullptr, 0, &acceptThread, this, 0, nullptr);
    if (m_handle == nullptr) {
        cout << "TcpServer create accept thread fail." << endl;
        m_bRunning = false;
        closesocket(m_sock);
        WSACleanup();
        return false;
    }
	return true;
}

//接收连接的线程函数(循环接收连接)
unsigned __stdcall TcpServer::acceptThread(void* lpVoid) {
    TcpServer* pThis = (TcpServer*)lpVoid;
    SOCKET sock = INVALID_SOCKET;
    sockaddr_in addrClient = {};
    int addrSize = sizeof(addrClient);
    HANDLE handle = nullptr;
    unsigned int threadId = 0;
    cout << "TcpServer accept thread running..." << endl;

    while (pThis->m_bRunning) {
        // 阻塞等待客户端连接
        sock = accept(pThis->m_sock, (sockaddr*)&addrClient, &addrSize);
        if (sock == INVALID_SOCKET) {
            cout << "TcpServer accept error:" << WSAGetLastError() << endl;
        }
        else {
            cout << "TcpServer accept success:" << inet_ntoa(addrClient.sin_addr) << endl;
            //每个连接成功的客户端,会产生一个专门跟这个客户端收发数据的socket
            //给每个客户端创建一个接收数据的线程
            //线程和socket就是1对1的关系

            //创建接收数据的线程
            handle = (HANDLE)_beginthreadex(nullptr, 0, &recvThread, pThis, 0, &threadId);
            if (handle) {
                //保存线程id和socket 1对1的关系
                pThis->m_mapThreadIdToSocket[threadId] = sock;
                //保存接收数据线程的句柄
                pThis->m_listHandle.push_back(handle);
            }
        }
    }
    return 1;
}

// 接收数据的线程函数
unsigned __stdcall TcpServer::recvThread(void* lpVoid) {
    TcpServer* pThis = (TcpServer*)lpVoid;
    pThis->recvData();
    return 0;
}

// 关闭网络（回收资源、关闭所有socket、卸载库）
void TcpServer::unInitNet() {
    // 1.回收线程资源
    if (m_handle) {
        m_bRunning = false;
        if (WAIT_TIMEOUT == WaitForSingleObject(m_handle, 5000)) {
            TerminateThread(m_handle, -1);
        }
        CloseHandle(m_handle);
        m_handle = nullptr;
    }
    HANDLE handle = nullptr;
    for (auto ite = m_listHandle.begin(); ite != m_listHandle.end();) {
        //从当前节点中取出句柄
        handle = *ite;
        //回收句柄对应的线程资源
        if (handle) {
            if (WAIT_TIMEOUT == WaitForSingleObject(handle, 5000)) {
                TerminateThread(handle, -1);
            }
            CloseHandle(handle);
            handle = nullptr;
        }
        ite = m_listHandle.erase(ite);
    }

    // 2.关闭套接字
    if (m_sock && INVALID_SOCKET != m_sock) {
        closesocket(m_sock);
    }
    SOCKET s = INVALID_SOCKET;
    for (auto ite = m_mapThreadIdToSocket.begin(); ite != m_mapThreadIdToSocket.end();) {
        //从当前节点取出socket
        s = ite->second;
        //关闭套接字
        if (s && s != INVALID_SOCKET) {
            closesocket(s);
        }
        //从map中移除无效结点,erase函数的返回值是下一个有效结点
        ite = m_mapThreadIdToSocket.erase(ite);
    }
    // 3.卸载库
    WSACleanup();
}

// 给指定客户端发送数据（to：客户端socket）
bool TcpServer::sendData(char* data, int len, long to) {
    // 1.检查参数是否合法
    if (!data || len <= 0) {
        cout << "Udp::sendData paramater error" << endl;
        return false;
    }
    // 2.先发包长度(len)
    int nSendNum = send(to, (char*)&len, sizeof(len), 0);
    if (nSendNum == SOCKET_ERROR) {
        cout << "TcpClient::sendData error1:" << WSAGetLastError() << endl;
        return false;
    }
    // 3.再发包内容(data)
    nSendNum = send(to, data, len, 0);
    if (nSendNum == SOCKET_ERROR) {
        cout << "TcpClient::sendData error2:" << WSAGetLastError() << endl;
        return false;
    }
    return true;
}

//接收数据
void TcpServer::recvData() {
    //休眠五秒:5秒时间内,不去cpu的任务队列里排队
    //给acceptThread一段时间,把socket保存到map中，保证下面从map中取值的时候一定会有值
    Sleep(5);
    //取出当前线程对应的socket
    //获取当前线程的id
    unsigned int threadId = GetCurrentThreadId();
    //根据线程id获取当前的socket
    SOCKET sock = INVALID_SOCKET;
    if (m_mapThreadIdToSocket.count(threadId)>0) {
        sock = m_mapThreadIdToSocket[threadId];
    }
    else {
        cout << "TcpServer::recvData error." << endl;
        return;
    }

    int nRecvNum = 0;//接收到的数据的长度
    int nPackLen = 0;//包长度
    int nOffset = 0;//记录一个包中累计接收到的数据的长度
    while (m_bRunning) {
        // 1.接收包长度
        nRecvNum = recv(sock, (char*)&nPackLen, sizeof(int), 0);
        if (nRecvNum > 0) {
            //接收数据包长度成功,接收包内容
            //申请一个空间
            char* packBuf = new char[nPackLen];
            //循环接收一个数据包的内容
            while (nPackLen > 0) {
                nRecvNum = recv(sock, packBuf + nOffset, nPackLen, 0);
                if (nRecvNum > 0) {
                    //接收一次数据成功
                    nOffset += nRecvNum;
                    nPackLen -= nRecvNum;
                }
                else {
                    cout << "TcpServer::recvData error2:" << WSAGetLastError() << endl;
                    break;
                }
            }//退出循环的时候,说明一个包的内容接收完成了
            //TODO:接收数据包内容成功,把数据包的内容发给中介者
            //测试代码:打印接收到的数据,并且给客户端回一个数据
            m_pMediator->transmitData(packBuf, nOffset, sock);
            //一个包接收完成,累计接收数据量清零
            nOffset = 0;
        }
        else {
            cout << "TcpServer::recvData error1:" << WSAGetLastError() << endl;
            break;
        }
    }
}