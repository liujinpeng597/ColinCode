#include<stdio.h>
	//void ——无类型（不确定类型）  是一种占位符号
	//出现的位置 
	//1 参数位置——明确说明 没有参数 一般的编译器可以省略
	//2 返回类型位置——说明不需要return返回具体值 ——此处不能省略
void f1(void);

void f2()
{
		//return ;//最后一行的 return;可以省略
}
int f3(void)
{
		return 0;
}
void* f4()
{
	return NULL;
}
int mainvoid()
{

}
	//return ;//最后一行的 return;可以省略
    //返回类型不是void return不能省略  必须有明确的返回