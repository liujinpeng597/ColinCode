//#include<iostream>
//using namespace std;
//
//class Father
//{
//public:
//
//};
//
//class Son :public Father
//{
//public:
//	void fun(int a)
//	{
//		cout << "Son::fun  " << a << endl;
//	}
//};
////----------------------
//class people
//{
//public:
//	int m_money;
//	people(int a = 100) :m_money(a) {}
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
//
//class Yellow :public people //黄种人
//{
//public:
//	void eat()
//	{
//		cout << "吃蛋糕+寿司" << endl;
//	}
//};
//
//class White :public people //白种人
//{
//public:
//	void eat()
//	{
//		cout << "吃黑巧克力" << endl;
//	}
//};
//
//class Black :public people //黑种人
//{
//public:
//	void eat()
//	{
//		cout << "吃白巧克力" << endl;
//	}
//};
//
//using PFUN = void(people ::*)();
//void fun(people* p, PFUN pfun) //父类指针可以统一多种子类类型
//{
//	p->cost(20);
//	//p->eat();   //无法调用子类的函数，有待解决
//	(p->*pfun)();
//	p->walk();
//}
//
//int main()
//{
//	Father* pfa = new Son;
//	//pfa->fun();
//
//	//定义一个类成员函数指针
//	//typedef void(Son :: *P_FUN)(int);    //void(Son :: *  )(int);  P_FUN
//	using P_FUN = void(Father ::*)(int);     //C++中的起别名
//
//	P_FUN pfun = (P_FUN)&Son::fun;  //定义类成员函数指针,指向子类的函数
//	//(对象->*函数指针)（数）;
//	(pfa->*pfun)(20);
//
//	((Son*)pfa->*pfun)(20);  //向下强转，不具备通用性
//	//------------------------
//	fun(new Yellow, (PFUN)&Yellow::eat);
//	fun(new White, (PFUN)&Yellow::eat);
//	fun(new Black, (PFUN)&Yellow::eat);
//	return 0;
//}