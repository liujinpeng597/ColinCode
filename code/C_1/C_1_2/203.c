#include <stdio.h>
/*
	判断某年某月有几天
	闰年的判断公式： 年份能被4整除但不能被100整除 或者 能被400整除
*/
int main203()
{
	int year=2008;
	int month=2;
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			printf("31天\n");
			break;
		case 2: 
			if (year%4==0&&year%100!=0
				||year%400==0) 
			{
				printf("29天\n");
			}
			else
			{
				printf("28天\n");
			}
			break;
		default:
			printf("30天\n");
			break;
		}
	return 0;
} 