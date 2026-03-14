#include"Back.h"
#include"../Config/Config.h"

Back::Back():m_x(0),m_y(0){}
Back::~Back(){}
//有实际意义的初始化
void Back::init() {
	m_x = 0;
	m_y = -BACK_H;
	//和图片资源绑定
	//::loadimage(&m_img,L"C:\\Users\\24191\\Desktop\\科林明伦\\科林明伦 - 三阶段\\代码\\09.飞机大战\\res\\res\\back.jpg");
	//相对于工程目录来说,而不是相对于当前的源文件
	::loadimage(&m_img, L"./res/res/back.jpg");
}
void Back::show(){
	::putimage(m_x, m_y, &m_img);
}
void Back::move(){
	m_y += BACK_MOVE_STEP;
	//初始化
	if (m_y >= 0) {
		m_y = -BACK_H;
	}
}
