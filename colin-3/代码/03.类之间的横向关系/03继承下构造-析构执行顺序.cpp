//#include<iostream>
//using namespace std;
//class CFather
//{
//public:
//	int m_a;
//	CFather(int a) :m_a(a)
//	{
//
//	}
//};
//class Cson :public CFather
//{
//public:
//	//构造：父子  析构：子父
//	int m_a;
//	Cson() :m_a(30), CFather(20)/*当父类中含有带参数的构造函数时，需要手动显示调用（无法完成自动调用）*/
//		/*,CFatehr(）对于父类的无参数构造函数来说，编译器可以自动调用*/
//		/*调用父类的构造函数，完成初始化*/
//		/*Cfather::m_a(20) 无法直接给父类成员做初始化*/
//	{
//		//子类和父类可以定义同名的成员（属性，函数），默认优先使用的是子类的成员
//		//m_a=10;//Cson::m_a=10;
//		//Cson::m_a=10;//显示的指明了使用的是哪个类的成员
//		//CFather::m_a=20;//可以显示的指明类名作用，用于区别各个类同名的成员
//	}
//	~Cson()
//	{
//		cout << "~Cson()" << endl;
//		/*在子类的析构结尾，编译器安插调用父类析构的代码~Cfather（）
//		* 定义的是子类对象，当其生命周期结束时，匹配的是当前类型的析构函数（子类型）
//		* 编译器会自动调用子类的析构函数结尾安插调用父类析构函数的代码，确保父类子对象
//		* 和子类对象都被正确的回收时，没有泄露内存
//		*/
//
//	}
//
//};
//int main()
//{
//	Cson son;
//	cout << son.m_a << endl;
//	cout << son.CFather::m_a << endl;
//	//CFather::son.m_a;//错误写法
//
//
//	//CFather fa;
//	//cout<<fa.m_a<<endl;
//
//
//
//}