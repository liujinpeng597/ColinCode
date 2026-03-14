#pragma once

#include<easyx.h>
#include"../Player/Player.h"

class Gunner {
public:
	int m_x;
	int m_y;
	IMAGE m_img;
public:
	Gunner();
	~Gunner();
	void init(Player* p);
	void show();
	void move();

};