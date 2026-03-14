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

class Gearbox {//变速箱
public:
	virtual void work() = 0;
};
class GearboxManual :public Gearbox {
public:
	void work() {
		cout << "手动档变速箱正在工作" << endl;
	}
};
class GearboxAuto :public Gearbox {
public:
	void work() {
		cout << "自动档变速箱正在工作" << endl;
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

class Factory {
public:
	virtual Engine* createEngine() = 0;
	virtual Gearbox* createGearbox() = 0;
};
class Fac2TManual :public Factory {
	virtual Engine* createEngine() {
		return new Engine2T;
	}
	virtual Gearbox* createGearbox() {
		return new GearboxManual;
	}
};

class Car {
public:
	Engine* m_pEngine;
	Gearbox* m_pGearbox;
	
	Car(Factory* pfac):
		m_pEngine(pfac?pfac->createEngine() : nullptr),
		m_pGearbox(pfac ? pfac->createGearbox() : nullptr){}

	~Car() {
		if (m_pEngine) {
			delete m_pEngine;
			m_pEngine = nullptr;
		}
		if (m_pGearbox) {
			delete m_pGearbox;
			m_pGearbox = nullptr;
		}
	}
	void drive() {
		if (m_pEngine && m_pGearbox) {
			m_pEngine->work();
			m_pGearbox->work();
			cout << "我的小汽车呜呜发动" << endl;
		}
	}
};

int main() {
	Factory* pfac = new Fac2TManual;

	Car car(pfac);
	car.drive();

	return 0;
}