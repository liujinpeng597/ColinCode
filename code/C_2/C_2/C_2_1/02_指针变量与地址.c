#include <stdio.h>
int main02()
{
	//1 什么是指针变量：存储内存地址的变量为指针变量 
	//声明指针变量
	int a = 5;
	//2 指针变量的字节数：根据操作系统的位数而不同。

	//3 指针的移动：根据数据类型不同，移动的步伐大小也不同

	//4 利用指针对存储值进行算术运算（注意运算符的优先级）。
	int* p;//指针变量——能指向一个int类型空间的 指针变量
	p = &a;//p保留了a地址，形象讲：p指向了a的空间
	//直接访问 内存空间 可以干啥
	*p = 7;
	*p += 5;
	*p *= 2;
	(*p)++;
	++*p;

	short* ps = &a;
	char* pc = &a;
	long long* pll = &a;
	printf("%d %d %d\n", sizeof(int*), sizeof(p),sizeof(*p));
	printf("%d %d %d\n", sizeof(short*), sizeof(ps), sizeof(*ps));
	printf("%d %d %d\n", sizeof(char*), sizeof(pc), sizeof(*pc));
	printf("%d %d %d\n", sizeof(long long*), sizeof(pll), sizeof(*pll));

	printf("%d %d %d\n", p, p + 1, p + 2);
	printf("%d %d %d\n", ps, ps + 1, ps + 2);
	printf("%d %d %d\n", pc, pc + 1, pc + 2);
	printf("%d %d %d\n", pll, pll + 1, pll + 2);

	//特殊的 指向类型 的指针
// void* 类型的指针： 
// 仅仅用于保留地址 
// 无法：间接访问空间 
// 无法：偏移到另一个地址 ——因为没有指向类型
	void* pv = &a;
	//*pv = 1;
	//pv = pv + 1;

	return 0;
}