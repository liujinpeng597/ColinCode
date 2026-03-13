#include <stdio.h>
/*
 找出1000以内21的倍数的数字有哪些。	
*/
int main201(){
	int count = 0;

	for (int i = 21; i <= 1000; i++) {
		if (i % 21 == 0)
		{
			printf("%d\n", i);
			count++;
		}
	}
	printf("1000以内21的倍数的数字有%d个\n", count);

	return 0;
} 