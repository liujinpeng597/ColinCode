#include <stdio.h>
/*
	激励性问题：
	每天提高百分之一，百日后你的能力提高多少倍。
	反之
	每天降低百分之一，百日后你的能力降低多少倍。
*/
int main07 ()
{
	double power = 1.0;
	int day;
	for (  day  = 1; day  <=100; day++)
	{
		power *= 1.01;
	}
	printf("每天提高百分之一，百日后你的能力提高%.2f倍\n",power);

	power = 1.0;
	for (  day  = 1; day  <=100; day++)
	{
		power *= 0.99;
	}
	printf("每天提高百分之一，百日后你的能力降低%.2f倍\n",power); 
	return 0;
}