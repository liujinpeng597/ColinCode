#pragma once
#include<easyx.h>
//#include"../GunnerList/Gunner.h"

class Gunner; //ÉùÃ÷Àà

class Player {
public:
	int m_x;
	int m_y;
	IMAGE m_img;
	IMAGE m_imgMask;
public:
	Player();
	~Player();
	void init();
	void show();
	void move(int direct);
	Gunner* sendGun();
};