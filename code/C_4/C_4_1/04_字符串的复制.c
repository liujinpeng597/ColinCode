#include <stdio.h>
#include <string.h>
 
int main04()
{
	/*×Ö·û´®¸´ÖÆº¯Êý*/ 
	char * p="12345";
	char a[20];
	/*strcpy*/
	strcpy(a, p);
	printf("%s\n", a);
	printf("%s\n", strcpy(a, "how are you"));
	/*strcpy_s*/
	strcpy_s(a, 20, p);
	/*strncpy*/
	strncpy(a, p, 3);
	/*strncpy_s*/
	strncpy_s(a, 20, p, 3);
	/*·ÂÕæ×Ö·û´®¸´ÖÆº¯Êý strcpy   */
	char* my_strcpy(char* dest, const char* src);
	return 0;
}
char* my_strcpy(char* dest, const char* src) {
	/*char* pd = dest;
	const char* ps = src;
	while (*ps != '\0') {
		*pd = *ps;
		ps++;
		pd++;
	}
	*pd = '\0';
	*/
	memcpy(dest, src, strlen(src) + 1);
	return dest;

}
