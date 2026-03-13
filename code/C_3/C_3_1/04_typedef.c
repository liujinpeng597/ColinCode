#include <stdio.h>

 
int main04()
{
	/* 模板: typedef 现有类型名 自定义名称   */
	
	/*1 基本数据类型定义*/
    typedef int integer;
	integer a, b;
	char c;
	typedef char byte;
	byte c2;
	size_t shoes;
	time_t sj;
    typedef char KB[1024];
	KB _1k; 
	KB* p;
	/*2  指针类型定义*/
	int* x, * y, * z;
	typedef int* PINT;
	typedef int* PINT; 
	PINT xx, yy，zz;
	/*3  函数类型定义*/ 
	typedef int(*PARR)[4];
	PARR pl, p2, p3;
	typedef double (*PMATH)(double);
	PMATH pms[4];
	/*4 嵌套定义*/
	typedef int FiveInt[5];
	typedef FiveInt* PFI;
	PFI arr[3];
	 
	return 0;
}