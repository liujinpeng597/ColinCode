#include"Udp.h"
#include"../mediator/UdpMediator.h"

Udp::Udp(INetMediator* p) {
	m_pMediator = p;
}
Udp::~Udp() {

}

bool Udp::initNet() {
	//1.加载库
		//参数1,版本号
	WORD version = MAKEWORD(2, 2);
	//参数2,WSADATA结构体
	WSADATA data{};
	int err = WSAStartup(version, &data);

	//判断返回值
	if (err != 0) {
		cout << "Udp WSAStartup fail" << endl;
		return 1;
	}

	//判断版本号
	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2) {
		cout << "Udp WSAStartup success" << endl;
	}
	else {
		cout << "Udp WSAStartup fail" << endl;
		//卸载库
		WSACleanup();
		return 1;
	}

	//2.创建套接字
	m_sock = socket(AF_INET/*IPV4*/, SOCK_DGRAM/*UDP*/, IPPROTO_UDP/*使用UDP*/);

	//判断是否创建成功
	if (m_sock == INVALID_SOCKET) {
		cout << "Udp socket error:" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}
	else {
		cout << "Udp socket success" << endl;
	}

	//3.绑定ip和端口(告诉操作系统,当前进程要使用哪个ip和端口号)
	//创建结构体 给结构体内容赋值
	sockaddr_in addr = {};
	//地址类型IPV4
	addr.sin_family = AF_INET;//地址家族,AF_INET代表使用IPV4地址类型
	//要用的端口号
	addr.sin_port = htons(12345); //网络字节序:大端存储,htons转换成网络字节序
	//要用的ip地址
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //绑定所有网卡

	//绑定 套接字s 绑定结构体 结构体中有套接字s需要的东西 算出结构体长度
	err = bind(m_sock, (sockaddr*)&addr, sizeof(addr));

	//判断是否绑定成功
	if (SOCKET_ERROR == err) {
		//bind 失败通常是因为端口被占用、权限不足等
		cout << "Udp bind error:" << WSAGetLastError() << endl;
		//关闭套接字,卸载库
		closesocket(m_sock);
		WSACleanup();
		return 1;
	}
	else {
		cout << "Udp bind success" << endl;
	}

	// 4.准备接收数据的线程
	// CreateThread()和ExitThread()是一对,如果在线程中使用了C++运行时的函数(例如strcpy),ExitThread()退出线程的时候不会回收资源
	// 在使用C++运行时库函数的时候,例如strcpy会创建空间,但ExitThread()不会回收这个空间,导致内存泄漏
	// _beginthreadex()和-endthreadex()是一对,_endthreadex会先回收资源,然后调用ExitThread()
	m_handle = (HANDLE)_beginthreadex(
		nullptr,/*安全级别,nullptr代表使用默认的安全级别*/
		0, /*堆栈大小,0代表使用默认的堆栈大小1M*/
		&recvThread,/*线程函数的起始地址*/
		this,/*线程函数的参数链表*/ 
		0,/*初始化标志位,0代表创建即运行,线程挂起*/ 
		nullptr/*输出参数,创建线程时操作系统分配的线程id*/
	);
	return true;
}

unsigned __stdcall Udp::recvThread(void* lpVoid) {
	Udp* pThis = (Udp*)lpVoid;
	pThis->recvData();
	return 1;
}

void Udp::unInitNet() {
	//创建线程的时候,操作系统给每个线程分配3个资源:线程id,线程句柄,内核对象，引用计数器是2
	//回收线程资源就是让计数器变成0; 1.结束线程工作,计数器减1 2.关闭句柄,计数器减1
	// 1.回收线程资源
	if (m_handle) {
		// 1.1结束线程工作
		m_bRunning = false;
		if (WAIT_TIMEOUT/*等待超时,如果等待5000ms线程还没有结束*/ == WaitForSingleObject(m_handle/*等哪个线程的句柄*/, 5000/*等待多长时间单位是毫秒*/)) {
			//线程没有结束工作,就强制杀死线程
			TerminateThread(m_handle, -1);
		}
		// 1.2关闭句柄
		CloseHandle(m_handle);
		m_handle = nullptr;
	}

	// 2.关闭套接字
	if (m_sock && INVALID_SOCKET != m_sock) {
		closesocket(m_sock);
	}

	// 3.卸载库
	WSACleanup();
}

bool Udp::sendData(char* data, int len, long to) {

	// 1.判断参数是否合法
	if (!data || len <= 0) {
		cout << "Udp::sendData paramater error" << endl;
		return false;
	}

	// 2.发送数据
	
	sockaddr_in addrTo = {};
	addrTo.sin_family = AF_INET;
	addrTo.sin_port = htons(UDP_PROT); 
	addrTo.sin_addr.S_un.S_addr = to; 
	int nSendNum = sendto(m_sock, data, len, 0, (sockaddr*)&addrTo, sizeof(addrTo));
	if (SOCKET_ERROR == nSendNum) {
		cout << "Udp::sendto error:" << WSAGetLastError() << endl;
	}
	return true;
}

//接收数据(在线程中做)
void Udp::recvData() {
	int nRecvNum = 0; //实际接收到的数据长度
	char recvBuf[4096] = "";
	sockaddr_in addrFrom = {};
	int addrSize = sizeof(addrFrom);

	//循环接收数据
	//外部控制此循环 循环条件处用变量
	while (m_bRunning) {
		sockaddr_in addrFrom = {};
		nRecvNum = recvfrom(m_sock, recvBuf, sizeof(recvBuf), 0, (sockaddr*)&addrFrom, &addrSize);
		if (nRecvNum > 0) {
			//接收数据成功
			//申请一个新的空间
			char* packBuf = new char[nRecvNum];
			//把接收到的数据拷贝到新的空间中
			memcpy(packBuf, recvBuf, nRecvNum);
			//TODO:把收到的数据传给中介者类
			
		}
		else {
			cout << "Udp::recvData error:" << WSAGetLastError() << endl;
			break;
		}
	}
}