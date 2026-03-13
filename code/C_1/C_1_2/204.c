#include <stdio.h>
/*
打印如下格式的数字
1       2       3       4       5
2       3       4       5       6
3       4       5       6       7
4       5       6       7       8
*/
int main204()
{
	int h,s;
	for(  h=1 ;h<=4 ;h=h+1 )
	{
		for(  s=h ;s<=h+4 ;s=s+1 )
		{
			printf("%i\t",s);
		}
		printf("\n"); 
	}
	return 0;
} 