//#include<iostream>
//using namespace std;
//
//class CTest {
//public:
//	mutable int m_a; //修饰成员属性:在常成员函数中,m_a可变的;
//	const int m_b;
//
//	int m_c;
//	//const修饰对象，意味着不能改对象本身，不能改生效的时机
//	//调用构造函数完毕后，彻底初始化完毕对象后，const才会生效
//	//常成员函数，不能修改对象的状态。构造函数将对象状态从无效变为有效
//
//
//	CTest():m_a(1),m_b(2){
//		m_c = 300;
//	}
//	//此时const失效 修改了对象的状态，从有效变为无效
//	~CTest() {
//		m_c = 400;
//	}
//
//
//	void fun(/* CTest * const this*/) {
//		cout << m_a << " " << m_b << endl;
//		m_a = 10;
//	}
//	//类中的特殊函数之一。常成员函数，this指针的类型是双重const修饰的。
//	//我们不能通过this指针，去修改他指向的对象
//
//	//修饰返回值
//	//const int funConst() {}
//
//	//常成员函数无法修改变量
//	void funConst(/*const CTest *const this*/) const {
//		cout << m_a << " " << m_b << endl;
//		//m_a = 10; // 即使是一个变量，在常成员函数中，也不能修改。
//		//通过this指针去修改成员。
//		//this->m_a = 10;
//
//		//1.通过其他指针修改
//		int* p = (int*)&this->m_a;
//		*p = 20;
//
//		//2.正规手段,mutable
//		this->m_a = 30;
//
//	}
//};
//
//
//int main() {
//	CTest t;
//	t.funConst();
//
//	cout << t.m_a << endl; // 30
//
//	const int a = 0;
//	int b = 1;
//
//	//常量指针
//	const int* p = &b; // const： 修饰的是 修饰的是指针p指向的变量
//	//*p = 100； error
//	p = &a; // ok
//
//	int* const p2 = &b; //const : 修饰的是 p2指针本身， 他的指向不能改变。
//	//可以修改 指针指向变量的值
//	//p2 = &b; //error
//	*p2 = 200;
//
//	int* p3 = &b;
//
//	//p3 = p; //是指针的安全级别降级的操作
//	
//	p = p3;//是指针的安全级别升级的操作
//
//
//
//
//	return 0;
//}