#include <stdio.h>
int fun11(int m,int n);
int main()
{

	/* 递归实现：两个正整数的最大公约数 */

	 printf("%d\n",fun11(124,36 ));

	return 0;
}

int fun11(int m,int n)
{
	if (m % n == 0)
	{
		return n;
	}
	return fun11(m,m%n);
}