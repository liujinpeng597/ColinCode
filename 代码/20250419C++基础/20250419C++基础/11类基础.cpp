//#include<iostream>
//using namespace std;
//
////访问修饰符: public/protected/private
////class默认访问权限私有
////struct默认访问权限公有
////public:公共的 所有人均可访问
////protected:受保护的 父类和继承于他的子类
////private:仅限自己类内访问
//
//class Robot
//{
//public:
//
//	int* p;
//	int m_size;
//	string m_name;
//	int m_charge;
//    //构造函数 与类同名 无返回值
//	//功能:初始化类成员属性
//	//定义对象时由系统自动调用
//	//在未书写构造函数时 系统会默认一共一个无参构造 空函数 什么也不做
//	//一旦书写构造 系统将不再提供无参构造 栈区对象所在{}结束时被回收 堆区对象delete时被调用
//	Robot(string name, int size, int charge)
//	{
//		this->m_name = name;
//		this->m_size = size;
//		this->m_charge = charge;
//	}
//	Robot()
//	{
//		this->m_name = "e-wall";
//		this->m_size = 50;
//		this->m_charge = 100;
//		p = nullptr;
//	}
//	void show()
//	{
//		cout << "name-" << m_name << "size-" << m_size << "charge-" << m_charge << endl;
//	}
//	//析构函数 ~与类同名 无参数 无返回值
//	//功能:释放对象额外申请的空间
//	//由系统自动调用 对象生命周期结束时调用 
//	~Robot()
//	{
//		cout << "~Robot" << m_size << endl;
//		if (p)
//		{
//			cout << "~~~~" << endl;;
//			delete p;
//			p = nullptr;
//		}
//	}
//};
//
//int main()
//{
//	Robot r1;
//	//r1.Init();
//	r1.m_size = 10;
//	r1.show();
//
//	string name = "qq";
//	Robot r2(name, 50, 100);
//	r2.m_size = 20;
//	r2.show();
//
//	Robot* r3 = new Robot();
//	r3->show();
//	r3->m_size = 30;
//	r3 = nullptr;
//
//	Robot r4;
//	r4.m_size = 40;
//	r4.p = new int;
//
//	return 0;
//}