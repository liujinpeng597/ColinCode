#include <stdio.h>
#include <string.h>
 
int main05 ()
{
	/*×Ö·û´®Æ´½Óº¯Êý*/ 
	char a[50]="hello ";
	char *p="hi ";
	
	/*strcat*/
	strcat(a, p);
	strcat(a, "you");
	/*strcat_s*/
	 
	/*strncat*/
	strncat(a, "ABCDE", 3);
	/*strncat_s*/

	/*·ÂÕæ×Ö·û´®Æ´½Óº¯Êý strcat  strcat_s */
	char* my_strcat(char* dest, const char* src);
	return 0;
}
char* my_strcat(char* dest, const char* src)
{
	char* p = dest + strlen(dest);
	strcpy(p, src);
	return dest;
}