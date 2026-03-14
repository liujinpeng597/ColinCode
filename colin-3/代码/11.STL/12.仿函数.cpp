#include<iostream>
using namespace std;

int add(int a, int b) {
	return a + b;
}

//通过类模拟实现,operator()

class ADD {
public:
	int sum; //统计所有加法的总和
	ADD() :sum(0) { cout << "ADD初始化成功..." << endl; }
	int operator()(int a, int b) {
		sum += a + b;
		return a + b;
	}
};

int main() {
	cout << "add(10, 20)=" << add(10, 20) << endl;
	ADD Add;
	//Add.add(30, 40);

	cout << "Add(50, 60)=" << Add(50, 60) << endl; //把对象名当成函数名,去像调用函数一样,实现仿函数(加法)功能
	cout << "Add(60, 70)=" << Add(60, 70) << endl;

	cout << "Add.sum=" << Add.sum << endl;
	return 0;
}