#include <stdio.h>
int main()
{
 
	/*
	注意1: 指针不要位移到不属于本程序的内存空间
	也不要利用指针改变不属于本程序的内存空间的数据
	*/
	
	 /*
	注意2:声明多个指针变量类型时，*不能省略。
	*/

	/*
	注意3: 指针变量的初始值如果没有明确指向目标用NULL赋值
	*/
	/*int a = 1;
	int* p = NULL;
	p = &a;

	p += 4000;
	*p = 6;*/



	int a = 1, b = 100, c, d;
	int* p, * q = &a, * m, * k;

	*q = 3;

	/*
	注意3: 指针变量的初始值如果没有明确指向目标用NULL赋值
	*/
	int* pp = NULL;//空指针：不指向任何地址
	//printf("%d\n", *pp);
	int n = 1;
	int* p = &n;
	int** pp = &p;
	int*** ppp = &pp;
	printf("%d", ***ppp);

	return 0;
}