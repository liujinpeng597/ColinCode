#include<iostream>
using namespace std;

class Engine {
public:
	virtual void work() = 0;
};

class Engine2L :public Engine {
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

class EngineFac {
public:
	virtual Engine* createEngine() = 0;
};

class EngineFac2L :public EngineFac {
public:
	Engine* createEngine() {
		return new Engine2L;
	}
};

class EngineFac2T :public EngineFac {
public:
	Engine* createEngine() {
		return new Engine2T;
	}
};

class Car {
public:
	Engine* m_pEngine;

	//工厂方法
	Car(EngineFac* pfac) :m_pEngine(pfac ? pfac->createEngine() : nullptr) {}
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
	//创建所需工厂对象
	EngineFac* pfac1 = new EngineFac2L;
	//工厂方法创建汽车
	Car car(pfac1);
	//汽车发动
	car.drive();

	return 0;
}