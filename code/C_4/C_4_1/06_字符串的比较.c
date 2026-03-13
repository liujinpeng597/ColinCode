#include <stdio.h>
#include <string.h>
#include <math.h>
int my_strcmp(const char* str1, const char* str2);
int main06()
{
	/*字符串比较函数*/

	/*strcmp*/
	printf("%d\n", my_strcmp("ABCD", "abcd"));//前大于后输出-1
	printf("%d\n", my_strcmp("abcd", "ABCD"));//前小于后输出1
	printf("%d\n", my_strcmp("abcd", "abcd"));//前后
	printf("%d\n", stricmp("AbcD", "abcd"));
	/*仿真字符串比较函数 strcmp */
	return 0;
}

int my_strcmp(const char* str1, const char* str2)
{
	char* p = str1;
	char* q = str2;
	while (*p == *q && *p != 0) {
		p++;
		q++;
	}
	int cha = *p - *q;
	return cha == 0?0:cha/abs(cha);
}
