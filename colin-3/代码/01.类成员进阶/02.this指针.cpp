//#include<iostream>
//using namespace std;
//
//class CTest {
//public:
//	int m_a;
//	//this：关键字，也是常量指针名字。
//	//编译器 会默认添加一个隐藏this指针参数。 是指向当前类对象的指针
//	//this：用于连接对象和使用成员的桥梁，让用户无感知的使用成员。
//
//	void fun(/*CTest * const this */) {
//		cout << m_a << endl;
//		//m_a == this->m_a; //在类成员函数中，使用成员，都是通过this指针隐式的去使用的。
//	}
//
//	CTest() {
//		this->m_a = 1000;
//	}
//
//	~CTest() {
//		this->m_a = 1000;
//	}
//};
//
//void fun(CTest* const pthis) {
//	cout << pthis->m_a << endl;
//}
//
//int main() {
//	CTest t1;
//	t1.m_a = 10;
//
//	CTest t2;
//	t2.m_a = 20;
//
//	return 0;
//}