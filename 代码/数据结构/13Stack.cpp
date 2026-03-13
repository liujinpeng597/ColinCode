//#include<iostream>
//using namespace std;
//
//class Node {
//public:
//	Node(int value) :m_next(nullptr),m_value(value){};
//	int m_value;
//	Node* m_next;
//};
//
//class Stack {
//public:
//
//	Node* m_top;
//	int m_count;
//	//构造函数
//	Stack() :m_top(nullptr), m_count(0) {};
//	//析构函数
//	~Stack() {
//		clear();
//	}
//	//头增
//	void Push(int val) {
//		Node* newNode = new Node(val);
//		if (m_top == nullptr)
//		{
//			m_top = newNode;
//		}
//		else {
//			newNode->m_next = m_top;
//			m_top = newNode;
//		}
//		m_count++;
//	}
//	//弹出
//	int Pop() {
//		if (m_top == nullptr||m_count==0)return 0;
//		Node* buffer_top = m_top;
//		int buffer_value = m_top->m_value;
//		m_top = m_top->m_next;
//		m_count--;
//		delete buffer_top;
//		return buffer_value;
//	}
//	//获得栈顶元素
//	int GetTop(){
//		if (m_top == nullptr) {
//			return -99999;
//		}
//		return m_top->m_value;
//	}
//	//获得栈元素数
//	int GetCount(){
//		return m_count;
//	}
//	//清空
//	void clear(){
//		while (m_top != nullptr) {
//			Node* buffer_top = m_top;
//			m_top = m_top->m_next;
//			delete buffer_top;
//		}
//		m_count = 0;
//	}
//	//判断是否为空
//	bool IsEmpty(){
//		return m_count == 0;
//	}
//};
//
//int main()
//{
//	Stack stack;
//	for (int i = 0; i < 10; i++) {
//		stack.Push(i);
//	}
//	/*for (int i = 0; i < 10; i++) {
//		cout << stack.Pop() <<" ";
//	}*/
//	cout << stack.GetTop() << endl;;
//	cout << stack.GetCount() << endl;
//	stack.clear();
//	cout << stack.GetTop() << endl;;
//	cout << stack.GetCount() << endl;
//	cout << stack.IsEmpty() << endl;
//	
//	return 0;
//}