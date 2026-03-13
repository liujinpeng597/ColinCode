#include <stdio.h>
#include <math.h>
/*
打印n以内的所有素数
*/
int main05()
{
	int n;
	scanf_s("%d", &n);

	for (int i = 2; i <= n; i++) {
		int flag = 1;
		for (int j = 2; j < i; j++) {
			if (i % j == 0) {
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			printf("%d\n", i);
		}
	}
	return 0; 
}