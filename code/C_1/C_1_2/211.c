#include <stdio.h>
/*
父亲的年龄36儿子13，几年后父亲年龄是儿子年龄的二倍

*/
int main211()
{
	int dad = 36;
	int son = 13;
	int year;
	//------------写法（ 一 ）----------------------//
	for ( year=1; 1 ; year++)
	{
		if (dad==son*2)
		{
			printf("%i年后 爸爸%i岁 儿子%i岁 爸爸年龄是儿子年龄的2倍\n",year,dad,son);
			break;
		}
		dad++;
		son++;
	}
	//------------写法（ 二 ）----------------------//
	 dad = 36;
	 son = 13;
	for ( year=1; dad>son*2; year++)
	{
		dad++;
		son++;
	}
	printf("%i年后 爸爸%i岁 儿子%i岁 爸爸年龄是儿子年龄的2倍\n",year,dad,son);
	//------------写法（ 三 ） 最简化写法------不推荐---------------//
	for ( dad = 36,son = 13,year=1; dad>son+son; year++,dad++,son++) //主要使用了 , 逗号表达式
		;
	printf("%i年后 爸爸%i岁 儿子%i岁 爸爸年龄是儿子年龄的2倍\n",year,dad,son);
	return 0;
} 