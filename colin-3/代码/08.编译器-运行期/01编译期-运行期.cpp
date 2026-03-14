//#include<iostream>
//using namespace std;
//
///*
//编译期: 将源代码交给编译器编译生成可执行程序的过程
//
//运行期:将可执行程序交给操作系统，直到程序退出的过程
//
//class 类:类成员函数,静态成员属性,虚函数列表,访问修饰符, 作用域
//
//对象:一般的成员属性,
//*/
//
//class AA {
//private:
//	void ff() {
//		cout << "AA::ff" << endl;
//	}
//public:
//	void fun() {
//		cout << "A::fun" << endl;
//	}
//};
//
//int main() {
//
//#if __cplusplus
//
//#define A 10
//
//#else
//
//#define A 20
//
//#endif
//
//	int B = A; // B的初始值 编译期就可以确定了
//	//等效于: int B =10;
//	cout << B << endl;
//
//	int b = 0;
//	int a = 0;
//
//	if (a > 100) { // 运行期 才能确定b'的最终值
//		b = 200;
//	}
//	else {
//		b = 100;
//	}
//	cout << b << endl;
//
//	//----------------
//
//	int len = 10;
//	const int ll = 20;
//
//	int arr[ll];//在vs中 静态数组在编译期确定大小
//
//	int * parr = new int[len];
//	//int arr[len]; // 编译期错误
//	//parr[10000] = 123;
//
//	AA aa;
//	aa.AA::fun(); //fun所属的作用域,是编译期描述的概念。
//	//运行期 0x 地址
//	return 0;
//}