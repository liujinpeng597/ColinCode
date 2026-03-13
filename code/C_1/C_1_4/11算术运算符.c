#include<stdio.h>
int main11()
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
	printf("%d\n", 9 % 4);
	printf("%d\n", -9 % 4);
	printf("%d\n", 9 % 4);
    int zi = 1;
	zi = -zi;
	printf("%d\n", zi);
	zi = -zi;
	printf("%d\n", zi);
	zi = 8;
	printf("%d\n", --zi); printf("%d\n", --zi);
	/*
	算术运算符： + - * / % ( ) 
	相反数运算符：-
	*/
	/*int a, b, c, d;
	a = b = c = d = 8;
	a *= a += a = 5;*/
	//int a = 10, b = 10;
	//int c, d;
	//c = ++a;// 先加后用
	//d = a++;// 先用后加

	return 0;
}