//#include<iostream>
//using namespace std;
//
////函数重载
////1.数据类型不同
////2.参数数量不同
////3.参数顺序不同
////4.int* 与 const int*可以重载
////注意!!!
////1.返回类型不同无法重载
////2.int 与 const int无法重载
//void fun(int a)
//{
//	cout << "void fun(int a)" << endl;
//}
//
//void fun(char a)
//{
//	cout << "void fun(char a)" << endl;
//}
//
//void fun(int a, int b)
//{
//	cout << "fun(int a, int b)" << endl;
//}
//
//void fun(int a, char b)
//{
//	cout << "fun(int a, char b)" << endl;
//}
//
//void fun(char a, int b)
//{
//	cout << "fun(char a, int b)" << endl;
//}
//
////------------------------------
////int 与 const int
//void fun2(int a)
//{
//	cout << "fun2(int a)" << endl;
//}
//
////void fun2(const int a)//函数"void fun2(int)已有主体"
////{
////	cout << "fun2(const int a)" << endl;
////}
//
////------------------------------
////int* 与 const int*可以构成重载
//void fun3(int* p)
//{
//	cout << "void fun3(int* p)" << endl;
//}
//
//void fun3(const int* p)
//{
//	cout << "void fun3(const int* p)" << endl;
//}
//
////--------------------------------
//
//void fun4(int a[])
//{
//	cout << "void fun4(int* a)" << endl;
//}
//
//void fun4();
//
//void fun5(int a)
//{
//	cout << "void fun5(int a)" << endl;
//}
//
//void fun5(int a, int b = 999)
//{
//	cout << "void fun5(int a,int b = 999)" << endl;
//}
//
//int main()
//{
//	int a = 10;
//	fun(a);
//	char b = 'b';
//	fun(b);
//	int c = 20;
//	fun(a, c);
//
//	fun(a, b);
//	fun(b, a);
//
//	fun2(a);
//
//	fun3(&a);
//
//
//	void fun5(int a);
//	fun5(a);
//	return 0;
//}