//#include<iostream>
//using namespace std;
//
//class people{
//public:
//	int m_money;
//	people(int a = 100) :m_money(a) {}
//	void cost(int n){
//		m_money -= n;
//		cout << "买了好吃的" << endl;
//	}
//	void walk(){
//		cout << "溜溜达达走两步" << endl;
//	}
//	//纯虚函数:在函数参数列表后加上 = 0 不需要定义 是需要声明
//	virtual void eat() = 0;
//	virtual void f1 () = 0;
//};
//class Yellow :public people {//具体类 对于抽象的父类的纯虚函数 一定要重写定义和实现的
//public:
//	void eat(){//一定要重写父类的纯虚函数
//		cout << "吃蛋糕+寿司" << endl;
//	}
//	//override:来表明 这个函数一定是重写父类的函数,而不能是单独的虚函数 否则报错
//	void f1()override{}
//};
//
//void people::eat() {
//	cout << "people::eat" << endl;
//}
//
//int main() {
//	return 0;
//}