//#include<iostream>
//using namespace std;
//
//class Hand {
//public:
//	void move() {
//		cout << "手正在移动" << endl;
//	}
//};
//
//class Computer {
//public:
//	void compile() {
//
//	}
//};
//
//class Friend {
//public:
//	void play() {
//		cout << "张三正在玩耍" << endl;
//	}
//};
//
//class People {
//public:
//	Hand m_hand;
//	Friend* m_pFri;
//	People() :m_pFri(nullptr){};
//	void eat() {
//		m_hand.move();
//		cout << "将菜送进嘴里" << endl;
//	}
//	void code(Computer *pComp) {
//		if (!pComp) {
//			cout << "电脑为空,我无法完成编程功能" << endl;
//			return;
//		}
//		m_hand.move();
//		cout << "写出一行行代码" << endl;
//
//		pComp->compile();
//	}
//	void playGame() {
//		if (m_pFri) {
//			m_pFri->play();
//			cout << "我和我的朋友高兴地玩耍" << endl;
//		}
//		else {
//			cout << "我自己孤独的高兴地玩耍" << endl;
//		}
//	}
//};
//
//
//
//
//class Family {
//public:
//	People* peoArr[10];
//	Family() :peoArr{ nullptr } {
//		peoArr[0] = new People;
//		peoArr[1] = new People;
//		peoArr[2] = new People;
//	}
//	~Family() {
//		for (People*& p : peoArr) {
//			if (p) {
//				delete p;
//				p = nullptr;
//			}
//		}
//	}
//	void peoEat() {
//		for (People*& p : peoArr) {
//			if (p) {
//				p->eat();
//			}
//		}
//	}
//};
//
//
//
//int main() {
//	{
//		People peo;
//		peo.eat();
//	}
//	{
//		People peo;
//		peo.code(nullptr);
//
//		Computer comp;
//
//		peo.code(&comp);
//	}
//	{
//		People peo;
//		peo.playGame();
//		Friend fri;
//		peo.m_pFri = &fri;
//		peo.playGame();
//	}
//	{
//		Family fam;
//		fam.peoEat();
//	}
//	return 0;
//}