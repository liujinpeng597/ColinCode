#include <stdio.h>
#include <string.h>
char* my_strstr(const char* str1, const char* str2);
int main07()
{
	/*字符串匹配函数
		搜索字符串在另一个字符串中首次出现的位置。
	*/
	char* p = strstr("how are you","are");
	printf("%s\n", p);
	printf("%c\n", *p);
	printf("下标:%d\n", p - "how are you");
	printf("%s\n", strstr("how are you", "c++"));

	/*strstr*/

	/*仿真字符串匹配函数 strstr */
	return 0;
}

char* my_strstr(const char* str1, const char* str2){

	const char* p = str1;

	while (*p != '\0') {
		
		const char* pp = p;
		const char* q = str2;

		while (*pp == *q && *pp != '\0') {
			pp++;
			q++;
		}
		if (*q == '\0')return p;
		p++;
	}
	return NULL;
}
