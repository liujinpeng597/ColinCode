#include <stdio.h>
int main09()
{
	//分析下面代码的执行结构，并通过调试器进行验证
	int a[3][2] = {(0,1),(1,2),(4,5)};
	int *p;
	p=a[1];
	printf("%d\n",p[0]);

	
	return 0;
}