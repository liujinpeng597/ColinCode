#include <stdio.h>
/* 算法：交换两个变量的值  */
int main03 ()
{
	int x = 20,y = 30;
	int t;
	printf("原来的值：x=%d, y=%d\n",x,y);
	t = x;
	x = y;
	y = t;
	printf("交换后的值：x=%d, y=%d\n",x,y);

	return 0;
}