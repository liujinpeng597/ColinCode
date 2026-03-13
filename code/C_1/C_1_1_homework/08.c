#include <stdio.h>
/*  
	计算一个整数的平方根
	史上最笨方法
*/
int main08 ()
{
	int a=2;
	double j = 0.0;
	while (j*j<a)
	{
		j+=0.0001;
	}
	printf("%d的平方根是%.3f\n",a,j);
	return 0;
}