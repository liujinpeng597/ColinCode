//#include<iostream>
//#include"03.单例-饿汉式.h"
//using namespace std;
//
///*
//单例懒汉式:当调用创建单例的接口的时候,再创建这个唯一实例。(先用现搞)
//单例饿汉式:当程序创建的时候，这个唯一的实例就一起创建了。(先搞预用)
//*/
//
////相较于第一种方法 第一种可以主动回收对象  本种无法中途回收 只能在程序结束的时候回收
//
//class Singleton {
//private:
//	Singleton():m_a(123) {}
//	Singleton(const Singleton&) = delete;
//	~Singleton() {}
//
//	static Singleton sin;
//public:
//	int m_a;
//
//	//在多线程下,不会创建出多个实例对象。
//	static Singleton* createSingleton() {
//		return &sin;
//	}
//};
//
//Singleton Singleton::sin;
//
//int a1 = Singleton::createSingleton()->m_a;
//
//int a2 = Singleton::createSingleton()->m_a;
//
//int main() {
//	Singleton* psin1 = Singleton::createSingleton();
//	Singleton* psin2 = Singleton::createSingleton();
//
//	cout << psin1 << "," << psin2 << endl;
//
//	cout << a1 << "   " << a2 << endl;
//}