//#include<iostream>
//#include<deque>
//using namespace std;
//
//
//int main() {
//	deque<int>de{ 1,2,3,4 };
//	de.push_back(5);
//	de.push_front(0);
//	deque<int>::iterator it = de.begin();
//	while (it != de.end()) {
//		cout << *it << endl;
//		++it;
//	}
//	cout << endl;
//
//	de.pop_front();
//	for (int v : de) { cout << v << " "; }
//	cout << endl;
//
//	cout << de.size() << endl;//长度,没有容量的概念
//
//	//支持随机访问 //de[1]  =  de+1
//	de[3] = 30;
//	cout << de[2] << endl;
//	return 0;
//}