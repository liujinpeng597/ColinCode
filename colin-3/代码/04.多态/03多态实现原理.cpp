//#include<iostream>
//using namespace std;
//
//class CFather {
//public:
//	virtual void fun1() {
//		cout << "CFather::fun1" << endl;
//	}
//	virtual void fun2() {
//		cout << "CFather::fun2" << endl;
//	}
//};
//
//class CSon :public CFather {
//	virtual void fun1() {
//		cout << "CFather::fun1" << endl;
//	}
//	virtual void fun3() {
//		cout << "CFather::fun3" << endl;
//	}
//};
///*
//虚函数列表指针:vfptr:到底指向的是哪个类虚表 取决于定义的是哪个子类的对象
//
//虚函数表:
//父类:同单个类中一样
//子类:虚表运作流程(在编译期就完成)
//1.继承：子类不但继承父类的成员，也会继承父类的虚表
//2.检查重写:如果子类重写父类的虚函数 则在虚表中【原地覆盖】
//		   父类中没有被重写的虚函数，【原地保留】
//3.结尾追加：子类中如果有单独的虚函数，按照顺序在虚表结尾依次添加
//*/
//
//int main() {
//	CFather* pfa = new CSon;
//	CSon son;
//	CFather fa;
//
//	pfa->fun1();
//	pfa->fun2();
//	return 0;
//}