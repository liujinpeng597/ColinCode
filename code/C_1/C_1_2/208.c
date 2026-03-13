#include <stdio.h>
/*
打印如下图形
    *
   ***
  *****
 *******
*********
*/
int main208()
{
	int h,k,o;
	for( h=1 ;h<=5 ; h=h+1)
	{
		//打印空格
		for( k=1 ;k<=5-h ;k++ )
		{
			printf(" ");
		}
		//打印*
		for( o=1 ;o<=2*h-1 ;o++ )
		{
			printf("*");
		}
		//换行
		printf("\n");
	} 
	return 0;
} 