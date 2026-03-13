#include <stdio.h>
#include<math.h>
int add_int(int a,int b);

int main03()
{

	/*函数名字的本质： 代表函数在内存中的地址 */
	printf("%d\n", add_int);
	printf("%d\n", add_int(10, 20));
	/*变量所代表的空间是为了存数据 */
	/*函数所代表的空间是为了执行代码 由于需要参数，需要增加() 代表执行此函数 */
	
	
	/* 定义指向函数的指针变量 就可以调用内存中的函数代码 */	 
	int (*p)(int, int);
	p = add_int;
	printf("%d\n", (*p)(100, 200));

	printf("%d\n", p(55, 66));


	/*printf("平方根 %f\n", sqrt(2));
	printf("绝对值 %f\n", fabs(-2));
	printf("棚顶 %f\n", ceil(2.99));
	printf("地板 %f\n", floor(2.0001));*/

	double(*pmath)(double) = sqrt;
	printf("平方根 %f\n", pmath(2));
	pmath = fabs;
	printf("绝对值 %f\n",pmath(-2));
	pmath = ceil;
	printf("棚顶 %f\n", pmath(2.99));
	pmath = floor;
	printf("地板 %f\n",pmath(2.0001));

	//批量执行函数
	//打包参数
	printf("--------------------------\n");
	double can[] = { 2,-2,2.99,2.001 };
	//函数指针 数组
	double(*pms[4])(double) = { sqrt, fabs, ceil, floor };
	int len = sizeof(pms) / sizeof(pms[0]);
	for (int i = 0; i < len; i++) {
		printf("%lf\n",pms[i](can[i]));
	}
	return 0;
}

int add_int(int a,int b)
{
	int sum=0;
	sum=a+b;
	return sum;
}