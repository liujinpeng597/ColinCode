#include <stdio.h>
int main14()
{
	/* 向右旋转一个4×4的矩阵 */
	int a[4][4] = { 
		{1,0,0,0},
		{1,1,0,0},
		{1,0,0,0},
		{0,0,0,0}};
	int b[4][4];
	int i,j,k,t;
	printf("旋转前\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j< 4;j++)
		{
			b[j][3-i] = a[i][j];
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j< 4;j++)
		{
			a[i][j] = b[i][j] ;
		}
	}


	printf("\n\n\n旋转后\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	/*
	{0,1,1,1},
	{0,0,1,0},
	{0,0,0,0},
	{0,0,0,0}
	
	{0,0,0,0},
	{0,0,0,1},
	{0,0,1,1},
	{0,0,0,1}
	*/


	return 0;
}