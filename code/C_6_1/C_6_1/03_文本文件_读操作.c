#include<stdio.h>
int main03 ()
{
	//1 读取若干个整数
	FILE* pf = fopen("d:\\myfile\\score.txt", "rt");
	//2 读取若干行文字
	if (pf != NULL)
	{
		int s = 0;
		while (!feof(pf))
		{
			fscanf(pf, "%d", &s);
			printf("%d\n", s);
		}
	 }

	
	
	return 0;
}