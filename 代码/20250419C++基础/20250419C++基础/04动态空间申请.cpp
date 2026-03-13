//#include<iostream>
//using namespace std;
//
////   malloc/free              new/delete
////(1)函数                   / 关键字
////(2)计算申请空间大小       / 不需要计算申请空间大小
////(3)不能申请同时初始化     / 能
////(4)不会调用构造和析构函数 / 会
//int main()
//{
//	int a[5] = { 1,2,3,4 };
//	int n = 10;
//	int* p = (int*)malloc(sizeof(int) * n);
//	for (int i = 0; i < n; i++)
//	{
//		p[i] = i;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << p[i] << "";
//	}
//	cout << endl;
//	free(p);
//	p = nullptr;
//
//	int* p2 = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		p2[i] = i;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		cout << p2[i] << "";
//	}
//	cout << endl;
//	delete[]p2;
//	p2 = nullptr;
//
//	//申请同时初始化
//	int* p3 = new int(10);
//	cout << *p3 << endl;
//	delete p3;
//	p3 = nullptr;
//
//	int* p4 = new int[4] {6, 7, 8, 9};
//	for (int i = 0; i < 4; i++)
//	{
//		cout << p4[i] << "";
//	}
//	cout << endl;
//	delete[]p4;
//	p4 = nullptr;
//
//    //申请指针
//	int m = 1024;
//	int** p5 = new int*;
//	*p5 = &m;
//	cout << **p5 << endl;
//	delete p5;
//	p5 = nullptr;
//
//	//指针数组
//	int** p6 = new int* [5];
//	delete[]p6;
//	p6 = nullptr;
//
//	//数组指针
//	int(**p7)[5] = new(int(*)[5]);
//	delete p7;
//	p7 = nullptr;
//
//	return 0;
//}