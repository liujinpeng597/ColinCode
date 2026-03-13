//#include<iostream>
//#include<stack>
//using namespace std;
//
//class doubleStackQueue {
//private:
//	stack<int> s1_push;
//	stack<int> s2_pop;
//public:
//	void Push(int val) {
//		if (!s1_push.empty()) {
//			s1_push.push(val);
//		}
//		else {
//			while (!s2_pop.empty()) {
//				s1_push.push(s2_pop.top());
//				s2_pop.pop();
//			}
//			s1_push.push(val);
//		}
//	}
//	void Pop() {
//		if (s2_pop.empty()) {
//			while (!s1_push.empty())
//			{
//				s2_pop.push(s1_push.top());
//				s1_push.pop();
//			}
//			s2_pop.pop();
//		}
//		else {
//			s2_pop.pop();
//		}
//	}
//	int Top() {
//		if (s2_pop.empty()) {
//			while (!s1_push.empty())
//			{
//				s2_pop.push(s1_push.top());
//				s1_push.pop();
//			}
//			return s2_pop.top();
//		}
//		else {
//			return s2_pop.top();
//		}
//	}
//};
//
//int main()
//{
//	doubleStackQueue dsQueue;
//	for (int i = 0; i < 10; i++) {
//		dsQueue.Push(i);
//	}
//	for (int i = 0; i < 10; i++) {
//		cout<<dsQueue.Top()<<" ";
//		dsQueue.Pop();
//	}
//	return 0;
//}