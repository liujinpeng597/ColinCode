///*
//序列性容器：容器保持了元素的原有位置，允许指定插入 删除的位置，每个元素都有固定的位置，取决于插入的时间和地点
//list，vector向量，deque双端队列
//
//关联性容器：元素的位置取决于容器特定的排序规则，一般和元素的值有关。map set hash_map（无序的map）
//
//
//*/
//
//#include<iostream>
//#include<list>
//using namespace std;
//
//void printList(list<int>lst) {
//	for (int a : lst) { cout << a << " "; }cout << endl;
//}
//
//int main()
//{
//	//list<int> lst;  //空链表
//
//	//list<int> lst(3);  //构建指定长度的链表，且 有默认的初始化值
//	//list<int> lst(3,6);  //构建指定长度的链表，且 指定初始化值
//	list<int> lst{ 1,2,3,4 }; //初始化列表的形式构建
//	for (int a : lst) {
//		cout << a << "  "; //1 2 3 4
//	}
//	cout << endl;
//
//	//在list首push元素
//	lst.push_front(0);
//	printList(lst);
//
//	//尾删
//	lst.pop_back();
//	printList(lst);
//
//
//	list<int>::iterator it = ++ ++lst.begin();  //链表的迭代器不支持+，+=数字
//
//	//返回的是删除的下一个,自带++效果。
//	it = lst.erase(it);
//	cout << "* it: " << *it << endl; //3
//	for (int a : lst) { cout << a << "  "; }cout << endl; //0 1  3 
//
//	it = lst.erase(it);
//	for (int a : lst) { cout << a << "  "; }cout << endl; //0 1
//	cout << "* --it: " << *--it << endl; //* --it: 1
//
//	it = lst.begin();
//	while (it != lst.end()) {
//		cout << *it << "  ";  //0  1
//		++it;
//	}
//	cout << endl;
//
//	//end:有效尾元素的下一个元素（无效尾元素）
//
//	it = ++lst.begin();
//	it = lst.insert(it, 10); //返回新插入元素的迭代器
//	for (int a : lst) { cout << a << "  "; }cout << endl;
//	cout << *it << endl; //10
//
//	cout << lst.front() << "," << lst.back() << endl;
//	cout << *lst.begin() << "," << *--lst.end() << endl;
//
//	//移除元素
//	lst = { 3,1,7,3,0,3 };
//	lst.remove(3);
//	printList(lst);
//
//
//	//连续且相同的元素保留只剩下一个
//	lst = { 3,3,1,7,3,3,3,0,3 };
//	lst.unique();
//	printList(lst);
//
//	//按指定规则排序
//	lst.sort();
//	printList(lst);
//	lst.sort(greater<int>()/*指定排序规则,降序*/);
//	printList(lst);
//
//	//将整个链表进行翻转
//	lst.reverse(); 
//	printList(lst);
//
//	list<int> lst2{ 4,1,0,8 };
//	it = lst.begin();
//	advance(it, 3);//it指向第二个3
//	
//	/*lst.splice(it, lst2);
//	printList(lst);
//	cout << "size = " << lst2.size() << endl;*/
//
//	/*lst.splice(it, lst2, ++lst2.begin());
//	printList(lst);*/
//
//	lst.splice(it, lst2, lst2.begin(),--lst2.end());
//	printList(lst);
//	cout << "size = " << lst2.size() << endl;
//
//	return 0;
//}