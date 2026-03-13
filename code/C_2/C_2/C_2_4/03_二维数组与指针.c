#include <stdio.h>
int main03()
{
	/* 0.二维数组在内存中的存储形态 */
	int arr[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	/* 1.用int指针遍历数组元素,证明二维数组在内存中是连续的 */
	//int* p = &arr[0][0];
	//for (int i = 0; i < 3 * 4; i++)
	//{
	//	printf("%p %d\n", p, *p);
	//	p++;
	//}
	///* 2.数组名的用法*/
	//	//A：得到 某行的首地址
	//printf("%d %d %d\n", arr, arr + 1, arr + 2);
	//	//B：得到 某行的存储空间
	//printf("%d %d %d\n", sizeof(*arr), sizeof(*(arr + 1)), sizeof(*(arr + 2)));
	//	//C：得到某行内--某列的地址
	//printf("%d %d %d\n", *(arr + 1), *(arr + 1) + 1, *(arr + 1) + 2);
	//printf("%d %d %d\n", arr[1], arr[1] + 1, arr[1] + 2);
	//	//D：得到某行 某列的存储空间
	//printf("%d %d %d\n", *(arr[1] + 0), *(*(arr + 1) + 1), * (*(arr + 1) + 2));
	//printf("%d %d %d\n", arr[1][0], arr[1][1], arr[1][2]);
	//	//E：跨度整个二维数组 
	 
	/*3 . 利用指向一维数组的指针 遍历每一行的首地址*/
	int(*ph)[4] = arr;
	/*4 . 利用指向一维数组的指针 遍历每一行 每一个元素成员*/
	printf("%d %d %d %dn", **ph ,(*ph)[1], (*ph)[2], *(*ph + 3));
	//ph指向arr数组的第一个元素{1,2,3,4} 且ph是指针
	// 
	//*ph得到arr[0]
	ph++;

	/*5 . 利用指向二维数组的指针 遍历每一行 每一个元素成员*/
	int(*pge)[3][4] = &arr;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%d %d %d %d", arr[i][j], (*(arr + i) + j), (*pge)[i][j], *(* (*pge + i)  + j));
		}
	}
	 
	return 0;
}