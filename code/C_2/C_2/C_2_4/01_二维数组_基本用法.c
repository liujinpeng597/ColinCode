#include <stdio.h>
int main01()
{
	/*  */

	/*0 数组的特性：长度固定 、 同类型、 有编号（先行后列），逻辑造型：表格矩阵状  */
	int a = 5;
	int b[5] = { 0 };
	/* 1 二维数组声明生成： 类型 数组名[行数][列数]  */
	int ge[10][5];
	/* 2 二维数组 内存原理*/
	
	/* 3 数组元素（成员）的使用：数组名[先行][后列]  */
	ge[0][0] = 1;
	ge[0][3] = 2;
	ge[2][0] = 3;
	ge[2][3] = 4;
	/* 4 注意事项：不要下标越界使用。  */
	printf("数组的总字节数:%d %d\n", sizeof(ge), sizeof(int[3][4]));
	printf("数组一行的字节数:%d %d\n", sizeof(ge[0]), sizeof(int[4]));
	int hs = sizeof(ge) / sizeof(ge[0]);
	int ks = sizeof(ge[0]) / sizeof(int);
	/* 5 循环遍历 每个成员 */
	for (int i = 0; i < hs; i++) {
		for (int j = 0; j < ks ; ks++) {
			printf("%d\t", ge[i][j]);
		}
		printf("\n");
	}
	return 0;
}