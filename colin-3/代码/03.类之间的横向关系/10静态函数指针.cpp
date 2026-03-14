//#include<iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	//和全局函数一样，通过一般函数指针就可以调用
//	static void funStatic()
//	{
//		cout << "CTest::funStatic" << endl;
//	}
//
//	void funConst(  /*  const CTest* const this   */)const
//	{
//		cout << "CTest::funConst" << endl;
//	}
//};
//
//int main()
//{
//	void (*p_fun)() = &CTest::funStatic;
//	(*p_fun)();  //CTest::funStatic
//
//	void (CTest:: * p_fun2)()const = &CTest::funConst;
//
//	CTest t;
//	(t.*p_fun2)();  //CTest::funConst
//
//	//类成员属性指针，并不是说变量的地址，存储的是偏移量。
//	return 0;
//}