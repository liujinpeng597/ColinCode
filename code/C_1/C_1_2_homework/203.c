#include <stdio.h>
/*
	判断某年某月有几天
	闰年的判断公式： 年份能被4整除但不能被100整除 或者 能被400整除
*/
int main203()
{
	int year = 0;
	int month = 0;
	scanf_s("%d%d", &year, &month);
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){

	}
	return 0;
} 