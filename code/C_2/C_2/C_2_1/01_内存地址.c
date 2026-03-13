#include <stdio.h>
int main01()
{
	//1 什么是内存地址
	int a = 5;
	//2 地址相关运算：&取变量所占字节的首地址  * 根据地址取值
	printf("%d\n", &a);
	printf("%p\n", &a);

	printf("%d\n", a);
	printf("%d\n", *&a);

	int* p;//指针变量——能指向一个int类型空间的 指针变量
	p = &a;//p保留了a地址，形象讲：p指向了a的空间
	
	return 0;
}