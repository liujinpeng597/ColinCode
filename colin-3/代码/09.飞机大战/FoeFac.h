#pragma once
#include"../09.飞机大战/FoeFac.h"

class FoeFac {  //简单工厂

public:
	Foe* createFoe(const string& type);
};