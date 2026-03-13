#include <stdio.h>
/* 1+2+3.., 何时超过100  */
int main04 ()
{
	int sum=0;
	int a=1;

	do
	{
		sum=sum+a;
		a+=1;
		//printf("第%d个数累加和是%d\n",a,sum);
	}
	while(sum<100);

	printf("第%d个数累加和是%d刚好超过100\n ",a,sum);
	return 0;
}