#include<stdio.h>
#include<stdlib.h>
 
int main02 ()
{	 
	//1 覆盖重写模式
	FILE* pf = fopen("d:\\myflie\\data.txt","wt");
	if (pf != NULL)
	{
		//向屏幕打印
		printf("北京时间%d:%d %.2f %s\n", 2, 3, 3.1415, "beijing");
		putchar('A');
		puts("hello world.");
		//向打印
		fprintf("北京时间%d:%d %.2f %s\n", 2, 3, 3.1415, "beijing");
		fputchar('A',pf);
		fputs("hello world.",pf);
		fclose(pf);
		pf = NULL;
	}
	//2 打开追加模式


	//3 读写混合方式
	return 0;
}