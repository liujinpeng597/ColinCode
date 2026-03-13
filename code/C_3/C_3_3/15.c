#include <stdio.h>
int fun15(int a[],int begin,int end);
int main15  ()
{

	/* 递归判断是否回文数组*/
	int a[]={1,2,4,2,1};
	if (fun15(a,0,sizeof(a)/sizeof(a[0])-1))
	{
		printf("是回文数组\n");
	}
	else
	{
		printf("不是回文数组\n");
	}

	return 0;
}

int fun15(int a[],int begin,int end)
{
	 
	 return 0;
	 
}