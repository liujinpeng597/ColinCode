//#include"A.h"
//#include<iostream>
//using namespace std;
//
//int a = 1;//定义及初始化
//
//void fun() {
//	cout << "fun" << endl;
//}
//
//static int d = 123;
//int* p = &d;
//
//A::A():m_a(4){
//	cout << "A" << endl;
//}
//A::~A(){
//	cout << "~A" << endl;
//}
//
//void A::funConst()const {
//	cout << "funConst" << endl;
//}
//
//void A::funStatic() {
//	cout << "funStatic" << endl;
//}
//
//void A::funVirtual() {
//	cout << "funVirtual" << endl;
//}
//
//int A::m_b = 5;
//
////多个文件互通的,编译器具有判重机制。
//class B{
//public:
//	int m_a = 123;
//};
//
//void fun11() {
//	B b;
//	cout << b.m_a << endl;
//}