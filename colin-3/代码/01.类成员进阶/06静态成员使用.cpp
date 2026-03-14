//#include<iostream>
//using namespace std;
//
///*
//统计当前类实例化对象的数量。
//*/
//
//class CTest
//{
//public:
//	static int m_count;  //用于统计对象的数量
//
//	CTest()
//	{
//		m_count++;
//	}
//	~CTest()
//	{
//		--m_count;
//	}
//
//};
//
//int CTest::m_count = 0;
//
//CTest t1;  //全局的对象，静态全局区。 在主函数之前，随着程序创建一起就创建了。程序结束退出的时候就销毁。
//
//int main()
//{
//	cout << CTest::m_count << endl; //1
//
//	CTest t2;  //函数内部局部的对象, 栈区，函数返回的时候销毁
//	cout << CTest::m_count << endl; //2
//
//	const CTest t3;  //栈区，函数返回的时候销毁
//	cout << CTest::m_count << endl; //3
//
//	CTest* ptst = new CTest;  //堆区
//	cout << CTest::m_count << endl; //4
//
//	delete ptst;  //delete手动释放的时候，生命周期结束
//	cout << CTest::m_count << endl; //3
//
//	//临时对象，匿名的对象，生命周期仅限于当前这一行。
//	CTest();  //调用构造函数创建临时对象
//	return 0;
//}