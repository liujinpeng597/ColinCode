#pragma once
#include"Foe.h"

class FoeBig :public Foe {
public:
	void init();
	void show();
	bool isHitGun(Gunner* pgun);
	bool isHitPlayer(Player* p);
};