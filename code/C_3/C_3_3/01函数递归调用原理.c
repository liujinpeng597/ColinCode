#include <stdio.h>
int fun01(int n);
int main01()
{
	//用递归思想实现n！
	/* 递归基本概念的理解 */

	/* 递归算法的基本模式: 终止条件，递推公式 */

	/* 函数递归的执行原理 */
	printf("%d\n",fun01(5));

	return 0;
}

int fun01(int n)
{
	if (n==1)
	{
		return 1;
	}
	return n*fun01(n-1);
}