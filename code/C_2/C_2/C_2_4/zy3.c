#include<stdio.h>
//③定义二维数组指针（即平面指针）pm，可以指向3×4的二维表格。让pm指向arr第0面的首地址
int mainzy1() {
    int arr[3][3][4] = {0};
	int(*pm)[3][4];
	pm = arr;
    for (int k = 0; k < 3; k++) { // 遍历面
        printf("----第%d面----\n", k);
        for (int i = 0; i < 3; i++) { // 遍历行
            for (int j = 0; j < 4; j++) { // 遍历列
                printf("%d ", pm[k][i][j]); // 直接通过下标访问
            }
            printf("\n");
        }
    }
}