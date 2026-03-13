#include<stdio.h>
//创建一个可以保留6名篮球队员身高（cm）的数组。
// 要求6名球员身高从键盘输入；找出最高值、最低值、平均值并打印出来。
int mainzy() {
	int height[6] = { 0 };
	int sum = 0;

	for (int i = 0; i < 6; i++) {
		scanf_s("%d", &height[i]);
		sum += height[i];
	}
	int max = height[0];
	int min = height[0];
	for (int i = 0; i < 6; i++) {
		if (height[i] > max) {
			max = height[i];
		}
		else if (height[i] < min) {
			min = height[i];
		}
	}
	printf("max:%d,min:%d,ave:%d", max, min, sum / 6);
}