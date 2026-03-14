#include<iostream>
using namespace std;

class Engine {
public:
	virtual void work() = 0;
};

class Engine2L:public Engine {
public:
	virtual void work() {
		cout << "2.0自然吸气的发动机正在工作" << endl;
	}
};

class Engine2T :public Engine {
public:
	virtual void work() {
		cout << "2.0涡轮增压的发动机正在工作" << endl;
	}
};

class Engine3T:public Engine {
public:
	virtual void work() {
		cout << "超级全新的3.0涡轮增压发动机正在工作" << endl;
	}
};

class EngineFac {
public:
	Engine* createEngine(const string& type) {
		if (type == "2L") {
			return new Engine2L;
		}
		else if (type == "2T") {
			return new Engine2T;
		}
		else if(type=="3T") {
			return new Engine3T;
		}
		return nullptr;
	}
};

class Car {
public:
	Engine* m_pEngine;
	//"2L" , "2T"
	Car(const string& type) :m_pEngine(nullptr) {//有耦合 直接创建发动机
		if (type == "2L") {
			m_pEngine = new Engine2L;
		}
		else if (type == "2T") {
			m_pEngine = new Engine2T;
		}
	}
	//对扩展开放，对修改封闭！！！
	Car(EngineFac* pfac, const string& type):m_pEngine(pfac ? pfac->createEngine(type):nullptr) {}

	~Car() {
		if (m_pEngine) {
			delete m_pEngine;
			m_pEngine = nullptr;
		}
	}

	void drive() {
		if (m_pEngine) {
			m_pEngine->work();
			cout << "我的小汽车呜呜发动" << endl;
		}
	}
};

int main() {
	Car car("2L");
	car.drive();

	EngineFac fac;

	Car car2(&fac, "2T");
	car2.drive();

	Car car3(&fac, "3T");
	car3.drive();
	return 0;
}