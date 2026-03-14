//#include<iostream>
//using namespace std;
//
////CFather* const pthis = &son;  //父类的指针可以不通过强转，能够直接指向子类对象。
//
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
//void fun(people* p) //父类指针可以统一多种子类类型
//{
//	p->cost(20);
//	//p->eat();   //无法调用子类的函数，有待解决
//	p->walk();
//}
//
////void fun(White* p)
////{
////	p->cost(20);
////	p->eat();
////	p->walk();
////}
//
////两个人：
//class Family
//{
//public:
//	//代码表示复杂
//	Yellow* arrY[2];
//	White* arrW[2];
//	Black* arrB[2];
//	//代码表示简单，没有内存空间浪费
//	people* arrPeo[2];
//	Family() :arrPeo{ new White,new Black }
//	{
//		arrPeo[0]->cost(10);
//		//arrPeo[0]->eat();
//		arrPeo[0]->walk();
//	}
//
//
//	int main()
//	{
//		fun(new Yellow);
//		fun(new White);
//
//		Family fam;
//		return 0;
//	}