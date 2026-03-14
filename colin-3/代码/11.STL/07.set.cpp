//#include<iostream>
//#include<set>
//using namespace std;
//
////set:关联性容器,和map 底层结构,查找效率是一样的
////不区分键值和实值,map去掉了实值,set元素值是唯一的 不允许重复
//
//int main() {
//	set<int>st{ 4,1,9,7,5 };
//	set<int>::iterator it = st.begin();
//	while (it != st.end()) {
//		cout << *it << " ";
//		++it;
//	}
//	cout << endl;
//	st.insert(2);
//	for (int v : st) {
//		cout << v << " ";
//	}
//	cout << endl;
//
//	st.insert(4);
//	for (int v : st) {
//		cout << v << " ";
//	}
//	cout << endl; //插入失败 通过返回值可以判断成功还是失败
//	
//	it = st.find(4);
//	it = st.erase(it);
//	for (int v : st) {
//		cout << v << " ";
//	}
//	cout << endl;
//	cout << *it << endl;
//	return 0;
//}