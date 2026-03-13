#include"string_pro.h"
#include<ctype.h>
#include<stdlib.h>

int contains(const char* str, const char* substr)
{
	return strstr(str, substr) != NULL;
}

int startsWith(const char* str, const char* substr)
{
	return strstr(str, substr) == str;
}

int endsWith(const char* str, const char* substr)
{
	//方法1
	/*const char* p = str + (strlen(str) - strlen(substr));
	return strcmp(p,substr)==0;*/

	//方法2
	const char* p = strstr(str, substr);
	return p == NULL ? 0 : strlen(p) == strlen(substr);
}

int strIndexOf(const char* str, const char* substr)
{
	const char* p = strstr(str, substr);
	return p == NULL ? -1:p-str;
}

int charIndexOf(const char* str, char c);


int strLastIndexOf(const char* str, const char* substr)
{
	const char* p = str;
	const char* q = NULL;
	do {
		p = strstr(p, substr);
		if (p != NULL){
			q = p;
			p++;
		}
	} while (p != NULL);
	return q == NULL ? -1 : q - str;
}

int charLastIndexOf(const char* str, char c)
{
	return;
}

int isEmpty(const char* str)
{
	return strlen(str)==0;
}

char* trimAll(char* str)
{
	char* p = str;
	char* q = str;
	while (*p != '\0') {
		if (*p != '0') {
			*q = *p;
			q++;
		}
		p++;
	}
	*q = '\0';
	return str;
}

char* leftTrim(char* str)
{
	return;
}

char* rightTrim(char* str) 
{
	return;
}


char* toUpperCase(char* str) 
{
	char* p = str;
	while (*p != '0') {
		if (*p >= 'a' && *p <= 'z') {
			toupper(*p);
		}
		p++;
	}
	return str;
}

char* toLowerCase(char* str)
{
	char* p = str;
	while (*p != '0') {
		if (*p >= 'A' && *p <= 'Z') {
			tolower(*p);
		}
		p++;
	}
	return str;
}

int strcmpIgnorecase(const char* str1, const char* str2)
{
	char* p1 = (char*)malloc(strlen(str1) + 1);
	char* p2 = (char*)malloc(strlen(str2) + 1);
	strcpy(p1, str1);
	memcpy(p2, str2,strlen(str2)+1);
	toUpperCase(p1);
	toUpperCase(p2);
	int r = strcmp(p1, p2);
	free(p1);
	free(p2);
	p1 = NULL, p2 = NULL;
	return r;
}

char* reserveStr(char* str);

char* repeat(char* d, const char* s, int n);

char* substr(const char* s, int from, int to, char* d);

char* insert(char* str, const char* sub, int index)
{
	char* p = str + index;
	char* temp = (char*)malloc(strlen(p) + 1);
	strcpy(temp, p);
	*p = '\0';
	strcat(str, sub);
	strcat(str, temp);
	free(temp);
	return str;
}

char* deleteCharAt(char* str, int index);

char* deleteSubstr(char* str, int from, int to);

char* replace(char* str, int from, int to, const char* sub);

char* replaceAll(char* str, const char* oldsub, const char* newsub);
