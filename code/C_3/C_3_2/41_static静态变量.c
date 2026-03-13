#include <stdio.h>
void fun41()
{
	static int c;
	int i;
	i=10;
	i++;
	c++;
	
	printf("c=%d,i=%d\n",c,i);
}
int main41()
{
	/*static 理解为局部内的 唯一变量 相当于全局，但全局不可访问  */
	fun41();
	fun41();
	return 0;
}
