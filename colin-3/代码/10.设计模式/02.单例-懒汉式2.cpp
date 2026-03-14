//#include<iostream>
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
//	Singleton() {}
//	Singleton(const Singleton&) = delete;
//	~Singleton() {}
//
//public:
//	//无法手动随时回收对象,只能等程序退出时,单例对象才会被回收掉。
//	//静态局部变量:编译器保证 在多线程下 不会创建出多个对象
//	static Singleton* createSingleton() {
//		static Singleton sin; //第一次执行到定义对象的戴拿,会真正创建。
//		//当第二次执行到定义对象的代码的时候,就不会创建对象了;
//		return &sin;
//	}
//};
//
//int main() {
//	Singleton* psin1 = Singleton::createSingleton();
//	Singleton* psin2 = Singleton::createSingleton();
//
//	cout << psin1 << "," << psin2 << endl;
//}