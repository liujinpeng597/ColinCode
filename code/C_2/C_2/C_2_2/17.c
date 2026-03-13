
#include<stdio.h>
#include<stdlib.h>
int main17 ()
{
	int ds[20],ns[20]  ;
	int i,j;
	int len=sizeof(ds)/sizeof(ds[0]);
	
	for(i=0;i<len;i++)
	{
		ds[i]=rand()%100;
		ds[i] = ds[i]*(ds[i]%3==0 ? -1 :1);
		printf("%d,",ds[i]);
	}
	printf("\n");
	/*把随机生成的数组成员中小于零的数字放到一个新数组ns中*/


	return 0;
}