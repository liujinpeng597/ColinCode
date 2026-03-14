//#include<iostream>
//using namespace std;
//
///*
//继承: 父类(基类),子类(派生类),子类包含父类，也可以使用父类的成员,子诶是对父类的派生和延续
//*/
//
//class Father {
//public:
//	int m_fa;
//
//	void funFather() {
//		cout << "funFather" << endl;
//	}
//};
//
////子类类名后:以冒号开头 继承方式 继承的父类
//class Son : public Father {
//public:
//	int m_son;
//
//	Son(){
//		this->m_son = 123;
//		this->m_fa = 456; //可以直接使用父类的成员
//	}
//
//	void funSon() {
//		cout << "funSon" << endl;
//	}
//};
//
//int main() {
//	Son son;
//	cout << son.m_son << " " << son.m_fa << endl;
//	son.funFather();
//	son.funSon();
//	//对象的内存空间,子类包含父类，当计算子类对象的大小时,也应该将父类的大小考虑进去
//	//继承下 子类对象内存布局 前面是父类 后面是子类
//	cout << sizeof(son) << endl;
//	cout << "对象首地址" << &son << endl;
//	cout << "&son.m_fa" << &son.m_fa << endl;
//	cout << "&son.m_son" << &son.m_son << endl;
//	return 0;
//}