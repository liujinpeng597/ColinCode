#pragma once
#include"Foe.h"

class FoeSma :public Foe {
public:
	void init();
	void show();
	bool isHitGun(Gunner* pgun);
	bool isHitPlayer(Player* p);
};