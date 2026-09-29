#pragma once
#include "../CGameFrame/CGameFrame.h"
#include "../Back/Back.h"
#include "../Player/Player.h"

class Plane : public CGameFrame {
public:
	Back m_back;
	Player m_player;
	//GunnerList m_gunList;
	//FoeList m_foeList;
	int m_score;
public:
	Plane();
	~Plane();
	void On_Init();
	void On_Paint();
	void On_Close();
	void InitMsgMap();
	//处理键盘按下
	//WM_KEYDOWN,EX_KEY;
	void On_WM_KEYDOWN(int);
	//WM_TIMER,EX_WINDOW;
	void On_WM_TIMER(WPARAM, LPARAM);
	void setTimer();
	void killTimer();
	void showScore();
};