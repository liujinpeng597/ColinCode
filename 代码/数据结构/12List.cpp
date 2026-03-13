//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Node {
//public:
//	Node(int value) :value(value), next(nullptr) {};
//	int value;
//	Node* next;
//};
//
//class LinkedList {
//public:
//    Node* head;
//	//构造函数
//	LinkedList() : head(nullptr) {};
//	//// 析构函数
//	//~LinkedList() {
//	//	Node* current = head;
//	//	while (current != nullptr) {
//	//		Node* next = current->next;
//	//		delete current;
//	//		current = next;
//	//	}
//	//	head = nullptr;
//	//}
//	//创建
//	void CreateList(vector<int>& nums)
//	{
//		for (int v : nums)
//		{
//			insertAtTail(v);
//		}
//	}
//	//头插
//	void insertAtHead(int val) {
//		Node* newNode = new Node(val);
//		newNode->next = head;
//		head = newNode;
//	}
//	//尾插
//	void insertAtTail(int val) {
//		Node* newNode = new Node(val);
//		if (head == nullptr)
//		{
//			head = newNode;
//			return;
//		}
//		Node* current = head;
//		while (current->next != nullptr)
//		{
//			current = current->next;
//		}
//		current->next = newNode;
//	}
//	// 在指定位置插入新节点（位置从0开始）
//	bool insertAtPosition(int val, int position) {
//
//	}
//	// 删除头节点
//	bool deleteHead() {
//		Node* newNode = head;
//		head = head->next;
//		delete newNode;
//		newNode = nullptr;
//		return true;
//	}
//	// 删除尾节点
//	bool deleteTail() {
//		if (head == nullptr)return false;
//		if (head->next == nullptr) {
//			delete head;
//			head = nullptr;
//			return true;
//		}
//		Node* current = head;
//		while (current->next->next  != nullptr)
//			current = current->next;
//		delete current->next ;
//		current->next  = nullptr;
//		return true;
//	}
//	// 删除指定值的节点（删除第一个匹配的节点）
//	bool deleteByValue(int val) {
//		if (head == nullptr)return false;
//		if (head->value == val) {
//			return deleteHead();
//		}
//		Node* current = head;
//		while (current->next != nullptr && current->next->value != val)
//		{
//			current = current->next;
//		}
//		if (current->next == nullptr)
//		{
//			return false;
//		}
//		Node* newNode = current->next;
//		current->next = current->next->next;
//		delete newNode;
//		newNode = nullptr;
//		return true;
//	}
//	// 查找指定值是否存在
//	bool search(int val) {
//		Node* current = head;
//		while (current != nullptr)
//		{
//			if (current->value == val)return true;
//			current = current->next;
//		}
//		return false;
//	}
//	// 获取链表长度
//	int length() {
//		int count = 0;
//		Node* current = head;
//		while (current != nullptr)
//		{
//			count++;
//			current = current->next;
//		}
//		return count;
//	}
//
//	//遍历
//	void display() {
//		if (head == nullptr)return;
//		Node* current = head;
//		while (current != nullptr)
//		{
//			cout << current->value << "->";
//			current = current->next;
//		}
//		cout << "nullptr" << endl;
//	}
//	//倒序
//	void RPrintLink(Node* head) {
//		if (head == nullptr)return;
//		RPrintLink(head->next);
//		cout << head->value << "->";
//	}
//	//倒序
//	void ReverseLink() {
//		cout << endl;
//		Node* prev = nullptr;
//		Node* current = head;
//		Node* next = nullptr;
//		while (current != nullptr)
//		{
//			next = current->next;
//			current->next = prev;
//			prev = current;
//			current = next;
//		}
//		head = prev;
//	}     
//	//合并
//	void mergeLinkedList(Node* h1, Node* h2) {
//		if (h1 == nullptr && h2 == nullptr) {
//			head = nullptr;
//			return;
//		}
//		if (h1 == nullptr) {
//			head = h2;
//			return;
//		}
//		if (h2 == nullptr) {
//			head = h1;
//			return;
//		}
//
//		Node* newhead = nullptr;
//		Node* tail = nullptr;
//
//		if (h1->value < h2->value) {
//			newhead = h1;
//			tail = h1;
//			h1 = h1->next;
//		}
//		else {
//			newhead = h2;
//			tail = h2;
//			h2 = h2->next;
//		}
//
//		while (h1 != nullptr && h2 != nullptr) {
//			if (h1->value <= h2->value) {
//				tail->next = h1;
//				tail = h1;
//				h1 = h1->next;
//			}
//			else {
//				tail->next = h2;
//				tail = h2;
//				h2 = h2->next;
//			}
//		}
//
//		if (h1 != nullptr) {
//			tail->next = h1;
//			while (tail->next != nullptr) {
//				tail = tail->next;
//			}
//		}
//		if (h2 != nullptr) {
//			tail->next = h2;
//			while (tail->next != nullptr) {
//				tail = tail->next;
//			}
//		}
//		head = newhead;
//	}
//};
//
//int main()
//{
//	LinkedList linkedList;
//	LinkedList linkedList2;
//	LinkedList mergedList;
//	vector<int>nums = { 1,3,5,7,9 };
//	vector<int>nums2 = { 2,4,6,8,10 };
//	linkedList.CreateList(nums);
//	linkedList2.CreateList(nums2);
//	//linkedList.display();
//	//linkedList.RPrintLink(linkedList.head);
//	//linkedList.ReverseLink();
//	//linkedList.display();
//	mergedList.mergeLinkedList(linkedList.head, linkedList2.head);
//	mergedList.display();
//	return 0;
//}