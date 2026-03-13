#include<stdio.h>
// 用不同类型的指针对三维数组arr进行遍历。
//①使用能够指向一个int型变量的指针变量p指向arr数组的第一个值。然后用p 遍历arr所有元素。
int mainzy1() {
	int arr[5] = {1,2,3,4,5};
	int* p;
	p = arr;
	for (int i = 0; i < 5; i++) {
		printf("%d\n", *(p + i));
	}
	return 0;
}