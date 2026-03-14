#pragma once

#include<list>
#include"Gunner.h"
using namespace std;

class GunnerList {
public:
	list<Gunner*>m_lstGun;
public:
	GunnerList();
	~GunnerList();
	void showAll();
	void moveAll();
};