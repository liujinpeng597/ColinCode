//#include<iostream>
//using namespace std;
//
//class QueueNode {
//public:
//	QueueNode(int value) :m_value(value),m_next(nullptr){};
//	int m_value;
//	QueueNode* m_next;
//};
//
//class Queue {
//public:
//	Queue() :m_front(nullptr), m_back(nullptr) ,m_count(0){};
//	~Queue() {
//		
//	}
//	QueueNode* m_front;
//	QueueNode* m_back;
//	int m_count;
//	void Push(int val) {
//		QueueNode* newNode = new QueueNode(val);
//		if (m_front == nullptr) {
//			m_front = newNode;
//		}
//		else {
//			m_back->m_next = newNode;
//		}
//		m_back = newNode;
//		m_count++;
//	}
//	void Pop() {
//		if (m_count == 0)return;
//		QueueNode* buffer_front = m_front;
//		m_front = m_front->m_next;
//		delete buffer_front;
//		m_count--;
//		if (m_count == 0) {
//			m_back = nullptr;
//		}
//	}
//	bool IsEmpty() {
//		return m_count == 0;
//	}
//	int QueueMin() {
//
//	}
//};
//
//int main()
//{
//	return 0;
//}