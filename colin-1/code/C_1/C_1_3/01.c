#include <stdio.h>
/*
1.  题目：打印出所有的“水仙花数”，所谓“水仙花数”是指一个三位数，其各位数字立方和等于该数 
本身。例如：153是一个“水仙花数”，因为153=1的三次方＋5的三次方＋3的三次方。
*/
int main01() {

	for (int i = 100; i <= 999; i++) {

		int sum = 0;

		for (int buffer_i = i; buffer_i != 0; buffer_i /= 10) {

			int digit = buffer_i % 10;//减少计算

			if (digit == 0 || digit == 1) {//减少计算
				sum += digit;
			}
			else {
				sum += digit * digit * digit;
			}
		}
		if (sum == i)printf("%d\n", sum);
	}
	return 0;
}