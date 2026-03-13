#include<stdio.h>

int main()
{
	int b[][3] = { {1} ,{3, 2},{4, 5, 6},{0} };
	printf("%d", sizeof(b));
	return 0;
}