#include <stdio.h>
int main08 ()
{
	//分析下面代码的执行结构，并通过调试器进行验证
	int a[4] = {1,2,3,4};
	int *ptr1=(int*)(&a+1 );
	int *ptr2 = (int*)((int)a+1 );

	printf("%x, %x",ptr1[-1],*ptr2);
	
	return 0;
}