#include"TcpClient.h"
#include"../mediator/TcpClientMediator.h"

//客户端构造函数
TcpClient::TcpClient(INetMediator* p) {
	m_pMediator = p;
}

//客户端析构函数
TcpClient::~TcpClient() {

}

//初始化网络(加载库,创建套接字,链接服务器,创建接收数据的线程)
bool TcpClient::initNet() {
	//加载库
	WORD version = MAKEWORD(2, 2);
	WSADATA data = {};
	int err = WSAStartup(version, &data);
	if (err != 0) {
		cout << "TcpClient WSAStartup fail." << endl;
	}
	if (HIBYTE(data.wVersion) == 2 && LOBYTE(data.wVersion) == 2) {
		cout << "TcpClient WSAStartup version success." << endl;
	}
	else {
		cout << "TcpClient WSAStartup version error." << endl;
		WSACleanup();	
		return true;
	}
	
	//创建套接字
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == m_sock) {
		cout << "TcpClient socket error:" << WSAGetLastError() << endl;
	}
	else {
		cout << "TcpClient socket success." << endl;
	}

	// 定义要连接的服务端地址（本机回环IP + 服务端端口）
	sockaddr_in addrServer = {};
	addrServer.sin_family = AF_INET;
	addrServer.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrServer.sin_port = htons(TCP_PROT);
	// 用客户端Socket连接到服务端地址
	err = connect(m_sock, (sockaddr*)&addrServer, sizeof(addrServer));
	if (err == SOCKET_ERROR) {
		cout << "TcpClient connect error:" << WSAGetLastError() << endl;
		closesocket(m_sock);
		WSACleanup();
		return false;
	}
	cout << "TcpClient connect success." << endl;
	
	//开始接收数据线程
	m_handle = (HANDLE)_beginthreadex(nullptr, 0,&recvThread, this, 0, nullptr);
	return true;
}

//接收数据线程
unsigned __stdcall TcpClient::recvThread(void* lpVoid) {
	//为什么接收数据需要线程?
	//因为recv()函数是阻塞函数(Block Function),会一直等着接收消息,如果不单开一线的话,会影响主函数的正常运行
	//正常来说recv()函数在接收到消息后会自动断开,但这不符合功能需求,所以在接收数据函数中使用循环接收
	TcpClient* pThis = (TcpClient*)lpVoid;
	pThis->recvData();
	return 1;
}

//关闭网络(回收线程资源,关闭套接字,卸载库)
void TcpClient::unInitNet() {
	if (m_handle) {
		m_bRunning = false;
		if (WAIT_TIMEOUT == WaitForSingleObject(m_handle, 5000)) {
			TerminateThread(m_handle, -1);
		}
		
		CloseHandle(m_handle);
		m_handle = nullptr;
	}

	if (&m_sock && INVALID_SOCKET != m_sock) {
		closesocket(m_sock);
	}

	WSACleanup();
}

//发送数据函数
bool TcpClient::sendData(char* data, int len, long to) {
	// 1.检查参数是否合法
	if (!data || len <= 0) {
		cout << "Udp::sendData paramater error" << endl;
		return false;
	}
	// 2.先发包长度(len)
	int nSendNum = send(m_sock,(char*) & len, sizeof(len),0);
	if (nSendNum == SOCKET_ERROR) {
		cout << "TcpClient::sendData error1:" << WSAGetLastError() << endl;
		return false;
	}
	// 3.再发包内容(data)
	nSendNum = send(m_sock, data,len, 0);
	if (nSendNum == SOCKET_ERROR) {
		cout << "TcpClient::sendData error2:" << WSAGetLastError() << endl;
		return false;
	}

	
	return true;
}

//接收数据函数
void TcpClient::recvData() {
	int nRecvNum = 0;//接收到的数据的长度
	int nPackLen = 0;//包长度
	int nOffset = 0;//记录一个包中累计接收到的数据的长度
	while (m_bRunning) {
		// 1.接收包长度
		nRecvNum = recv(m_sock,(char*)&nPackLen,sizeof(int),0);
		if (nRecvNum>0) {
			//接收数据包长度成功,接收包内容
			//申请一个空间
			char* packBuf = new char[nPackLen];
			//循环接收一个数据包的内容
			while (nPackLen > 0) {
				nRecvNum = recv(m_sock, packBuf + nOffset, nPackLen, 0);
				if (nRecvNum > 0) {
					//接收一次数据成功
					nOffset += nRecvNum;
					nPackLen -= nRecvNum;
				}
				else {
					cout << "TcpClient::recvData error2:" << WSAGetLastError() << endl;
					break;
				}
			}//退出循环的时候,说明一个包的内容接收完成了
			//TODO:接收数据包内容成功,把数据包的内容发给中介者
			//测试代码:打印接收到的数据
			m_pMediator->transmitData(packBuf, nOffset, m_sock);
			//一个包接收完成,累计接收数据量清零
			nOffset = 0;
		}else {
			cout << "TcpClient::recvData error1:" << WSAGetLastError() << endl;
			break;
		}
	}
}