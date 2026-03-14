#pragma once
#include"Foe.h"

class FoeMid :public Foe {
public:
	void init();
	void show();
	bool isHitGun(Gunner* pgun);
	bool isHitPlayer(Player* p);
};