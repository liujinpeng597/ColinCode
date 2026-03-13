#include <stdio.h>
#include<math.h>

int isPrimeNumber(int number);
void printPrimerNumber(int begin, int end);

int main15()
{
	/* 编写函数： 判断一个数是否是素数*/
	/* 调用素数函数 打印出20以内所有的素数*/
	printPrimerNumber(1, 2000);
	return 0;
}

//判断一个数是否为素数
int isPrimeNumber(int number) {
	int flag = 1;
	for (int i = 2; i < sqrt(number); i++) {
		if (number % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

//打印出从begin到end之间的素数(包括begin和end)
void printPrimerNumber(int begin, int end) {
	for (int i = begin; i <= end; i++) {
		if (i == 1 || i == 2) {
			printf("%d ", i);
		}
		else {
			if (isPrimeNumber(i))printf("%d ", i);
		}
	}
}