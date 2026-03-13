#include <stdio.h>
/* 计算圆形的面积 
	要求：计算结果显示 2位小数
*/
int main02 ()
{
	int r = 7  ;
	float area;
	area = 3.1415926 * r*r;
	printf("半径为%d的圆形，它的面积为%.2f",r,area);
	return 0;
}