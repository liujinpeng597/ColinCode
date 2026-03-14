//#include<iostream>
//using namespace std;
//
//class CFather {
//public:
//	//构造函数不能为虚函数
//	/*virtual*/CFather() { cout << "CFather" << endl; }
//	virtual ~CFather() { cout << "~CFather" << endl; }
//};
//
//class CSon :public CFather {
//public:
//	int* m_p;
//	CSon():m_p(new int(1)) { cout << "CSon" << endl; }
//	~CSon() { cout << "~CSon" << endl; } //重写 覆盖父类虚函数
//	//CFather::~CFather(); 编译器在结尾安插的这个代码，是静态绑定父类析构函数（不会再次发生多态）
//
//	//子类析构和父类析构 函数名不一样 是重写吗 是
//	//析构函数会被编译器重新命名 之后可以认为函数名是一样 所以在编译器的角度看 名字是一样的
//
//	//2.构造函数,静态成员函数
//	//static virtual void fun(){}
//	//仅非静态成员函数可以是虚拟的
//	//静态成员函数不能是虚函数
//};
///*
//在多态下 父类指针指向子类对象,delete调用析构函数 根据的是指针的类型 所以只是执行了父类的析构
//可能会存在内存泄漏问题
//通过虚析构解决 同一般的函数一样 也会发生多态 最终调用的是子类的析构函数 自然而然就会调用父类的析构了
//*/
//int main() {
//	//CSon son; //父子 子父
//
//	CFather* pfa = new CSon; // CFather CSon
//
//	delete pfa;
//	return 0;
//}