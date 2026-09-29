#include "./Plane.h"
WND_PARAM(600 + 16, 800 + 39, 500, 50, L"飞机大战")
CREATE_OBJECT(Plane)
Plane::Plane(){}
Plane::~Plane(){}
void Plane::On_Init(){
	//初始化背景
	m_back.init();
	m_player.init();
	setTimer();
}
void Plane::On_Paint(){
	m_back.show();
	m_player.show();
}
void Plane::On_Close(){}
void Plane::InitMsgMap(){
	INIT_MSGMAP(WM_KEYDOWN, EX_KEY, Plane);
	INIT_MSGMAP(WM_TIMER, EX_WINDOW, Plane);
}
//处理键盘按下
//WM_KEYDOWN,EX_KEY;
void Plane::On_WM_KEYDOWN(int){
	
}
//WM_TIMER,EX_WINDOW;
void Plane::On_WM_TIMER(WPARAM w, LPARAM){
	if (w == 1) {
		m_back.move();
	}else if (w == 2) {
		if (::GetAsyncKeyState(VK_UP)) {
			m_player.move(VK_UP);
		}
		if (::GetAsyncKeyState(VK_DOWN)) {
			m_player.move(VK_DOWN);
		}
		if (::GetAsyncKeyState(VK_LEFT)) {
			m_player.move(VK_LEFT);
		}
		if (::GetAsyncKeyState(VK_RIGHT)) {
			m_player.move(VK_RIGHT);
		}
	}
}
void Plane::setTimer(){
	//Background移动定时器
	::SetTimer(m_hwnd, 1/*定时器id*/, 80, nullptr/*回调函数*/);
	//Player移动定时器
	::SetTimer(m_hwnd, 2/*定时器id*/, 20, nullptr/*回调函数*/);
}
void Plane::killTimer(){}
void Plane::showScore(){}