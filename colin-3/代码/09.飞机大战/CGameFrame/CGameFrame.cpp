#include "CGameFrame.h"
CGameFrame* pGame = nullptr;




int main() {
	pGame = CreateObject();

	pGame->InitGame(wndWidth, wndHeight, wndX, wndY, wndTitle);
	pGame->On_WM_PAINT(0,0);   //先绘制一下
	//pGame->RunGame();
	while (!pGame->m_isQuit) {  //改为判断标志是否退出
		Sleep(1000);
	}

	delete pGame;
	pGame = nullptr;

	return 0;
}