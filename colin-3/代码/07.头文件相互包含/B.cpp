//#include<iostream>
//#include "B.h"
//#include"A.h"//一定要在源文件中包含
//using namespace std;
//
//B::B() :/*m_pa(nullptr)*/m_pa(new A) {
//	//m_pa = new A; //异常
//} //不能在构造函数里创建对象,否则相互调用，程序异常
//
//void B::CreateA() {
//	//m_pa = new A;
//}
//
//void B::useA(A a) {//需要A的定义，必须包含头文件
//	cout << "a.m_a:" << a.m_a << endl;
//}