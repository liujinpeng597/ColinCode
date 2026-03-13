#include <stdio.h>
/*  
	判断 任意三个边长能否构成一个三角形
	提示：根据数学定理：构成三角形三边满足任意两边之和大于第三边。
*/
int main05 ()
{
	int a,b,c;
	a = 10;
	b = 5;
	c = 8;
	if (a+b>c&&a+c>b&&b+c>a) //&& 运算符为并且之意。  || 为或者之意
	{
		printf("可以构成三角形");
	}
	else
	{
		printf("不可以构成三角形");
	}
	return 0;
}