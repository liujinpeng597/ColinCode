#include <stdio.h>
/*
有一只青蛙掉入一口深 10 米的井中。每天白天这只青蛙跳上 4 米晚上又滑下 3 米, 
问：这只青蛙经过多少天可以从井中跳出?
*/
int main209 ()
{
	int gao=0;  //蛤蟆的高度
	int  bw=1;//白天:1  晚上:0
	int ts = 0;//总天数
	do
	{
		//白爬
		if(bw ) 
		{
			gao=gao+5;
			bw=0;
			ts++;
		}
		else//晚滑
		{
			gao=gao-4;
			bw=1;
		}
		//打印高度
		printf("爬的高度：%d\n",gao);
	}
	while(gao<10);//每当 (满足条件 高度不到10米);
	printf("总共用的天数是：%d天\n",ts);

	return 0;
} 