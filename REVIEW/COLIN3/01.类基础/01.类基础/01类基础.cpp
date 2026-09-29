#include<iostream>
#include<string>
using namespace std;

class People {
public:
	string m_name;//
	int m_age;
	bool m_sex;//性别
	static constexpr int MAX = 100;//类内定义
public:
	void eat() {
		cout << m_name << "正在吃板面" << endl;
	}
};