#include <stdio.h>
/*
《舍罕王的打赏》

在国际象棋的64个格子里摆麦子
第1个格子放1个
第2个格子放2个
第3个格子放4个
第4个格子放8个
编程：总共需要多少个麦子才能摆满64个格子

*/
int main09()
{
	unsigned long long m = 1,n = 0;
	int g;
	for (g = 1; g <=64; g++)
	{
		printf("第%d个格子放%llu个麦子\n",g,m);
		n+=m;
		m*=2;
	}
	printf("总共需要%llu个麦子\n",n);
	return 0;
}