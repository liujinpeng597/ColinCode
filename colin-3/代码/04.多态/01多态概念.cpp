//#include<iostream>
//using namespace std;
//
///*
//多态:相同行为方式 导致不同的行为结果 同一行语句可以展现多种不同的表现形态
//c++:在继承下 父类的指针可以指向任何继承于该子类的对象 多种子类具有多种形态
//由父类指针进行统一管理 则父类指针具有了多种形态 即是多态性
//
//多态的条件:
//1.在继承下 父类指针（引用）指向子类对象。（而不是子类指针）
//2.在父类中定义了虚函数 子类重写了父类的这个虚函数。
//
//重写：子类定义了和父类虚函数一模一样的虚函数（返回类型 函数名 参数列表）
//
//*/
//
//class Father {
//public:
//	//virtual：虚函数 定义虚函数的关键字
//	virtual void fun(int b) {//虚函数原型 保持一致		
//		cout << "Father::fun" << endl;
//	}
//};
//
//class Son :public Father {
//public:
//	/*(virtual)*/void fun(int a) {//也是虚函数,因为子类已经重写了父类的虚函数,即使不加关键字,也会被认定为虚函数
//		cout << "son::fun" << endl;
//	}
//};
//
//class People
//{
//public:
//	int m_money;
//	People(int a = 100) :m_money(a) {}
//
//	void cost(int n)
//	{
//		m_money -= n;
//		cout << "买了好吃的" << endl;
//	}
//
//	void walk()
//	{
//		cout << "溜溜达达走两步" << endl;
//	}
//};
//class Yellow :public People //黄种人
//{
//public:
//	void eat()
//	{
//		cout << "吃蛋糕+寿司" << endl;
//	}
//};
//class White :public People //白种人
//{
//public:
//	void eat()
//	{
//		cout << "吃黑巧克力" << endl;
//	}
//};
//class Black :public People //黑种人
//{
//public:
//	void eat()
//	{
//		cout << "吃白巧克力" << endl;
//	}
//};
//
//
//using PFUN = void(People ::*)();
//
//void fun(People* p, PFUN pfun) {
//
//}
//
//void fun(People* p){
//
//}
///*
//编译器绑定：（静态绑定）:通过函数名 在编译器就绑定了 也就是确定了调用哪个函数 通过名字调用普通的函数 
//运行期绑定：（动态绑定）：virtual函数 编译器匹配的是父类的函数 运行期绑定的是子类的函数 这样才能完成多态
//
//编译时多态： 函数重载
//运行时多态：虚函数实现的动态多态
//破除多态：显式的指定父类的类名作用域
//*/
//int main() {
//	Father* pta = new Son;//父类指针指向子类对象 虽然pta是父类的指针 但是指向对象是子类 所以调用fun是子类fun
//	pta->fun(1);
//
//
//	Father& fa = *pta;//父类引用父类指向子类的指针 依旧调用子类fun
//	fa.fun(2);
//
//	fun(new Black);
//
//	fa.Father::fun(3);//显式的指定父类的类名作用域
//
//	return 0;
//}