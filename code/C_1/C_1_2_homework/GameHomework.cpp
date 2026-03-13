#include <easyx.h>
#include <time.h>
#include <conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<graphics.h>
/*游戏界面绘制*/
void gamePaint();
/*游戏初始化绘制*/
void gameInit();
/*游戏定时处理*/
void gameInterval();
/*游戏键盘按下*/
void gameKeypress(int key);
/*游戏鼠标按下*/
void gameMouseDown(int mouseX,int mouseY);
/*游戏鼠标抬起*/
void gameMouseUp(int mouseX,int mouseY);
/*游戏鼠标移动*/
void gameMousemove(int mouseX,int mouseY);

/*透明图绘制*/
void drawImage(IMAGE* picture, int  picture_x, int picture_y); //x为要载入图片的X坐标，y为Y坐标
/*矩形碰撞检测*/
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 );

/*设置100即每隔100毫秒刷新以下界面绘图。*/
int interval = 100;//TODO: 1 设置定时器时间间隔（单位毫秒）
// TODO: 1 设置窗口: 宽度 高度
int screenWidth = 800;
int screenHeight=600;
int stop = 0;//是否停止游戏
//-----------------------------------//
int times = 0; 
/*初始化游戏 */
void initgame()
{
	srand((unsigned)time(NULL));//随机数初始化
	setbkcolor(NULL);//背景色
	setbkmode(TRANSPARENT);// 设置背景混合模式: TRANSPARENT为透明
	gameInit();
}
/*
	界面绘图演示案例
*/
void paintDemo()
{
	/* 颜色设置：
	//设置线的颜色     Blue Green Red  十六进制表示三原色
	setlinecolor(0x0000ff);//红色的 线
	//-设置填充的颜色
	setfillcolor(0x00ff00);//绿色的 填充
	//-设置字体的颜色
	settextcolor(0xff0000);//蓝色的 字体颜色
	*/


	/*  画直线的案例

		setlinestyle(PS_DASH, 粗细); //PS_DASH 虚线  PS_SOLID 实现 PS_DOT 点线...
		line(点1x坐标 ,点1y坐标,点2x坐标 ,点2y坐标); //两点确定一条直线
		例如：
	
	setlinestyle(PS_DASH, 3);
	line(50 ,50,300 ,200); 
	*/


	/*
	  绘制矩形
	  1.空心矩形
	  rectangle( 顶点x,顶点y,右下点x,右下点的y);
	  按宽度 和 高度计算为
	  rectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度);
	  rectangle(x,y,x+width,y+height);
	  2.实心矩形（无边框）
	  solidrectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度); 
	  3.实心矩形（有边框）
	  fillrectangle( 顶点x,顶点y,顶点x+宽度,顶点y+高度); 
	  例如： 绘制一个宽50 高50 的正方形
	
		rectangle( 100,100,100+50,100+50);
		fillrectangle( 100,100,100+50,100+50);
	*/
	

	/*
	  绘制圆形
	  1、空心圆
	  circle( 圆心x坐标,圆心y坐标,半径);
	  2、实心圆（无边框）
	  solidcircle( 圆心x坐标,圆心y坐标,半径);
	  3、实心圆（有边框）
	  fillcircle( 圆心x坐标,圆心y坐标,半径);
	  例如： 
	  
		circle( 75,75,50);
		fillcircle( 75,75,50);
	*/


	/*
	 绘制文字
	 1、设置字体样式
	 settextstyle(字高, 0, _T("字体名称"));
	 2、设置文字位置与内容
	 outtextxy(x,y,L"文字内容");
	 例如：
	 settextstyle(46, 0, _T("黑体"));
	 outtextxy(300,400,L"helloworld你好世界");
	 */


	/*模板化 动态文字
	TCHAR str[100];
	_stprintf (str, L"%s的数学成绩是%d", L"小明",61);
	outtextxy(300,400,str );
	*/


	/*贴图
	1、声明一个存放图片变量（为了节省图片变量内存空间，通常把其放到全局变量位置）
	IMAGE img1 ; 
	2、加载硬盘的图片到图片变量的内存地址
	loadimage(&img1, L".\\图片路径\\图片文件名" ); //.代表项目硬盘存储的位置
	3、把内存中的图片显示到界面上。
	putimage(x,y,&img1); 
	*/


	/*例如：贴一张图 
	//loadimage(&img, L".\\images\\jpg\\1\\image0.jpg") ; //图片不透明
	IMAGE img1 ;
	loadimage(&img1, L".\\images\\1\\image0.png") ; 
	putimage(10,10,&img1);*/


	/*例如：再贴一张图
	IMAGE img2;
	loadimage(&img2, L".\\images\\2\\image8.png") ; 
	putimage(10,200,&img2); */


	/*例如：连续贴图，要求相同尺寸的图
	IMAGE img3;
	TCHAR imgPath[100];
	int i;
	for (i = 0; i <=23; i++)
	{
		_stprintf (imgPath, L".\\images\\%d\\image%d.png", 3,i);
		loadimage(&img3,imgPath ) ; 
		putimage(100*i,300,&img3); 
	}*/
	 
}

