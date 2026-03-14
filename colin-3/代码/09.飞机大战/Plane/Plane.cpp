#include"Plane.h"
#include"../Foelist/FoeBig.h"
#include"../Foelist/FoeSma.h"
#include"../Foelist/FoeMid.h"
#include"../FoeFac.h"

WND_PARAM(600 + 16, 800 + 39, 500, 50, L"飞机大战")

CREATE_OBJECT(Plane)

Plane::Plane() :m_score(0), m_player(Player::createPlayer()) {}
Plane::~Plane() {}
void Plane::On_Init() {//程序初始化
	m_back.init();
	setTimer();
	m_player.init();

}
void Plane::On_Paint() {
	m_back.show();
	m_player.show();
	m_gunList.showAll();
	m_foeList.showAll();
	showScore();
}
void Plane::On_Close() {}
void Plane::InitMsgMap() {
	INIT_MSGMAP(WM_KEYDOWN, EX_KEY, Plane);
	INIT_MSGMAP(WM_TIMER, EX_WINDOW, Plane);
}
void Plane::On_WM_KEYDOWN(int key) {
	m_player.move(key);

	if (key == VK_SPACE) {
		Gunner* pgun = m_player.sendGun();
		m_gunList.m_lstGun.push_back(pgun);//尾添加炮弹
	}

}
void Plane::On_WM_TIMER(WPARAM w/*定时器的id*/, LPARAM) {//触发
	if (/*一号定时器触发*/w == 1) {
		m_back.move();
	}
	else if (w == 2) {
		//检测此时方向键是否按下
		if (::GetAsyncKeyState(VK_UP)) {//如果返回的是真，表示按键是按下的状态
			m_player.move(VK_UP);
		}
		if (::GetAsyncKeyState(VK_DOWN)) {//如果返回的是真，表示按键是按下的状态
			m_player.move(VK_DOWN);
		}
		if (::GetAsyncKeyState(VK_LEFT)) {//如果返回的是真，表示按键是按下的状态
			m_player.move(VK_LEFT);
		}
		if (::GetAsyncKeyState(VK_RIGHT)) {//如果返回的是真，表示按键是按下的状态
			m_player.move(VK_RIGHT);
		}
	}
	else if (w == 3) {
		m_gunList.moveAll();
	}
	else if (w == 4) {
		m_foeList.moveAll();
	}
	else if (w == 5) {
		int r = Foe::rd() % 100;
		Foe* pfoe = nullptr;
		if (r < 50)
		{
			//pfoe = new FoeSma;
			pfoe = m_foefac.createFoe("FOESMA");
		}
		else if (r >= 50 && r < 80) {
			//pfoe = new FoeMid;
			pfoe = m_foefac.createFoe("FOEMID");

		}
		else {
			//pfoe = new FoeBig;
			pfoe = m_foefac.createFoe("FOEBIG");

		}

		if (pfoe) {
			pfoe->init();
			m_foeList.m_lstFoe.push_back(pfoe);//尾添加敌人飞机
		}
	}
	else if (w == 6) {//有节点的增删用迭代器

		bool isBoom = false;
		list<Foe*>::iterator itFoe = m_foeList.m_lstFoe.begin();
		while (itFoe != m_foeList.m_lstFoe.end()) {

			//判断是否和玩家飞机碰撞
			if ((*itFoe)->isHitPlayer(&m_player)) {
				//停止所有的定时器
				killTimer();

				//弹出弹出框
				::MessageBox(m_hwnd, L"GAME OVER!", L"提示", MB_OK);

				//程序退出
				On_WM_CLOSE(0, 0);
			}

			//遍历所有炮弹
			list<Gunner*>::iterator itGun = m_gunList.m_lstGun.begin();
			while (itGun != m_gunList.m_lstGun.end())
			{
				if ((*itFoe)->isHitGun(*itGun)) {
					//如果碰撞了，删除炮弹
					delete(*itGun);
					(*itGun) = nullptr;
					//删除炮弹链表节点
					itGun = m_gunList.m_lstGun.erase(itGun);
					if (--(*itFoe)->m_blood <= 0) {
						//要爆炸了，将敌人费解从正常链表中转移到爆炸链表
						m_foeList.m_lstBoomFoe.push_back(*itFoe);
						itFoe = m_foeList.m_lstFoe.erase(itFoe);
						isBoom = true;
						m_score++;
						//如果是最后一个敌人飞机，则不能继续炮弹的循环了，
						if (itFoe == m_foeList.m_lstFoe.end())
						{
							break;
						}
					}
					continue;
				}
				++itGun;
			}
			if (isBoom) {
				isBoom = false;
			}
			else
			{
				++itFoe;
			}
		}
	}
	else if (w == 7) {
		//遍历爆炸的敌人飞机，改变下标减1
		list<Foe*>::iterator it = m_foeList.m_lstBoomFoe.begin();
		while (it != m_foeList.m_lstBoomFoe.end()) {
			if (--(*it)->m_piclndex < 0) {
				//删除敌人飞机
				delete (*it);
				//删除节点
				it = m_foeList.m_lstBoomFoe.erase(it);
				continue;
			}

			it++;
		}
	}
}
void Plane::setTimer() {//统一设定定时器
	//设定定时器的函数
	::SetTimer(m_hwnd, 1/*定时器的id*/, 80/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);
	//定时检测方向键是否按下，如果按下的话，再按照设定频率去移动
	::SetTimer(m_hwnd, 2/*定时器的id*/, 20/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);
	//炮弹定时移动
	::SetTimer(m_hwnd, 3/*定时器的id*/, 60/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);
	//敌人飞机移动
	::SetTimer(m_hwnd, 4/*定时器的id*/, 60/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);
	//敌人飞机创建
	::SetTimer(m_hwnd, 5/*定时器的id*/, 3000/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);
	//判断是否碰撞（炮弹和敌人飞机，玩家飞机和敌人飞机）
	::SetTimer(m_hwnd, 6/*定时器的id*/, 10/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);
	//爆炸特效
	::SetTimer(m_hwnd, 7/*定时器的id*/, 20/*出发的频率，单位是毫秒*/, nullptr/*回调函数*/);

}
void Plane::killTimer() {
	::KillTimer(m_hwnd, 1/*定时器的id*/);
	::KillTimer(m_hwnd, 2/*定时器的id*/);
	::KillTimer(m_hwnd, 3/*定时器的id*/);
	::KillTimer(m_hwnd, 4/*定时器的id*/);
	::KillTimer(m_hwnd, 5/*定时器的id*/);
	::KillTimer(m_hwnd, 6/*定时器的id*/);

}
void Plane::showScore() {
	//显示分数
	//整形转字符串
	//itoa
	WCHAR sc[5] = { 0 };
	_itow_s(m_score, sc, 10);

	RECT rect{ 0, 0, 60, 40 };
	drawtext(sc, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	settextcolor(RGB(200, 0, 0));


}