#include "./Back.h"
#include "../Config/Config.h"

Back::Back(){
	m_x = 0;
	m_y = 0;
}
Back::~Back(){}
void Back::init(){
	m_x = 0;
	m_y = -BACKGROUND_H;
	//loadimage 相对于当前目录
	::loadimage(&m_img, L"./res/back.jpg");
}
void Back::show(){
	//putimage
	::putimage(m_x,m_y, &m_img);
}
void Back::move() {
	m_y += BACKGROUND_MOVE_STEP;
	if (m_y >= 0) {
		m_y = -BACKGROUND_H;
	}
}