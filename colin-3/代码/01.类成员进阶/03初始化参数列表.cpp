//#include<iostream>
//using namespace std;
//
//class CTest {
//public:
//	int m_a = 10; //默认初始化
//	const int m_b = 20;
//	int arr[10];
//
//	CTest() :m_b(2), m_a(1), arr{0} {
//		for (int i = 0; i < 10; ++i) {
//			arr[i] = i;
//		}
//	}
//	//初始化参数列表,初始化成员的顺序：取决于成员在类中声明的先后顺序。
//	//和初始化参数列表的顺序无关。
//	CTest(int aa): m_a(aa),m_b(m_a) {
//	}
//	
//};