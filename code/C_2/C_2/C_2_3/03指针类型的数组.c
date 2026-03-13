#include <stdio.h>
int main03()
{
	int a=1,b=2,c=3,d=4,i;
	// 指针类型的数组简称：指针数组。 每个数组成员都是指针变量。
	//int *p[4]={ };
	int arr[4] = { 1,2,3,4 };
	int* pa[4] = { &a,arr,arr + 1,&arr[3] };
	for (int i = 0; i < 4; i++) {
		printf("%d\n", *pa[i]);
	}	 
	return 0;
}