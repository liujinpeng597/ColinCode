#include <stdio.h>
int main07()
{
	//分析下面代码的执行结构，并通过调试器进行验证
	int a[5]={1,2,3,4,5};
	int *ptr=(int*)(&a+1);
	printf("%d ,%d\n",*(a+1),*(ptr-1));

	
	return 0;
}