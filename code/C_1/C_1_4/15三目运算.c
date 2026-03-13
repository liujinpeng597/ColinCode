#include<stdio.h>
int main15()
{
	/*
	运算表达式的基本概念：
	1：运算符
	2：操作数
	3：表达式
	4：结合性 
	5：优先级
	*/
	/*
	牢记：只要是表达式 就有一个计算结果
	*/


	/*
	三目运算符：  ?  :
	*/
	int a=10;
	char r ;
	if (a%2==0)
	{
		r='T';
	}
	else
	{
		r='F';
	}
	 

	printf("%c\n",r);
	int age = 22;
    int sex = 1; 
    printf("%d\n", sex ? age >= 22 : age >= 20);
	return 0;
}