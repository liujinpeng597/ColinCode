#pragma once
#include<Windowsx.h>
#include<easyx.h>
#include<map>
using namespace std;

class CGameFrame;   //声明类
extern CGameFrame* pGame;   //指针声明
//声明
CGameFrame* CreateObject();
extern int wndWidth;
extern int wndHeight;
extern int wndX;
extern int wndY;
extern const wchar_t* wndTitle;

#define INIT_MSGMAP(MSGID,MSGTYPE,CLASS)\
	m_msgMap[MSGID].msgType = MSGTYPE;\
	m_msgMap[MSGID].p_fun_##MSGTYPE = ( P_FUN_##MSGTYPE)&CLASS::On_##MSGID;



class CGameFrame
{
public:
	HWND m_hwnd;   //窗口句柄
	bool m_isQuit;  //是否退出,true:退出


	typedef void (CGameFrame ::* P_FUN_EX_MOUSE)(int, int);   //鼠标类别
	typedef void (CGameFrame ::* P_FUN_EX_KEY )(int);
	typedef void (CGameFrame ::* P_FUN_EX_WINDOW)(WPARAM, LPARAM);
	 
	//#define EX_MOUSE	    1
	//#define EX_KEY		2
	//#define EX_CHAR		4
	//#define EX_WINDOW	    8

	struct MsgTypeFun {
		int msgType;   //消息类别
		union{   //联合
			P_FUN_EX_MOUSE p_fun_EX_MOUSE;   //鼠标类别的函数指针
			P_FUN_EX_KEY   p_fun_EX_KEY;
			P_FUN_EX_WINDOW p_fun_EX_WINDOW;
		};
	};
	map<UINT, MsgTypeFun >  m_msgMap;  //消息映射表

	CGameFrame() :m_isQuit(false) {}
	virtual ~CGameFrame() {}
	virtual void InitMsgMap() = 0;
public:
	//1. 初始化游戏
	void InitGame(int width,int height,int x,int y,const wchar_t* pTitle) {
		//创建窗口
		m_hwnd = ::initgraph(width, height);
		//设定窗口的背景色
		::setbkcolor(RGB(255, 255, 255));   //设定背景颜色
		::cleardevice();   //目的： 将上面设定的白色，立即刷新到窗口上

		//将窗口移动到指定的位置(窗口句柄，位置x,y 窗口大小w,h ,是否重绘窗口
		::MoveWindow(m_hwnd,x,y, width, height,true);

		//设定窗口的标题  ,LPCWSTR  ->  typedef  const WCHAR * 。 typedef wchar_t WCHAR;
		::SetWindowText(m_hwnd, pTitle);

		INIT_MSGMAP(WM_CLOSE, EX_WINDOW,CGameFrame)
		INIT_MSGMAP(WM_PAINT, EX_WINDOW, CGameFrame);
		InitMsgMap();

		//为窗口设定回调函数
		::SetWindowLong(m_hwnd, GWL_WNDPROC/*32位下的宏*/,(LONG)&CGameFrame::RunGame);

		//调用具体游戏的初始化的接口函数
		On_Init();
	}
	//2.重绘游戏
	void On_WM_PAINT(WPARAM, LPARAM) {
		::BeginBatchDraw();  //开始批量绘图
		::cleardevice();//清除上一次显示残留的图片
		On_Paint();
		::EndBatchDraw();  //结束批量绘图
	}

	//回调函数： 1：窗口句柄，2：消息ID，3、4 :消息ID携带的各种信息
	static LRESULT	WINAPI RunGame(HWND hwnd , UINT msg, WPARAM w,LPARAM l  ) {
		if (pGame->m_msgMap.count(msg)) {   //如果存在于map中
			switch (pGame->m_msgMap[msg].msgType)
			{
			case EX_MOUSE:   //判断消息所属的类别，如果是鼠标类别
			{
				//类成员函数指针
				//(指针对象   ->*    类成员函数指针的名字)( 参数列表 )
				(pGame       ->*    pGame->m_msgMap[msg].p_fun_EX_MOUSE    )(GET_X_LPARAM(l), GET_Y_LPARAM(l));
			}
			break;
			case EX_KEY:
			{
				(pGame->*pGame->m_msgMap[msg].p_fun_EX_KEY)(w);
			}
			break;
			case EX_WINDOW:
			{
				(pGame->*pGame->m_msgMap[msg].p_fun_EX_WINDOW)(w,l);
			}
			}

			//一旦是我需要处理的消息，则及时刷新窗口
			//pGame->PaintGame();
			RECT rect = { 0,0,wndWidth ,wndHeight };
			::InvalidateRect(hwnd, &rect, FALSE);
		}
		return ::DefWindowProc(hwnd, msg, w,l);    //window  默认回调处理函数
	}
	//4.关闭游戏
	void On_WM_CLOSE(WPARAM,LPARAM) {
		On_Close();  //具体游戏的回收工作
		::closegraph();  //关闭窗口
		pGame->m_isQuit = true;
	}


public:
	virtual void On_Init() = 0;   //要求具体游戏一定要实现这个函数
	virtual void On_Paint() = 0;
	virtual void On_Close() = 0;
};

#define WND_PARAM(W,H,X,Y,TITLE)\
	/*在子类中定义*/\
	int wndWidth = W;\
	int wndHeight=H;\
	int wndX=X;\
	int wndY=Y;\
	const wchar_t* wndTitle=TITLE;



#define CREATE_OBJECT(CLASS)\
	CGameFrame* CreateObject() {\
		return new CLASS;\
	}


/*
定义一个子类，继承CGameFrame的父类，将游戏壳中的4个纯虚函数重写定义
void On_Init() ;   //程序初始化
void On_Paint();   //程序重绘
void On_Close();   //窗口关闭时调用
void InitMsgMap(); //初始化消息映射表，用于添加额外的消息绑定。

在子类的源文件中，使用两个宏 
WND_PARAM(  窗口宽度,窗口高度,窗口位置x坐标,窗口位置y坐标,窗口标题  )
CREATE_OBJECT( 子类类名 ) 


void InitMsgMap() 初始化消息映射表为纯虚函数，在子类中重写定义，添加额外消息和处理的绑定，
使用宏                         INIT_MSGMAP(    消息ID,     所属的消息类别, 子类类名  )  
如 添加鼠标左键按下消息的绑定:     INIT_MSGMAP(WM_LBUTTONDOWN, EX_MOUSE,      A  )

在子类中添加消息对应的处理函数，返回类型为void  函数名：On_后接消息ID的宏名字, 参数列表 要根据消息所属的类别而定，见下面3种。
如，添加鼠标左键消息的处理函数：void On_WM_LBUTTONDOWN(int, int);


消息类别3种：
EX_MOUSE	   参数：-> (int, int)
EX_KEY		   参数：-> (int)
EX_WINDOW	   参数：-> (WPARAM, LPARAM)

不断的  Message:消息 驱动游戏运行

*/


