#include <stdio.h>
/*
判断一个 整数 是 奇数还是偶数
*/
int main01 ()
{
	int a = 23;
	if (a%2==0) //知识点： % 为求余数运算又称为取模运算
	{
		printf("%d是偶数\n",a);// \为转义符号 \n的含义为换行
	}
	else
	{
		printf("%d是奇数\n",a);
	}
	return 0;
}