//#include<iostream>
//using namespace std;
//
//class CTest {
//public:
//	int m_a;
//	const int m_b = 10;
//	static int m_c;
//
//	void fun(){
//		funStatic();//this,类名作用域直接调用 都可以 
//		funConst();//必须通过this调用
//		cout << m_a << " " << m_b << " " << m_c << endl;
//	}
//	static void funStatic(){
//		cout << m_c << endl;
//		//funConst(); 静态函数只能调用静态函数或静态成员
//		//fun();
//		//cout<<m_a<<" "<<m_b<<endl; 
//	}
//	void funConst() const{
//		//fun(); //this指针安全级别降低
//		funStatic(); // ok
//		m_c = 30; // 既可以用 也可以改
//	}
//
//	//-------------------------------------
//	//error C2686:不能重载具有相同参数类型的静态和非静态成员函数
//	//相同函数名 同参数的 静态的非静态 不能同时存在
//	//同名同参数的一般函数和常成员函数 互为函数重载
//	void f(){
//		cout << "f" << endl;
//	}
//	//static void f() {}
//	void f() const {
//		cout << "f const" << endl;
//	}
//};
//
//int CTest::m_c = 0;
//
//int main() {
//
//	CTest t;
//	//t.fun();
//	t.f();//优先匹配一般的函数
//
//	const CTest t2;
//	t2.f(); //const对象 只能调用 const函数
//	return 0;
//}