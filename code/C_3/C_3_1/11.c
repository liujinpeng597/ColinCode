#include <stdio.h>
int fun11(int a,int b);
int main11()
{

	 /* 1.编写一个函数，功能为返回两个int类型参数的最大的值 */

	 printf("%d\n",fun11(88,68));

	 return 0;
}

int fun11(int a,int b)
{
	 return a>=b?a:b;
}