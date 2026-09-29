#include<stdio.h>

int main() {
	printf("hello world\n");
	;//空语句
	{//复合语句--多条语句表达一个逻辑
		{
			//1哲学三问
			printf("我是谁?\n");
			printf("我从哪里来?\n");
			printf("我要到哪里去?\n");
		}
	}
	return 0;
}