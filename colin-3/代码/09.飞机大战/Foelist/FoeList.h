#pragma once
#include<list>
using namespace std;
#include"Foe.h"

class FoeList {
public:
	list<Foe*> m_lstFoe;
	list<Foe*> m_lstBoomFoe;
public:
	FoeList();
	~FoeList();
	void showAll();
	void moveAll();
};