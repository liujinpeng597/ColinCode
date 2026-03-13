#include <stdio.h>

int getFactor(int n,int *a);

int main16(){
	/*编写函数:把一个正整数的所有因数存放到一个数组里并返回因数的个数*/
	int n = 100;
	int a[100];

	int count = getFactor(n, a);
	for (int i = 0; i < count; i++) {
		printf("%d ", a[i]);
	}
	printf("\n正整数%d的因数有%d个\n", n, count);
	system("pause");
	return 0;
}

int getFactor(int n, int *a) {
	a[0] = 1;
	int len = 1;
	for (int i = 2; i <= n/2; i++) {
		if (n % i == 0) {
			a[len++] = i;
		}
	}
	a[len] = n;
	return len;
}