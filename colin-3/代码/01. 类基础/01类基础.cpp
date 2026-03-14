//#include<iostream>
//#include<string>
//using namespace std;
//
////public: 公共的,凡是能定义对象的地方,都可以使用
//
////private:私有的 只能在类中去使用
//
////protect:保护的 在类内和继承的子类可以使用
//
////结构体默认public:
//
//class People {
//public:
//	string m_name;
//	int m_age;
//	bool m_sex;
//	char* m_pnote;
//
//	//构造函数:用于类中成员初始化
//	//当定义类对象的时候,由编译器自动调用
//	//类中存在默认无参构造函数,People(){};
//	//如果一旦手动重构任何的构造函数，默认的无参构造函数就不会提供了
//	//构造函数可以出现多个，他们属于函数重载
//	/*People() {
//		m_name = "zhangsan";
//		m_age = 18;
//		m_sex = 1;
//	}*/
//
//	People() = default;
//
//	People(const string& name,const int age) {
//		m_name = "name";
//		m_age = age;
//		m_sex = 1;
//		m_pnote = new char[20] {"我是一个老师"};
//	}
//
//	//当对象的生命周期结束的时候,自动调用析构
//	~People() {
//		if (m_pnote) {
//			delete[]m_pnote;
//			m_pnote = nullptr;
//		}
//		
//	};
//
//	void eat() {
//		cout << m_name << "正在吃板面" << endl;
//	}
//	void show() {
//		cout << "name:" << m_name << ",age:" << m_age << ",sex:" << m_sex << endl;
//	}
//};
//
//int main() {
//
//	//People peo(); 此为函数声明
//
//	People peo;
//	peo.eat();
//	peo.show();
//
//	People peo2("李四", 21);
//	peo2.eat();
//	peo2.show();
//
//	return 0;
//}