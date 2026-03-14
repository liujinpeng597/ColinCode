//#include<iostream>
//using namespace std;
//
//class CTest {
//public:
//	int m_a;
//	CTest() :m_a(1) {}
//	void fun() {
//		cout << "CTest::fun" << endl;
//	}
//	virtual void funVirtual() {
//		cout << "CTest::funVirtual" << endl;
//	}
//	virtual void funVirtual2() {
//		cout << "CTest::funVirtual2" << endl;
//	}
//};
//
///*
//__vfptr: void** 类型的二级指针虚函数列表指针，属于对象之中，当类中存在虚函数的时候，编译器默认添加的隐藏属性
//多个对象中都存在这个指针，多个虚表指针指向的是同一个虚函数列表
//在定义对象调用构造函数时候，在初始化参数列表中由编译器默认进行初始化
//由编译器添加在对象内存空间的首地址位置(在成员属性前面)
//
//虚函数列表(函数指针动态数组)vftable 数组的每一个元素存储的当前类中虚函数的地址  元素类型 void*
//属于类的，在编译期由编译器直接构建出来 数组元素的数量就是虚函数的数量 元素顺序:取决于虚函数在类中声明的先后顺序
//
//调用流程： 首先找到对象内存空间前面指针大小的空间 去除里面存储的地址（表里的地址） 通过这个地址间接引用 找到虚表
//通过下标直接定位到虚表的具体内容 获取里面的虚函数真正的地址 通过这个函数的入口调用虚函数
//
//区别:
//1.调用流程不同
//2.效率不同 虚函数调用流程复杂 效率低
//3.使用场景不同 虚函数使用目的是为了能够实现动态多态 一般函数无法实现动态多态
//*/
//
//
//int main() {
//	//cout<<sizeof(CTest)<<endl; // 1 只有一个普通的函数
//
//	cout << sizeof(CTest) << endl;//4 一个普通的函数+虚函数
//
//	CTest t;
//	CTest t2;
//
//	cout << "&t2:" << &t2 << endl;
//	cout << "&m_a:" << t2.m_a << endl;
//
//	t2.fun();
//	t2.funVirtual();
//
//	int vfptr = *(int*)&t2;//虚表指针（虚表首地址）
//
//	using P_FUN2 = void(*)(int);
//	P_FUN2 p_fun2 = (P_FUN2) (* ((int*)vfptr));
//
//	using P_FUN = void(*)();
//	P_FUN p_fun = (P_FUN)(*(((int*)vfptr) + 1));
//
//	
//	return 0;
//}