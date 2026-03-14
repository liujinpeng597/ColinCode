//#include<iostream>
//using namespace std;
///*
//* public：公共的
//* protected:保护的
//* private:私有的
//* 继承方式：父类成员在子类中表现的属性，和访问修饰符 共同决定了父类成员所能使用的范围
//*
//*
//* 继承方式:public:
//* 父类属性     子类属性
//* public        public
//* protected     protected
//* private       不可访问
//*
//*
//* * 继承方式:protected:
//* 父类属性     子类属性
//* public        protected
//* protected     protected
//* private       不可访问
//*
//* * 继承方式:private
//* 父类属性     子类属性
//* public        private
//* protected     private
//* private       不可访问
//*
//*
//*/
//class CFather
//{
//public:
//	int m_pub;
//protected:
//	int m_pro;
//private:
//	int m_pri;
//public:
//	CFather() :m_pub(1), m_pro(2), m_pri(3) {}
//	int getpri() { return m_pri; }
//
//
//};
////class CSon:public CFather
////{
////public:
////	void funpublic()
////	{
////		cout << m_pub << endl;//public
////		cout << m_pro << endl;//public
////		//cout << m_pri << endl;
////		cout << getpri() << endl;
////
////
////	}
////};
//class CSon :protected CFather
//{
//public:
//	void funpublic()
//	{
//		cout << m_pub << endl;//protected
//		cout << m_pro << endl;//protected
//		//cout << m_pri << endl;
//		cout << getpri() << endl;
//
//
//	}
//};
//class CSon : CFather
//{
//public:
//	void funpublic()
//	{
//		cout << m_pub << endl;//private
//		cout << m_pro << endl;//private
//		//cout << m_pri << endl;
//		cout << getpri() << endl;
//
//
//	}
//};
//class CSonson :public CSon
//{
//public:
//	void fun()
//	{
//		/*cout << m_pro << endl;
//		cout << m_pub << endl;*/
//	}
//
//};
//int main()
//{
//	CSon son1;
//	//son1.m_pub;
//	//son1.m_pro;
//
//}