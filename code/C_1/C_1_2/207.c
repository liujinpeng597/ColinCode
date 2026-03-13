#include <stdio.h>
/*
	判断一个坐标值在 第几象限
*/
int main207 ()
{
	int x=10;
	int y=10;
	if (x==0&&y==0)
	{
		printf("原点");
	}	
	if (x>0) 
	{
		if (y>0) 
		{
			printf("一象限\n");
		} 
		else
		{
			printf("四象限\n");
		}
	} 
	else
	{
		if (y>0) 
		{
			printf("二象限\n");
		} 
		else
		{
			printf("三象限\n");
		}		
	}
	return 0;
} 