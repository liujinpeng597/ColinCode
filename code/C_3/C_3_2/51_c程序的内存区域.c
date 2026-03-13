#include <stdio.h>
#include <malloc.h>
 
int* fun51()
{
	int a;
	a = 10;
	return &a;
}
int* fun52()
{
	int *p = malloc(sizeof(int));//申请一个整数空间
	if (p != NULL)*p = 50;//存入整数
	return p;//分享空间
}
int main51()
{
	///*代码区code zone · 常数区constant zone · 全局变量区global zone · 栈区stack zone · 堆区heap zone */
	//

	///*栈区*/
 //   int* p = fun52();
	//printf("%d\n", *p);
	//printf("%d\n", *p);
	//free(p);
	//p = NULL;
	///*堆区*/
	// 在堆区申请一块内存
	int* p1 = malloc(sizeof(int));
	*p1 = 3;
	/*int* pn = malloc(sizeof(int) * 5);*/
	//能申请多组变量空间
	int* pn = calloc(5, sizeof(int));
	pn[0] = 1;
	pn[1] = 5;
	pn[2] = 7;
	pn[3] = 8;
	//扩建空间 异地重建
	pn = realloc(pn, sizeof(int) * 5);
	pn[7] = 9;
	free(p1);
	free(pn);
	p1 = NULL;
	pn = NULL;
	return 0;
}
