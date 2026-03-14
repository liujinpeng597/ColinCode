//#include<iostream>
//using namespace std;
//
///*
//继承使用：有一些功能比较相似的类，里面会有一些公共的代码，将这些公共的代码抽离出来，放到一个类中，即这个类是父类。 子类继承父类，就包含了所有的公共的代码。提高了代码的复用性和扩展性。
//*/
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
//int main()
//{
//	{
//		Yellow y;
//		y.cost(10);
//		y.eat();
//		y.walk();
//	}
//
//	{
//		White y;
//		y.cost(20);
//		y.eat();
//		y.walk();
//	}
//
//	{
//		Black y;
//		y.cost(30);
//		y.eat();
//		y.walk();
//	}
//	return 0;
//}