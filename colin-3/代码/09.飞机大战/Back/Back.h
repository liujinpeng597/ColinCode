#pragma once
#include<easyx.h>

class Back {
public:
	int m_x;
	int m_y;
	IMAGE m_img;
public:
	Back();
	~Back();
	void init();
	void show();
	void move();
};