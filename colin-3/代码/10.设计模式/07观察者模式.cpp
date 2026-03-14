#include<iostream>
#include<list>
using namespace std;


//观察者模式:订阅-发布模式
class Observer {
public:
	virtual void notify(const string& title) = 0;
};

class 张同学:public Observer {
public:
	void notify(const string& title) {
		cout << "我是张同学,我收到了文章: " << title << endl;
	}
};

class 李同学 :public Observer {
public:
	void notify(const string& title) {
		cout << "我是李同学,我收到了文章: " << title << endl;
	}
};

//公众号
class PublicAccount {
public:
	list<Observer*> m_lstObserver;
public:
	//点击关注公证号
	void pushObserver(Observer* pob) {
		m_lstObserver.push_back(pob);
	}
	//取消关注公众号
	void popObserver(Observer* pob) {
		list<Observer*>::iterator it = m_lstObserver.begin();
		while (it != m_lstObserver.end()) {
			if (*it == pob) {
				m_lstObserver.erase(it);
				break;
			}
			++it;
		}
	}
	//发布文章
	void publishTitle(const string& t) {
		string text = t;
		for (Observer* pob : m_lstObserver) {
			pob->notify(t);
		}
	}
};


int main() {
	PublicAccount pa;

	张同学 小张;
	李同学 小李;

	pa.pushObserver(&小张);
	pa.pushObserver(&小李);

	pa.publishTitle("《new-malloc底层.....》");

	pa.popObserver(&小李);
	return 0;
}