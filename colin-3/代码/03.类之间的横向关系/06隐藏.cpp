//#include<iostream>
//using namespace std;
//
//void fun()
//{
//	cout << "fun" << endl;
//}
//void fun(/*  CFather* const this    */int a)
//{
//	cout << "fun(int)" << endl;
//}
//
//class CFather
//{
//public:
//	//并不是函数重载，并不是在一个作用域下
//	void fun(int a)
//	{
//		cout << "fun（int）" << a << endl;
//		cout << "this:" << this << endl;
//	}
//};
//
//class CSon :public CFather
//{
//public:
//	//隐藏：子类定义了和父类同名的成员，会将父类的同名成员自动隐藏
//	void fun()
//	{
//		cout << "fun" << endl;
//	}
//	//也是函数重载
//	/*void fun(int a)
//	{
//		cout << "fun(int)" << endl;
//	}*/
//};
//
//int main()
//{
//	CSon son;
//
//	son.fun();
//	//son.fun(10);  //无法自动匹配父类
//	son.CFather::fun(10);  //显式的指定匹配父类的函数
//	//------------------------------
//	son.CFather::fun(10);
//	cout << "&son:" << &son << endl;
//
//	CFather* const pthis = &son;  //父类的指针可以不通过强转，能够直接指向子类对象。
//	//保证了子类对象可以顺利的调用父类的函数
//
////CSon* pson = new CFather;     //反过来不行。
//
////小类型的指针 可以指向大类型的对象
////大类型的指针 不可以指向小类型的对象
//
//	return 0;
//}