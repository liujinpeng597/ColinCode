//#pragma once
///*
//使用场景
//头文件（A.h）:变量的声明 函数的声明 类的定义
//源文件（A.cpp）:变量 函数的定义 类成员的定义实现等
//
//头文件：单独的头文件不参与编译
//源文件: 自上而下的独立进行编译
//*/
//
////int a;//定义未初始化 如果在头文件中定义变量的话 这头文件被多个源文件包含的的话 重定义错误
//extern int a;//声明 extern声明关键字
//
//void fun();
//
////静态变量 可以放在头文件中定义 是具有文件作用域的
//static int b = 3;
//
////类成员函数在类外源文件中,定义,一定要加上类名作用域
//class A {
//public:
//	int m_a;
//	A();
//	~A();
//	void funConst() const;
//	static void funStatic();
//	virtual void funVirtual();
//
//	static int m_b; 
//};