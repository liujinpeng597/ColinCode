#include <stdio.h>
int fun13(int a[],int len);
int main13 ()
{

	/* 3.编写一个函数，返回一个int数组中最大的元素的值 */

	int a[]={1,5,6,9,8,1,4,5};
	printf("%d\n",fun13(a, sizeof(a)/sizeof(a[0])));
	return 0;
}

int fun13(int a[],int len)
{
	int max = a[0];
	int i;
	for(i=0;i<len;i++)
	{
		if (max<a[i])
		{
			max=a[i];
		}
	}
	return max;
}