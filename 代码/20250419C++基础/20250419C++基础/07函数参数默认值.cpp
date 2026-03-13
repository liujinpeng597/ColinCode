//#include<iostream>
//using namespace std;
//
//void fun(int a = 888)
//{
//	cout <<"fun:" << a << endl;
//}
//
//void fun2(int a = 5, int b = 20)
//{
//	cout<<"fun2:" << a << " " << b << endl;
//}
//
//void fun3(int a, int b, int c = 50)
//{
//	cout <<"fun3:" << a << " " << b << " " << c << endl;
//}
//
////函数声明和函数定义同时存在,函数参数默认值在声明处给出
////二者一般情况下不能同时给定参数默认值
//
//void fun4(int a, int b = 60);
//
//void fun5(int a, int b = 70)
//{
//	cout <<"fun5:" << a << " " << b << endl;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 15;
//	int c = 30;
//	//不传参用默认参数 传参用实参
//	fun(a);
//	fun();
//	fun2(a, b);
//	fun2();
//	fun3(a, b);
//	fun4(a);
//
//	fun5(a);
//	void fun5(int a, int b = 90);
//	fun5(a);
//	fun5(b);
//	{
//		void fun5(int a, int b = 70);
//		fun5(a);
//	}
//	return 0;
//}
//
//void fun4(int a, int b)
//{
//	cout <<"fun4:" << a << " " << b << endl;
//}
