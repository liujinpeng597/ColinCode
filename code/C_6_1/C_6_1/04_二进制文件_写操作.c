#include <stdio.h>
#include <string.h>

int main04   ()
{
	FILE * writeFile=fopen("d:\\data.txt","wb");
	//1 存储一个整型变量
	int n = 0x61626364;
	fwrite(&n, sizeof(int), 1, writeFile);
	//2 存储一个数组
	int arr[5] = { 65,97,48,10,66 };
	fwrite(arr, sizeof(int), 5, writeFile);
	fwrite(arr, sizeof(int[5]), 1, writeFile);
	//3 存储一个字符串
	 
	//4 存储一个结构体
	 
	fclose(writeFile);
	return 0;
}