#pragma once
//全局变量的    声明
extern int fangXiang ;/*蛇头方向： 0右 1 上 2左 3 下*/
extern int snakeLie[100] ;
extern int snakeHang[100];
extern int snakeLen ;/*当前长度*/
//函数         声明

/*蛇 爬行*/
void snakeMove(void);
/*长个*/
void snakeGrow(void);
/*能吃苹果
返回：0 不能 1能
*/
int eatApple(void);

/*能 咬自己
返回：0 不能 1能
*/
int eatSelf(void);

/*能 出界
返回：0 不能 1能
*/
int  snakeOut(void);