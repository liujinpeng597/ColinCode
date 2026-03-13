#include <stdio.h>
int main02()
{
	/* 一维数组 在 声明的同时 直接初始化赋值  */

	/* 1  完全初始化  */
	int a[4] = { 1,3,5,7 };
	/* 2 不完全初始化、其它成员默认 0     */
	int b[4] = { 1,3 };
	int c[4] = { 0 };
	int d[4] = { -1 };
	for (int i = 0; i < sizeof(d) / sizeof(int); i++) {
		printf("%d\n", d[i]);
	}
	/* 3 初始化成员个数 自动决定长度  */
	int e[] = { 1,2,3,4,5,6,7,8,9,10 };
	/*4 循环遍历 每个成员 */


	return 0;
}