#include <stdio.h>
//定义共用体
union aa
{
	int a ;
	char b;
} ;
int main01()
{
	//1 共用体：所有成员共享一段存储空间，但每个时间只有一个成员在使用
	union aa h;
	h.a=65;
	printf("共用体大小%d\n",sizeof(union aa));
	printf("%c\n",h.b);


	return 0;
}