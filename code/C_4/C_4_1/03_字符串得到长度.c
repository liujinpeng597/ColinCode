#include <stdio.h>
#include <string.h>
size_t my_strlen(const char* str);
int main03()
{
	/* 如何得到字符串的长度 */
	 char str1[] ="Hello";
	 char *p1 = "Hello";
	 char *p2="Hello";

	 printf("字符数组的大小:%d\n", sizeof(str1));
	 printf("字符串的长度:%d\n", strlen(str1));
	 
	/*仿真 strlen */
	 printf("字符串的长度:%d\n", my_strlen(str1));
	 return 0;
}

size_t my_strlen(const char* str)
{
	 //方式1
     /*const char* p= str;
	 int count =0;
	 while(*p!=’\0’)
	 {
		count++;
		p++;
     } 
	 */
     //方式2
	const char* p = str;
	while (*p) 
	{
		p++;
	}//编码是非0 即 真
	return p - str;//地址差就是长度
}
