/*
  知识点列表：
  1 类型关键字
  2 命名规范
  3 字面值后缀
  4 字节大小与数据范围
  5 溢出现象
  6 进制转换
  7 内存存储原理：原码 补码 反码
  8 左值 右值
  9 八进制 十六进制字面值
  10 打印格式
*/
#include<stdio.h>
#include<math.h>
int main01()
{
	/*int iValue = 9;
	unsigned int uiValue=9u;
	printf("signed int字节数：%d %d %d\n", sizeof(int), sizeof(iValue), sizeof(9));
	printf("unsigned int 字节数：%d %d %d\n", sizeof(unsigned), sizeof(uiValue), sizeof(9u));

	long int lValue = 9l;
	unsigned long int ulValue=95ul;
	printf("signed long int 字节数：%d %d %d\n", sizeof(long), sizeof(lValue), sizeof(9L));

	long long int llValue = 95ll;
	unsigned long long int ullValue = 95ull;
	printf("signed long long int 字节数：%d %d %d\n", sizeof(long long), sizeof(llValue), sizeof(9LL));

	short int sValue=9;
	unsigned short int usValue=9u;
	printf("signed short int 字节数：%d %d %d\n", sizeof(short), sizeof(sValue), sizeof(9));

	signed char  cValue = 'A';
	unsigned char ucValue=48u;
	printf("signed char字节数：%d %d %d\n", sizeof(char), sizeof(cValue), sizeof('A'));*/

	//101100; // 十进制
	//0b1011011; // 二进制
	//0356; // 八进制
	//0x2fb; // 十六进制
	//0xAABBCCDDULL;

	//printf("%d %o %x", 185, 185, 185);

	//unsigned char n = -1;// 1(非符号位) 111 1111 256/2
	//char m = -1;// 1(符号位)111 1111 -1/2
	//printf("%hhd %hhd", n/2, m/2);

		//利用溢出现象 计算数据范围
	unsigned char a = -1;
	//char n = -1;
	printf("%hhd %hhd %hhu\n", a / 2, a / 2 + 1, a / 2 + 1);
	unsigned short b = 0xffff;
	printf("%hd %hd\n", b / 2, b / 2 + 1);

	unsigned int c = -1;
	printf("%d %d\n", c / 2, c / 2 + 1);

	unsigned long long d = -1;
	printf("%lld %lld\n", d / 2, d / 2 + 1);

	return 0;
}