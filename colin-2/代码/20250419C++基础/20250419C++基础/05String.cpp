//#include<iostream>
//#include<string>
//using namespace std;
//
//int main()
//{
//	//str1  指针  字符常量区(只能读不能写)  str1[2] = 'H';不可以 str1 = "hello";可以
//	//str2  数组  栈区(可读可写)            str2[2] = 'H';可以   str2 = "hello";不可以
//	//str2[]与*str1档形参的时候,是同一个类型[]会退化成一个指针
//	const char* str1 = "str1";
//	char str2[20] = "str2";
//	cout << "str1是" << str1 << endl;
//	cout << "str2是" << str2 << endl;
//
//
//	//----------------------
//	//c语言字符串复制通过函数
//	strcpy_s(str2, str1);
//	cout << "c str1复制到str2" << endl;
//	cout << "str2是" << str2 << endl;
//	//c++字符串复制通过赋值运算符
//	string str = "abcabc";
//	string str3 = "haha";
//	cout << "str是" << str << endl;
//	cout << "str3是" << str3 << endl;
//	str = str3;
//	cout << "c++ str3复制到str" << endl;
//	cout << "str是" << str << endl;
//
//
//	//----------------------
//	//c语言字符串拼接通过函数
//	strcat_s(str2, str1);
//	cout << "c str1拼接到str2后" << endl;
//	cout << "str2是" << str2 << endl;
//	//c++字符串拼接通过+=运算符
//	str += str3;
//	cout << "c++ str3拼接到str后" << endl;
//	cout<< "str是" << str << endl;
//
//
//	//---------------------
//	//c语言通过比较函数
//	if (strcmp(str1, str2) == 0)
//	{
//		cout << "相等" << endl;
//	}
//	else
//	{
//		cout << "不等" << endl;
//	}
//	//c++通过比较运算符
//	if (str == str3)
//	{
//		cout << "C++相等" << endl;
//	}
//	else
//	{
//		cout << "C++不等" << endl;
//	}
//	//---------------------
//	cout << "str1是" << str1 << endl;
//	cout << "str2是" << str2 << endl;
//	cout << "str3是" << str3 << endl;
//	cout << "str是" << str << endl;
//	//---------------------
//	cout << "sizeof(str1)是:" << sizeof(str1) << endl;
//	cout << "sizeof(str2)是:" << sizeof(str2) << endl;
//	cout << "strlen(str1)是:" << strlen(str1) << endl;
//	cout << "strlen(str2)是:" << strlen(str2) << endl;
//
//	cout << "sizeof(str)是" << sizeof(str) << endl;
//	cout << "sizeof(str3)是" << sizeof(str3) << endl;
//	cout << "str.size()是" << str.size() << endl;
//	cout << "str3.size()是" << str3.size() << endl;
//	cout << "str.length()是" << str.length() << endl;
//	cout << "str3.length()是" << str3.length() << endl;
//	//---------------------
//	cout << "str.substr(3, 5)是" << str.substr(3, 5) << endl;
//	cout << "str.substr(4, 10)是" << str.substr(4, 10) << endl;
//	cout << "str.find('h')是" << str.find('h') << endl;
//	cout << "str.find('ah')是" << str.find("ah") << endl;
//	cout << "str.find('c')是" << str.find('c') << endl;
//	return 0;
//}