#include <stdio.h>

int main15(){

	int n = 0;
	int count = 0;

	printf("请输入一个整数:");
	scanf_s("%d", &n);
	while (n != 0){
		n /= 10;
		count++;
	}
	printf("你输入的数字有%d位.",count);

    return 0;
} 