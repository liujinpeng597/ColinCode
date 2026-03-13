//#include<iostream>
//using namespace std;
//
////参数传递: 值传递/地址传递/引用传递
////值传递:形式参数修改不了实际参数
////void fun(int a)
////{
////	a = 40;
////}
////地址传递:形式参数可以修改实际参数
//void fun(int* a)
//{
//	*a = 50;
//}
////引用传递:形式参数可以修改实际参数 一般用在复合类型传参
//void fun(int& a)
//{
//	a = 60;
//}
//
//void fun2(int a) 
//{
//	cout << "void fun2(int a)" <<endl;
//}
//
//void fun2(int& a)
//{
//	cout << "void fun2(int& a)" << endl;
//}
//
//int main()
//{
//	int a = 10;
//	int* p = &a;
//	cout << a << endl;
//	*p = 20;
//	cout << a << endl;
//
//	int& b = a;
//	b = 30;
//	cout << a << endl;
//
//	fun(a);
//	cout << a << endl;
//
//	//指针与引用的区别
//	// 
//	//指针占空间 引用不占
//	//指针可以不初始化 引用必须初始化
//	//指针可以指向空 但是没有对空的引用
//	//有多级指针 但是引用没有多级引用
//	//指针可以更换指向对象 引用不可以更换引用对象
//
//	//右值引用
//	int&& c =10;
//	cout << c << endl;
//
//	int* p3 = &a;
//	p3 = &b;
//	int& d = a;
//
//	void fun2(int& a);
//	fun2(d);
//	{
//		void fun2(int a);
//		fun2(a);
//	}
//
//	//指针的引用
//	int*& q = p3;
//	*q = 1024;
//	cout << a << endl;
//
//	//引用的指针
//	int* p4 = &b;
//	*p4 = 2048;
//	cout << a << endl;
//
//	//引用数组
//
//
//	return 0;
//}