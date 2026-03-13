#include <stdio.h>
#include "01函数基本概念.h"
int main01()
{

	/*重构基本思想*/

	/*函数的意义：对流程结构的封装*/

	/*函数的基本结构*/

	int age = 21;
	int sex = 0;
	判断结婚(sex, age);

	return 0;
}

void 判断结婚(int sex, int age)
{
	if (sex)
	{
		if (age >= 22)
		{
			printf("男的 能\n");
		}
		else
		{
			printf("男的 不能\n");
		}
	}
	else
	{
		if (age >= 20)
		{
			printf("女的 能\n");
		}
		else
		{
			printf("女的 不能\n");
		}
	}
}
