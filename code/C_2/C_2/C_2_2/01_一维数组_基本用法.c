#include <stdio.h>
int main01()
{
	/*0 数组的特性：长度固定 、 同类型、 有编号  */
	int age = 18;
	int arr[15];
	/* 1 一维数组声明生成： 类型 数组名[长度]  */
	printf("%d %d\n", sizeof(int), sizeof(age));
	printf("%d %d\n", sizeof(int[15]), sizeof(arr));
	/* 2 数组元素（成员）的使用：[下标]  */
	arr[0] = 1;
	arr[1] = 3;
	arr[2] = 7;
	arr[3] = 9;
	arr[4] = 10;
	/* 3 注意事项：不要下标越界使用。  */
	//arr[5] = 8;  运行时错误

	/*int daxiao = 8;
	int aa[daxiao];*/
	int daxiao = 8;
	int aa[10000];
	/*4 循环遍历 每个成员 */
	int len = sizeof(arr) / sizeof(int);
	for (int i = 0; i < len; i++) {
		printf("%d\n", arr[i]);
	}

	return 0;
}