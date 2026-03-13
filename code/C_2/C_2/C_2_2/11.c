#include <stdio.h>
int main11()
{
	/*输入5个学生年龄，并反向输出*/ 
	int hs[5];
	int i;
	for(i=0;i<5;i++)
	{
		scanf_s("%d",&hs[i]);
	}

	for(i=5-1;i>=0;i--)
	{
		printf("%d ,",hs[i]);
	}
	return 0;
}