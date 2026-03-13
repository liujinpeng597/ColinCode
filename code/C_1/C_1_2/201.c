#include <stdio.h>
/*
 找出1000以内21的倍数的数字有哪些。	
*/
int main201  ()
{
	int i;
	for ( i = 0; i <=1000; i++)
	{
		if (i%21==0)
		{
			printf("%d,",i);
		}
	}
	return 0;
} 