#include "snake.h"
#include "apple.h"
int fangXiang = 1;/*蛇头方向： 0右 1 上 2左 3 下*/
int snakeLie[100] = {10,10,10,10,10};
int snakeHang[100] = {10,11,12,13,14};
int snakeLen= 5;/*当前长度*/

void snakeMove(void)
{//身体爬 
	for ( int j=snakeLen-1;j>=1 ;j-- )
	{
		snakeHang[j] = snakeHang[j-1];
		snakeLie[j] = snakeLie[j-1];
	}
	//头爬
	switch (fangXiang)
	{
	case 0:
		snakeLie[0]++;
		break;
	case 1:
		snakeHang[0]--;//上
		break;
	case 2:
		snakeLie[0]--;
		break;
	case 3:
		snakeHang[0]++;//下
		break;
	}
}
void snakeGrow(void)
{
	snakeLen++;
}
int eatApple(void)
{
	return appleHang==snakeHang[0]
		&&appleLie==snakeLie[0] ;
}
int eatSelf(void)
{
	return 0;
}
int snakeOut(void)
{
	return 0;
}