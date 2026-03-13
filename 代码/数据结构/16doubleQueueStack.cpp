//#include<iostream>
//#include<queue>
//using namespace std;
//
//class doubleQueueStack {
//private:
//	queue<int>q1;
//	queue<int>q2;
//public:
//	void Push(int val) {
//		!q1.empty() ? q1.push(val) : q2.push(val);
//	}
//	void Pop() {
//		//(!q1.empty() ? q1 : q2)非空队列
//		//(q1.empty() ? q1 : q2)空队列
//		if (q1.empty() && q2.empty())return;
//		queue<int>& nonEmptyQ = q1.empty() ? q2 : q1;
//		queue<int>& emptyQ = q1.empty() ? q1 : q2;
//		while (nonEmptyQ.size() > 1) {
//			emptyQ.push(nonEmptyQ.front());
//			nonEmptyQ.pop();
//		}
//		cout << nonEmptyQ.front() << endl;
//		nonEmptyQ.pop();
//	}
//};
//
//int main()
//{
//	doubleQueueStack dqStack;
//	dqStack.Push(1);
//	dqStack.Push(2);
//	dqStack.Push(3);
//	dqStack.Pop();
//	return 0;
//}