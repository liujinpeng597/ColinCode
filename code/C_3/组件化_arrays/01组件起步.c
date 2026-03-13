#include<stdio.h>
#include<stdlib.h>
int main01()
{
	//训练函数的封装
	//1. 对排序代码进行封装 函数名为sort：要求能根据参数（升序或降序）的要求 进行数组的排序。


	//2. 对折半查找功能进行函数封装 函数名为search。


	//3. 对封装的函数分离声明与定义，形成自己的代码库文件名为（ mynamelib.h  mynamelib.c ） 。


	
	return 0;
}

/*对数组成员 按 从小到大的顺序进行排序*/
/*
	int ds[20]  ;
	int i,j,t;
	int len=sizeof(ds)/sizeof(ds[0]);
	for(i=0;i<len;i++)
	{
		ds[i]=rand()%100;
		printf("%d,",ds[i]);
	}
	printf("\n");


	for(i=0;i<len-1 ;i++)
	{
		for(j=i+1;j <len ;j++)
		{
			if( ds[i]>ds[j] ) 
			{
				t = ds[i];
				ds[i] = ds[j];
				ds[j] = t;
			}
		}
	}

*/


/*在一组有序的数列中，寻找一个指定的数字所在的下标*/
	/*int d[] = {1,5,8,12,23,44,56,78,99,200};
	int find=44;
	int i=0,j=sizeof(d)/sizeof(d[0])-1 ;
	int mid;
	do
	{
		mid=(i+j)/2;
		if(d[mid]==find)
		{
			
			break;
		}
		else if(d[mid]>find)
		{
			j=mid-1;
		}
		else if(d[mid]<find)
		{
			i=mid+1;
		}

	}while(i<=j);
	if(i<=j)
	{
		printf("%d\n",mid);
	}
	else
	{
		printf("%d\n",-mid);
	}*/

