#include<stdio.h>
int main04()
{
	/*
	自动类型转换
	*/
	printf("%d %g\n", 7 / 2, 7. / 2);
	/*
	自动类型转换
	*/
	//1 存储时以变量类型为准
	double m = 88;
	int n = 25.69;
	//2 算术运算时规律：
	printf("%d\n", sizeof(5 + 8LL + 'A'));
	printf("%d\n", sizeof(5 + 8LL + 'A' + 1.f));
	printf("%d\n", sizeof(5 + 8LL + 'A' + 1.f + 0.));
	/*
	强制类型转换
	*/
	printf("%d %g\n", 7 / 2, 7 / (float)2);
	printf("%d\n", sizeof(5 + (char)8LL + 'A' + (char)1.f + (short)0.));
	// 算术整数运算结果 以 int为最小处理
	printf("%d\n", sizeof((char)5 + (char)8LL + (char)'A' + (char)1.f + (char)0.));
	// 加法结果默认为int
	printf("%d\n", sizeof((char)1.f + (char)'A'));
	return 0;
}