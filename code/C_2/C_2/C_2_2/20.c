#include <stdio.h>

int main20(){
	/*在一组有序的数列中，寻找一个指定的数字所在的下标*/
	int d[] = {1,5,8,12,23,44,56,78,99,200};
	int find=12;
	int left = 0;
	int right = 0;
	int len = sizeof(d) / sizeof(int);
	int mid = 0;
	for (left = 0, right = len - 1; left <= right;) {
		int mid = (left + right) / 2;
		if (d[mid] == find) {
			printf("找到了:%d\n", mid);
			break;
		}
		else if (d[mid] > find) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (!(left <= right))printf("没找到");

	return 0;
}