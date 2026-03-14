#include"FoeBig.h"
#include"../ConFig/Config.h"

#define PIC_INIT_INDEX 4

void FoeBig::init() {

	//srand(/*当前时间戳*/time(NULL)); //设定随机数种子
	//rand(); //基于上面设定的种子，产生随机数

	m_x = rd() % (BACK_W - FOEBIG_W + 1);
	m_y = -FOEBIG_H;
	::loadimage(&m_img, L"./res/res/foebig.jpg");
	m_blood = 5;
	m_picIndex = PIC_INIT_INDEX;
}
void FoeBig::show() {
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H, &m_img, FOEBIG_W,
		FOEBIG_H * (PIC_INIT_INDEX - m_picIndex), SRCPAINT);
	::putimage(m_x, m_y, FOEBIG_W, FOEBIG_H, &m_img, 0,
		FOEBIG_H * (PIC_INIT_INDEX - m_picIndex), SRCAND);
}
bool FoeBig::isHitGun(Gunner* pgun) {
	//取炮弹的中心点
	int x = pgun->m_x + GUNNER_W / 2;
	int y = pgun->m_y + GUNNER_H / 2;
	if (x >= m_x && x <= m_x + FOEBIG_W && y >= m_y && y <= m_y + FOEBIG_H) {
		return true;
	}
	return false;
	 }
bool FoeBig::isHitPlayer(Player* p) { 
	//玩家飞机,分别取三个点
	//点1
	int x1 = p->m_x + PLAYER_W / 2;
	int y1 = p->m_y;
	if (x1 >= m_x && x1 <= m_x + FOEBIG_W && y1 >= m_y && y1 <= m_y + FOEBIG_H) {
		return true;
	}
	//点2
	int x2 = p->m_x;
	int y2 = p->m_y + PLAYER_H / 2;
	if (x2 >= m_x && x2 <= m_x + FOEBIG_W && y2 >= m_y && y2 <= m_y + FOEBIG_H) {
		return true;
	}
	//点3
	int x3 = p->m_x + PLAYER_H;
	int y3 = y2;
	if (x3 >= m_x && x3 <= m_x + FOEBIG_W && y3 >= m_y && y3 <= m_y + FOEBIG_H) {
		return true;
	}

	return false;
}