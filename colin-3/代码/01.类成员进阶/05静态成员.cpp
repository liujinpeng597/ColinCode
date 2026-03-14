//#include<iostream>
//using namespace std;
//
///*
//静态成员属性：不属于对象之中，归属于类的，编译期存在，一个类中只会有一份，和是否定义对象无关。
//多个对象共享着同一份的静态属性。
//
//静态成员函数，同上。
//*/
//
///*
//和一般函数的区别：
//1.一般成员函数，有隐藏的this指针参数，静态成员函数没有隐藏的this指针。
////2.静态函数只能调用其他的静态成员。
//*/
//
//
//class CTest
//{
//public:
//	int m_a;
//
//	static int m_b;
//
//	CTest() :m_a(0)//,m_b(1)
//	{
//
//	}
//
//	void fun()
//	{
//		cout << m_a << endl;
//		cout << m_b << endl;
//		this->m_b;
//		CTest::m_b;
//		this->CTest::m_b;   //以上写法都正确
//	}
//
//	void fun2()
//	{
//		cout << "fun2:" << m_b << endl;
//	}
//
//	//静态成员函数
//	static void funStatic(/*无隐藏的this指针。凡是必须通过this指针使用的成员，都不能在静态成员函数内部使用*/)
//	{
//		//cout << m_a << endl;  //必须通过对象才能调用
//		//
//		//this; //this只能用于非静态函数的内部
//		cout << m_b << endl; //只能使用类中的静态成员（类外的静态也可以）。
//	}
//
//};
////名字前面加上类名作用域
///*去掉static*/ int CTest::m_b = 2;
//
//int main()
//{
//	cout << sizeof(CTest) << endl;;
//
//	cout << CTest::m_b << endl;//不需要通过对象也可以调用静态成员
//
//	CTest t1;
//
//	t1.m_b = 3;
//
//	CTest t2;
//	cout << t2.m_b << endl;  //3     如果存在了对象，也可以通过对象来调用。
//
//	CTest::funStatic();  //不通过对象调用
//
//	t2.funStatic();  //也可以通过对象调用
//
//	//CTest::m_a;  //必须通过对象调用。
//
//	//t1.fun();
//
//	CTest* ptst = nullptr;
//	//ptst->fun();  //运行时报错，因为函数内部使用了对象中的成员。
//	ptst->fun2();  //不推荐这样写， fun2: 3
//	return 0;
//}