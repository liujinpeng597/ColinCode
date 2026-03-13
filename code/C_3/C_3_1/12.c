#include <stdio.h>
int fun(int a,int b);
int main12()
{

	/* 2.编写一个函数，返回一个数到另外一个数之间所有整数相加的和 */
	printf("%d\n",fun(3,6));
	return 0;
}

int fun(int a,int b)
{
	int sum=0;
	if (a>b)
	{
		return 0;
	}
	for(a++;a<b;a++)
	{
		sum+=a;
	}
	return sum;
}

