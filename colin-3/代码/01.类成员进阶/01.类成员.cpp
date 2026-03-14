//#include<iostream>
//using namespace std;
//
///*
//成员属性:归属于对象，当定义对象的时候，才会存在(申请空间)
//定义多份对象，就会有多份的成员属性，彼此独立互不干扰
//
//成员函数:占用的不是对象的内存空间,归属于类的。编译期就存在了。一个类中只会存在一份,
//和是否定义对象无关。但是多个对象是共享着同一份的函数。
//*/
//
//class A {
//public:
//	int m_a;
//
//	void fun() {
//		cout << "fun" << endl;
//	}
//};
//int main() {
//	//cout<<sizeof(A)<<endl; // siziof(A) == 1,用于判定如果要使用A类定义对象的话，应该占用多大空间
//	//1 表示的是占位的作用，用来标识当前对象真实的存在于内存空间中。
//	//sizeof（int）
//	cout << sizeof(A) << endl;
//
//	A a;
//	a.m_a = 10;
//
//	A b;
//	b.m_a = 20;
//
//	//cout << &a.m_a << " " << a.m_a << endl;
//
//	//cout << &b.m_a << " " << b.m_a << endl;
//
//	cout << sizeof(A) << endl; // 4
//
//	a.fun();
//	b.fun();
//
//	//&a.fun;
//
//	printf("%p", &A::fun); // 打印函数地址
//	return 0;
//}