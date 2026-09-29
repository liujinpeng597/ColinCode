#include "./Back.h"
#include "../Config/Config.h"

Back::Back() :m_x(0),m_y(0){

}
Back::~Back() {

}
void Back::init() {
	//真正初始化
	//初始化坐标
	m_x = 0;
	m_y = -BACK_H;
	//绑定图片image; 相对于工程目录
	::loadimage(&m_img, L"./res/res/back.jpg");
}
void Back::show() {
	//打印图片
	::putimage(m_x, m_y, &m_img);
}
void Back::move() {
	m_y += BACK_MOVE_STEP;
	//边界检测
	if (m_y >= 0) {
		m_y = -BACK_H;
	}
}