#include <stdio.h>
int main13 ()
{
	 /* 挑出一组数中的最大数 是几 */
	int ds[]={10,30,43,43,43,23,12,40};
	int max = ds[0];
	int i;
	int length=sizeof(ds)/sizeof(ds[0]);
	//printf("%d",sizeof(ds)/sizeof(ds[0]));//计算数组的成员数量
	/* 扩展：最大数有几个 */
	for(i=1;i<length;i++)
	{
		if (max<ds[i])
		{
			max = ds[i];
		}
	}
	printf("%d\n",max);
	/* 扩展：第二大的是几 */

	return 0;
}