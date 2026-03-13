#include <stdio.h>
/*定义一个结构体*/
//结构体位域 应用于嵌入式领域居多
typedef struct  
{
	 int a:2;//a变量占两个位的存储空间 但int会分配4个字节。
	 int b:8;
	 int c:2;
	 int :0;//断开
	 int d:2;

}  TT;
 
int main07()
{
	TT t ;
	 
	printf("%d\n",sizeof(TT));
	t.a = 9;
	printf("%d\n", t.a);

	return 0;
}