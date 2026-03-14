//#include<iostream>
//using namespace std;
//
//void fun(int a){
//	cout << "fun(int)" << a << endl;
//}
//
//class A {
//public:
//	void fun(int a) {
//		//有this指针
//		cout << "fun(int)" << a << endl;
//	}
//};
//
///*
//区别：
//1.类成员函数有隐藏的this指针参数,全局函数没有。
//2.属于某个类的作用域限制。全局函数属于全局作用域。
//3.
//*/
//
//int main() {
//	fun(10);//直接通过名字使用
//	//通过函数指针解耦，方便灵活使用
//	//void(*p_fun)(int) = &fun;//定义函数指针,并指向函数
//
//	typedef void (*P_FUN)(int);
//	P_FUN p_fun = &fun;
//
//	(*p_fun)(20);
//
//	A a;
//	a.fun(30);//直接通过名字调用
//	
//	//定义类成员函数指针， ::*是C++中一个整体操作符
//	void (A::*p_fun2)(int) = &A::fun;
//    
//	(a.*p_fun2)(40);//.*是C++中的一个整体操作符，通过对象调用类成员函数指针指向的函数
//
//	A* pa = &a;
//	(pa->*p_fun2)(50);
//	return 0;
//
//}