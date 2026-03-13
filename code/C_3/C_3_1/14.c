#include <stdio.h>
unsigned getMaxIndex(double arr[],int len);
//1 规划设计——前置声明状态
//函数名用动词
/*
得到最大值到下标
参数:arr:数组首地址
	 len:数组长度
返回:下标
*/
int main14()
{
	/* 4.编写一个函数，返回double数组中最大元素的下标 */
	double a[]={1,43.3,5.3,55.6,74.8,2.5};
	int len = sizeof(a) / sizeof(a[0]);

	//2 场景·调用——验证规划设计 调用状态

	int max_index = getMaxIndex(a,len);

	printf("double数组中的最大元素下标为:%u,最大值为%g", max_index,a[max_index]);
	return 0;
}
//3 功能实现——定义状态
unsigned getMaxIndex(double arr[],int len) {

	unsigned max_index = 0;

	for (int i = 1; i < len; i++) {
		if (arr[i] > arr[max_index]) {
			max_index = i;
		}
	}
	return max_index;
}