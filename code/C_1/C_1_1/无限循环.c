#include<stdio.h>

int main()
{
	//1
flag:
	printf("为人民服务！");
	goto flag;

	//2
	for (;;)
	{
		printf("为人民服务！");
	}

	//3
	while(1) 
	{
		printf("为人民服务！");
	}
	//4
	do {
		printf("为人民服务！");
	} while (1);

	return 0;
}