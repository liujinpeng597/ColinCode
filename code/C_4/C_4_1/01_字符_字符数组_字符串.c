#include <stdio.h>
void prints(char str[]);
int main01()
{
	/*字符显示的原理*/
	 
	/*字符数组 与 \0*/
	char arr[5] = { 'A',65,'\101','\x41','\0' };
	printf("%s", arr);
	/*字符串*/
	char str[] = "hello";
	printf("%s\n", str);
	printf("字符串str的长度是%d", sizeof(str) / sizeof(char));
	/* 仿真 %s 封装函数 */
	prints(str);
	prints(arr);

	return 0;
}
//  %c
void prints(char str[])
{
    //1下标方式
    //for ( int i=0; str[i]!='\0';i++ )
    //{
    //	printf("%c",str[i]);
    //}
  
  //2 指针方式
	char* p = str;//指向str数组的第一个元素
	while (*p != '\0')//如果*p不等于\0
	{
		//打印指向地址内容
		printf("%c", *p);
		//指针移动
		p++;
	}
	printf("\n");
}