/*绘制显示游戏界面*/
void paint()
{
	BeginBatchDraw();//打开双缓冲
	cleardevice();// 清屏
	paintDemo();
	gamePaint();
	//-----------------------------//
	EndBatchDraw();//关闭双缓冲
}



/*游戏运行*/
void run()
{
	ExMessage mouse ;
	 
	while (1)	// 游戏主循环  可借助break 结束循环
	{
		
		if (peekmessage(&mouse,EM_MOUSE,false))//原来是mouseHit（已经作废）需要用peekmessage代替
		{
			mouse=getmessage();
			if (mouse.message == WM_LBUTTONDOWN )
			{
				gameMouseDown(mouse.x,mouse.y);
			}
			else if (mouse.message == WM_LBUTTONUP )
			{
				gameMouseUp(mouse.x,mouse.y);
			}

			else if(mouse.message == WM_MOUSEMOVE)
			{
				gameMousemove(mouse.x,mouse.y);
			}
			
			
			paint();
		}

		
		if (_kbhit())
		{
			int k=_getch();
			 
			gameKeypress(k);
			 paint();
		}

		//------时间处理 勿动-----------//
		Sleep(1);
		times++;
		if(times%(interval/10)!=0){
			continue;
		}
		times=0;
		if(stop)
		{
			break;
		}
		gameInterval();
		 
		//-------------------------------//
		paint();// 刷新显示游戏界面
	}
}



/*绘制透明背景图*/
 void drawImage(IMAGE* picture, int  picture_x, int picture_y) //x为载入图片的X坐标，y为Y坐标
{

	// 变量初始化
	DWORD *dst = GetImageBuffer();    // GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD *draw = GetImageBuffer(); 
	DWORD *src = GetImageBuffer(picture); //获取picture的显存指针
	int picture_width = picture->getwidth(); //获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); //获取picture的高度，EASYX自带
	int graphWidth = getwidth();       //获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     //获取绘图区的高度，EASYX自带
	int dstX = 0;    //在显存里像素的角标

	// 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	for (int iy = 0; iy < picture_height; iy++)
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width; //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24); //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16); //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);   //G
			int sb = src[srcX] & 0xff;              //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x )+ (iy +   picture_y ) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}
//检测两个矩形是否相碰撞
int testHit(int x1,int y1,int w1,int h1,int x2,int y2,int w2,int h2 )
{
 return !(x1 + w1 < x2||
		 y1 + h1 < y2 ||
		 x2 + w2 <x1 ||
		 y2 + h2<y1 );
}
// 主函数，开启游戏
int main  ()
{
	initgraph(screenWidth, screenHeight,SHOWCONSOLE);		
	initgame();					// 初始化游戏
	paint();// 刷新显示游戏界面
	 
	flushmessage();		// 清空鼠标缓冲区
	while (_kbhit()) _getch();	// 清空键盘缓冲区
	run();						// 开始游戏
	closegraph();//关闭图形环
	return 0;
}
 

//--------------优雅的警戒线 以上为雷区 非专业 勿进------------------// 
//TODO: 2 全局变量声明位置 
 

//TODO: 3 游戏初始化位置  
 void gameInit()
{

}
 //TODO: 4 绘图处理位置  
void gamePaint()
{
  	//TODO: 作业1 同心圆
	 
	//TODO: 作业2 蓝白色相间的箭靶
	
	//TODO: 作业3 国际象棋棋盘，每个格子为50×50

	//TODO: 作业4 绘制五子棋棋盘 共有15×15个格子 每个格子为30×30
	 
	//TODO: 作业5 数字时钟：北京时间：23时59分55秒

}
 //TODO: 5 定时处理位置
void gameInterval()
{
	 
}
//TODO: 6 处理键盘控制位置
void gameKeypress(int key)
{
	switch (key)
	{
	case 'A':
	case 'a':    // 左
				
		break;	
	case 'S':
	case 's':   // 下
				
		break;	
	case 'D':
	case 'd':   // 右
				
		break;	
	case 'W':  // 上
	case 'w':  
				
		break;	

	case 72: //上
				 
		break;
	case 80://下
				  
		break;
	case 75://左
		 	 
		break;
	case 77://右
		  	  
		break;
	default://任意键
		break;
	}
}

//TODO: 7 处理鼠标控制位置
void gameMouseDown(int mouseX,int mouseY)
{
	 
}
void gameMouseUp(int mouseX,int mouseY)
{
	 
}
void gameMousemove (int mouseX,int mouseY)
{
	 
}