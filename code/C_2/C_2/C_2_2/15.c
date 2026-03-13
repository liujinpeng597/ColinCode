#include<stdio.h>
int main15()
{
	 /* 把一组数的第一个数放到最后，其它的依次向前串 */
	int ds[] = {1,2,3,4,5,6,7,8,9};
	int i,j,t;
	int len=sizeof(ds)/sizeof(ds[0]);
	/* 方法1 */
	/*t = ds[0];
	for (i = 1; i < len; i++) {
		ds[i-1] = ds[i];
	}
	ds[len - 1] = t;*/
	/* 方法2 从第0个开始 依次和后面的数进行交换 */
	for (i = 0; i < len-1; i++) {
		t = ds[i];
		ds[i] = ds[i+1];
		ds[i+1] = t;
	}
	for (i = 0; i < len; i++) {
		printf(" % d\t", ds[i]);
	}

	return 0;
}