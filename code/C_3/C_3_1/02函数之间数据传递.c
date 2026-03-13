#include <stdio.h>
int add(int a, int b);
int add_all(int a[]);
void exchange(int a, int b);
void swap(int* p, int* q);
int main02()
{

	/*函数的前置声明*/

	/*函数的执行原理：调用时执行，执行完消失*/
	int he = add(5, 3);
	printf("%d\n", he);
	printf("%d %d\n", add(23,56),add(102,204));
    int arr[] = { 8,5,1,7 };
	printf("%d\n", add_all_2(&arr));

	//交换
	int n = 3, m = 4;
	printf("m=%d n=%d\n", m, n); 
	void exchange(int n, int m);
    //调用前 声明exchange(n,m);printf("m=%d n=%d\n",m, n);
	swap(&n, &m);
	printf("m=%d n=%d\n", m, n);
	
	/*函数的数据（值）传递为：copy（复制）方式 */

	/*自定义头文件*/
	
	return 0;
}
int add(int a,int b)
{
	int sum=0;
	sum=a+b;
	return sum;
}

int add_all(int a[] )
{
	int sum=0;
	int len=sizeof(a)/sizeof(a[0]);
	int i;
	for(i=0;i<len;i++)
	{
		sum+=a[i];
	}
	return sum;
}

//数组的指针
int add_all_2(int(*a)[4])
{
	int sum = 0;
	int i;
	for (i = 0; i < 4; i++)
	{
		sum += (*a)[i];
	}
	return sum;
}

void exchange(int a,int b)
{
	 int n = 3, m = 4;
	 printf("m=%d n=%d\n", m, n);
	 int t;
	 t = n; n = m; m = t;
	 printf("m=%d n=%d\n", m, n);
	 return;
}

void swap(int*n,int *m)
{
	int t;
	return 0;
	t = *n; *n = *m; *m = t;
}