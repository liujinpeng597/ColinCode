#include"TcpServerMediator.h"
#include"../net/TcpServer.h"

TcpServerMediator::TcpServerMediator() {
	m_pNet = new TcpServer(this);
}
TcpServerMediator::~TcpServerMediator() {
	if (m_pNet) {
		delete m_pNet;
		m_pNet = nullptr;
	}
}

// 打开网络
bool TcpServerMediator::openNet() {
	return m_pNet->initNet();
}

// 关闭网络
void TcpServerMediator::closeNet() {
	m_pNet->unInitNet();
}

// 发送数据
bool TcpServerMediator::sendData(char* data, int len, long to) {
	return m_pNet->sendData(data, len, to);
}

// 把接收到的数据传给核心处理类
// data:要传的数据
// len:数据的长度
// from:数据从哪里来
void TcpServerMediator::transmitData(char* data, int len, long from) {
	cout << "TcpServerMediator::transmitData:" << data << endl;
	char s[] = "东北雨姐真带派!";
	sendData(s, sizeof(s), from);
}