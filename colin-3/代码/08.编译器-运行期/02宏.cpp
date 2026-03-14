//#include<iostream>
//using namespace std;
//
//#include"宏.h"
//
////函数名可以加（），同名的函数和宏区分。
//int (mul)(int a, int b)
//{
//	return a * b;
//}
//
//void ff(int a)
//{
//	cout << "ff(int a)  " << a << endl;
//}
//
//void ff(char a)
//{
//	cout << "ff(char a)  " << a << endl;
//}
//
//void ff(const char* a)
//{
//	cout << "ff(const char* a)  " << a << endl;
//}
//
//
//
//int main()
//{
//	cout << A << endl;
//
//	for (int i = 0; i < A; ++i)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//
//	B
//
//		C(4)
//		C(8)
//
//		//cout << mul(3, 4) << endl;  //12
//		//cout << MUL(3, 4) << endl;  //12
//
//		//cout << mul(3, 2+2) << endl;  //12
//		//cout << MUL(3, 2+2) << endl;  //8 = 3 * 2 + 2
//
//		cout << mul(3, 4) << endl;  //默认使用宏
//
//	cout << (mul)(3, 4) << endl;
//
//	cout << D << endl;
//#undef D //取消宏定义，作用范围到此为止。
//
//	int D = 2;
//	cout << D << endl;
//
//	void f();
//	f();
//
//	ff(E(3));  //ff(const char* a)  3
//	ff(F(4));  //ff(char a)  4
//
//	ff(E("abc"));  //ff(const char* a)  "abc"
//
//	ff(F(45));  //反例
//	//'45'
//
//	G(bc)  //int a##GG=12345;
//		cout << abc << endl;
//	return 0;
//}
//
//#include"宏.h"
//
//void f()
//{
//	cout << " " << endl;
//}