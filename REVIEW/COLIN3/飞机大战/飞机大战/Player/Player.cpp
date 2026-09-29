#include "./Player.h"
#include "../Config/Config.h"
Player::Player(){
	m_x = 0; 
	m_y = 0;
	m_img;
	m_imgMask;
}
Player::~Player(){}
void Player::init(){
	//初始化真实坐标
	m_x = (BACKGROUND_W - PLAYER_W) / 2;//(背景宽度 - 飞机宽度) / 2
	m_y = BACKGROUND_H - PLAYER_H;//背景高度 - 飞机高度
	//loadimage
	::loadimage(&m_img,L"./res/player.jpg");
	::loadimage(&m_imgMask, L"./res/player_mask.jpg");
}
void Player::show(){
	//先putimage屏蔽图 SRCPAINT 再加载原图 SRCAND
	::putimage(m_x, m_y, &m_imgMask, SRCPAINT);
	::putimage(m_x, m_y, &m_img, SRCAND);
}
void Player::move(int direct){
	if (direct == VK_UP) {
		if (m_y - PLAYER_MOVE_STEP <= 0) {
			m_y = 0;
		}
		else {
			m_y -= PLAYER_MOVE_STEP;
		}
	}
	else if (direct == VK_DOWN) {
		if (m_y + PLAYER_MOVE_STEP >= BACKGROUND_H - PLAYER_H) {
			m_y = BACKGROUND_H - PLAYER_H;
		}
		else {
			m_y += PLAYER_MOVE_STEP;
		}
		
	}
	else if (direct == VK_LEFT) {
		if (m_x - PLAYER_MOVE_STEP <= 0) {
			m_x = 0;
		}
		else {
			m_x -= PLAYER_MOVE_STEP;
		}
	}
	else if (direct == VK_RIGHT) {
		if (m_x + PLAYER_MOVE_STEP >= BACKGROUND_W - PLAYER_W) {
			m_x = BACKGROUND_W - PLAYER_W;
		}
		else {
			m_x += PLAYER_MOVE_STEP;
		}
	}
}