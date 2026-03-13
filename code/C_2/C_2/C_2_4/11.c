#include <stdio.h>
int main11()
{
	/* Ñî»ÔÈý½Ç
		1
		11
		121
		1331
		14641
	*/
	int a[10][10]={{1},{1,1}};
	for (int i = 2; i < 10; i++) 
	{
		for (int j = 0; j <= i; j++) 
		{
			if (j == 0 || j == i) 
			{
				a[i][j] = 1;
			}
			else {
				a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}