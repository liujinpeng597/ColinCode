#include <stdio.h>
/*
	判断一个人能否结婚：
	按法律：男年满22周岁 女年满20周岁
*/
int main205(){

	int age = 21;
	int sex = 1;

	if (sex) {
		if (age >= 22) {
			printf("男的能");
		}
		else {
			printf("男的不能");
		}
	}
	else {
		if (age >= 20) {
			printf("女的能");
		}
		else {
			printf("女的不能");
		}
	}

	return 0;
} 