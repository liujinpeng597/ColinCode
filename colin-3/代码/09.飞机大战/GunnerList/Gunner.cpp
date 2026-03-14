#include"Gunner.h"
#include"../Config/Config.h"

Gunner::Gunner() {
	m_x = 0;
	m_y = 0;
}
Gunner::~Gunner() {}
void Gunner::init(Player* p) {
	m_x = p->m_x + (PLAYER_W - GUNNER_W) / 2;
	m_y = p->m_y;
	::loadimage(&m_img, L"./res/res/gunner.jpg");
}
void Gunner::show() {
	::putimage(m_x, m_y, GUNNER_W, GUNNER_H/*显示图片的宽度高度*/, &m_img, GUNNER_W, 0/*从哪个位置开始显示*/, SRCPAINT);
	::putimage(m_x, m_y, GUNNER_W, GUNNER_H/*显示图片的宽度高度*/, &m_img, 0, 0/*从哪个位置开始显示*/, SRCAND);
}
void Gunner::move() {
	m_y -= GUN_MOVE_STEP;
}