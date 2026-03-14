//#pragma once
//class Singleton {
//private:
//	Singleton() :m_a(123) {}
//	Singleton(const Singleton&) = delete;
//	~Singleton() {}
//	static Singleton sin;
//public:
//	int m_a;
//	//在多线程下,不会创建出多个实例对象。
//	static Singleton* createSingleton() {
//		return &sin;
//	}
//};