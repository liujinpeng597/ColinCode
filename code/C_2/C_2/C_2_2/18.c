#include<stdio.h>
#include<stdlib.h>
int main18(){
	int ds[20];
	int i, j;
	int len = sizeof(ds) / sizeof(ds[0]);

	for(i=0;i<len;i++){
		ds[i]=rand()%100;
		printf("%d,",ds[i]);
	}
	printf("\n");
	/*对数组成员 按 从小到大的顺序进行排序*/
	for (int i = 0; i < len - 1; i++) {
		for (int j = i + 1; j < len; j++) {
			if (ds[j] < ds[i]) {
				int temp = ds[j];
				ds[j] = ds[i];
				ds[i] = temp;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		printf("%d ", ds[i]);
	}

	return 0;
}