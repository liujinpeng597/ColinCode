#include"UdpMediator.h"
#include"../net/Udp.h"

UdpMediator::UdpMediator() {
	m_pNet = new Udp(this);
}
UdpMediator::~UdpMediator() {
	if (m_pNet) {
		delete m_pNet;
		m_pNet = nullptr;
	}
}

// 打开网络
bool UdpMediator::openNet() {
	return m_pNet->initNet();
}

// 关闭网络
void UdpMediator::closeNet() {
	m_pNet->unInitNet();
}

// 发送数据
bool UdpMediator::sendData(char* data, int len, long to) {
	return m_pNet->sendData(data,len,to);
}

// 把接收到的数据传给核心处理类
// data:要传的数据
// len:数据的长度
// from:数据从哪里来
void UdpMediator::transmitData(char* data, int len, long from) {
	//测试代码:打印接收到的数据
	cout << "UdpMediator::transmitData:" << data << endl;
}