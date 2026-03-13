#include <stdio.h>
int main10()
{
	//分析下面代码的执行结构，并通过调试器进行验证
	int aa[2][5] = {1,2,3,4,5,6,7,8,9,10};
	int*ptr1=(int*)(&aa+1);
	int *ptr2=(int*)( *(aa+1) );
	printf("%d,%d\n",*(ptr1-1),*(ptr2-1));
	return 0;
}