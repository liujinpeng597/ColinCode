#pragma once
#include<easyx.h>
#include"../GunnerList/Gunner.h"
#include<random>
using namespace std;

class Foe
{
public:
	int   m_x;
	int   m_y;
	IMAGE m_img;
	int   m_blood;
	int   m_picIndex;

	static random_device rd;  //ÕæËæ»úÊý
public:
	Foe();
	virtual ~Foe();
	virtual void init() = 0;
	virtual void show() = 0;
	void move(int step);
	virtual bool isHitGun(Gunner* pgun) = 0;
	virtual bool isHitPlayer(Player* p) = 0;
};