#include <stdio.h>

int main13(){

	int choice;

	scanf_s("%d",&choice);
	switch (choice){
	case 1:
		printf("自我实现");
		break;
	case 2:
	    printf("尊重需求");
		break;
	case 3:
		printf("社会需求");
		break;
	case 4:
		printf("安全需求");
		break;
	case 5:
		printf("生理需求");
		break;
	}

	return 0;
} 