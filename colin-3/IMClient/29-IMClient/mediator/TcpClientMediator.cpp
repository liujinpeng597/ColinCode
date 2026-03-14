#include"TcpClientMediator.h"
#include"../net/TcpClient.h"

TcpClientMediator::TcpClientMediator() {
	m_pNet = new TcpClient(this);
}
TcpClientMediator::~TcpClientMediator() {
	if (m_pNet) {
		delete m_pNet;
		m_pNet = nullptr;
	}
}

// 打开网络
bool TcpClientMediator::openNet() {
	return m_pNet->initNet();
}

// 关闭网络
void TcpClientMediator::closeNet() {
	m_pNet->unInitNet();
}

// 发送数据
bool TcpClientMediator::sendData(char* data, int len, long to) {
	return m_pNet->sendData(data, len, to);
}

// 把接收到的数据传给核心处理类
// data:要传的数据
// len:数据的长度
// from:数据从哪里来
void TcpClientMediator::transmitData(char* data, int len, long from) {
    Q_EMIT signals_recvServerData(data,len,from);
}
