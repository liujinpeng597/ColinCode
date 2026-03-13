#include <stdio.h>
#include <stdlib.h>
typedef struct 
{
	char a;
	double b ;
	int c;
} AAA;
int main05()
{
	FILE * readFile=fopen("d:\\data.txt","rb");
	//1 读取一个整型变量
	int num;
	fread(&num, sizeof(int), 1, readFile);
	printf("%x\n", num);
	//2 读取一个数组
	int arr[100];
	int count = fread(arr, sizeof(int), 100, readFile);
	//3 读取一个字符串
	
	//4 读取一个结构体
	
	fclose(readFile);
	return 0;
}