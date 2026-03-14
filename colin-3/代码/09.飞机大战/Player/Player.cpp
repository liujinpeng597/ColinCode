#include"Player.h"
#include"../Config/Config.h"
#include"../GunnerList/Gunner.h"

Player::Player() {
	m_x = 0;
	m_y = 0;

	m_img;
	m_imgMask;
}
Player::~Player(){}
void Player::init(){
	m_x = (BACK_W - PLAYER_W)/2;
	m_y = BACK_H - PLAYER_H;

	::loadimage(&m_img,L"./res/res/player.jpg");
	::loadimage(&m_imgMask, L"./res/res/player_mask.jpg");
}
void Player::show(){
	::putimage(m_x, m_y, &m_imgMask,SRCPAINT/*传输方式*/); //默认是拷贝 copy,原方不动
	::putimage(m_x, m_y, &m_img, SRCAND/*传输方式*/); //默认是拷贝 copy,原方不动
}
void Player::move(int direct){
	//键盘的字符码 虚拟键
	if (direct == VK_UP) {//VK_UP:方向键上。
		if (m_y - PLAYER_MOVE_STEP >= 0) {
			m_y -= PLAYER_MOVE_STEP;
		}
		else {
			m_y = 0;
		}
	}
	if (direct == VK_DOWN) {
		if (m_y + PLAYER_MOVE_STEP <= (BACK_H - PLAYER_H)) {
			m_y += PLAYER_MOVE_STEP;
		}
		else {
			m_y = BACK_H - PLAYER_H;
		}
	}
	if (direct == VK_LEFT) {
		if (m_x - PLAYER_MOVE_STEP >= 0) {
			m_x -= PLAYER_MOVE_STEP;
		}
		else {
			m_x = 0;
		}
	}
	if (direct == VK_RIGHT) {
		if (m_x + PLAYER_MOVE_STEP <= (BACK_W - PLAYER_W)) {
			m_x += PLAYER_MOVE_STEP;
		}
		else {
			m_x = (BACK_W - PLAYER_W);
		}
	}
}

Gunner* Player::sendGun() {
	Gunner* pgun = new Gunner;
	pgun->init(this);
	return pgun;
}