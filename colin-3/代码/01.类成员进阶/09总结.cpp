//#include<iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	/*CTest(const CTest&){}*/
//	int m_a;
//	int* m_p;
//
//	//可以发生隐式转换，将其他类型（整型）转换为当前对象。
//	//explicit 修饰构造函数，禁止发生隐式类型转换
//	explicit CTest(int a) :m_a(a), m_p(new int(100)) {}
//	~CTest()
//	{
//		if (m_p)
//		{
//			delete m_p;
//			m_p = nullptr;
//		}
//	}
//
//	CTest& operator=(/*  CTest* const this,  */const CTest& tt)
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
//};
//
//int main()
//{
//	//CTest t;  //匹配默认的无参构造函数,如果手动重构了拷贝构造函数，默认无参构造就不会提供了
//	//CTest t2(t);  //默认拷贝构造函数是给提供的
//
//	//类中会提供哪些默认的函数
//	//默认无参构造函数，析构函数，拷贝构造函数，默认的operator=，考虑移动语义，移动构造，移动赋值
//	//-------------------------------
//
//	CTest t3(12);
//
//	/*t3 = 123; *///通过123匹配对应的构造函数，构建出来一个临时的对象，t3=CTest(123); 
//	//再匹配operator=，将临时对象给this做赋值操作
//
//	t3 = CTest(123); //explicit,将问题给暴露出来
//
//	cout << t3.m_a << endl;
//	return 0;
//}