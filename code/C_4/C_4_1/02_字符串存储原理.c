#include <stdio.h>
int main02()
{
	/*用debug调试观察变量信息 总结：字符数组与字符指针对字符串处理的区别*/
	 char str1[] ="Hello";
	 char const *p1 = "Hello";
	 char const *p2="Hello";
	 
	 str1[0]='h';
	 /*p1[0]='h';
	 p2[0]='h';*/
     //str1 = "world";
	 p1 = "world";
	 p2 = "world";

	 printf("%s\n", "Hello" + 3);
	 printf("%c\n", "Hello"[2]);

	

	 return 0;
}