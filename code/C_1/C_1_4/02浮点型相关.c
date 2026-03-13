/*
  知识点列表：
  1 类型关键字
  2 命名规范
  3 字面值后缀
  4 字节大小与数据范围
  5 
  6 
  7 
  8 
  9
  10 打印格式
*/
#include<stdio.h>
int main02()
{
	float fValue = .25f;
	double dValue = .25;
	long double ldValue= .25l;//标准化组织IEEE 定义了  可能被升级。
	printf("字节数：%d %d %d\n", sizeof(float), sizeof(double), sizeof(long double));
	//字面值：
	//小数方式：
	float pi = 3.1415926F;
	double pi2 = 3.1415926;
	//指数方式：
	float aa = 36e6f;//e代表10的 几次方
	double bb = 314e10;
	//打印格式
	printf("小数方式 %f %f\n", pi, aa);
	printf("指数方式 %e %e\n", pi2, bb);
	printf("最短方式 %g %g", pi, aa);
	return 0;
}