//#include<iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int* m_p;
//
//	CTest(int a) :m_a(a), m_p(new int(123)) {}
//	~CTest()
//	{
//		if (m_p)
//		{
//			delete m_p;
//			m_p = nullptr;
//		}
//	}
//	//类中存在着默认的构造函数 和 拷贝构造函数，都是编译器给提供的函数
//	//参数：const 当前类对象的引用 形参名
//	//什么时候去调用：当同类型的一个类对象给另一个类对象做初始化的时候，自动调用。
//	//一旦手动重构了拷贝构造函数，则编译器就不会提供默认的了。
//	//函数体代码：形参对象中的成员依次给this对象做初始化
//	//浅拷贝问题：默认的拷贝构造函数是一个浅拷贝，
//	//浅拷贝，对于类中的指针成员，并没有拷贝指针对应的空间，只是拷贝了指针本身的值。
//	//解决方案：深拷贝，对于指针成员，也要申请一块属于自己空间。
//	CTest(const CTest& tt) :m_a(tt.m_a), m_p(tt.m_p)
//	{
//		if (tt.m_p)
//		{
//			this->m_p = new int(*tt.m_p);
//		}
//
//		cout << "CTest(const CTest& tt)" << endl;
//	}
//
//	//重载赋值操作，对这个=操作符，进行功能的扩展
//	//函数名：operator=,参数：const 当前类对象的引用
//	//默认是浅拷贝，对于指针成员，也会有浅拷贝的问题，
//	//解决：需要手动重构operator=,来手动实现深拷贝
//	//一旦手动重构了operator=，则编译器就不会提供默认的了。
//	CTest& operator=(const CTest& tt)
//	{
//		if (this != &tt)//判断是否是自己
//		{
//			if (tt.m_p)
//			{
//				this->m_a = tt.m_a;
//
//				if (this->m_p)
//				{
//					*this->m_p = *tt.m_p;
//				}
//				else
//				{
//					this->m_p = new int(*tt.m_p);
//				}
//			}
//			else
//			{
//				if (this->m_p)
//				{
//					delete this->m_p;
//					this->m_p = nullptr;
//				}
//			}
//
//			return*this;
//		}
//	}
//
//};
//
//void fun(CTest& t)  //函数的形参：尽量用引用或指针，尽量避免值传递
//{
//	cout << t.m_a << "   " << *t.m_p << endl;
//}
//
//CTest& fun2(CTest& t)  //函数的形参：尽量用引用或指针，尽量避免值传递
//{
//	cout << t.m_a << "   " << *t.m_p << endl;
//	return t;
//}
//
//int main()
//{
//	CTest t(1);
//	cout << t.m_a << endl;  //1
//
//	//CTest t2(t);  //匹配对应参数的构造函数
//	//cout << t2.m_a << endl;  //1
//
//	//cout << *t2.m_p << endl;
//
//	//fun2(t);
//
//	*t.m_p = 456;
//
//	CTest t3(2);
//
//	t3 = t;
//
//	cout << t3.m_a << "  " << *t3.m_p << endl;
//
//	t3 = t3;
//	return 0;
//}