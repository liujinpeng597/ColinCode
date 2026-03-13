#include<stdio.h>
int main16()
{
	
	int ds[] = {1,2,3,4,5,6,7,8,9,19,36,78};
	int i,j;
	int len=sizeof(ds)/sizeof(ds[0]);
	int find=19;
	/*寻找指定数字在数组中首次出现的下标*/
	//顺序查找
	for (i = 0; i < len; i++)
	{
		if (ds[i] == find)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (!(i < len))
	{
		printf("没找到。");
	}
	return 0;
}