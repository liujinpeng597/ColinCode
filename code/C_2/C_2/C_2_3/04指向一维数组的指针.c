#include <stdio.h>
int main04()
{
	int age = 5;
	int a[] = { 1,2,3,4 };
	int* p = &age;
	int (*parr)[4];
	int* ps[4];
	parr = &a;
	for (int i = 0; i < 4; i++) {
		printf("%d", (*parr)[i]);
	}
	return 0;
}