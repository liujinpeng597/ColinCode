//#include<iostream>
//#include<vector>
//using namespace std;
//
////节点
//class node 
//{
//public:
//	int value;
//	node* next;
//
//	node(int v) :value(v), next(nullptr){}
//};
//
////哈希表
//class HashTable
//{
//private:
//	//指针数组
//	vector<node*>hashtable;
//	//M值
//	int M;
//public:
//	//构造函数
//	HashTable() :M(13), hashtable(13, nullptr){}
//	
//	//哈希表创建
//	void CreateHash(vector<int>& nums)
//	{
//		for (int v : nums)
//		{
//			//获得元素对应表位置
//			int index = v % M;
//
//			//向对应链表进行插入
//			//申请节点
//			node* tmp = new node(v);
//
//			//头插
//			tmp->next = hashtable[index];
//			hashtable[index] = tmp;
//		}
//	}
//
//	//哈希表查找
//	void find(int v)
//	{
//		//获得数据对应表位置
//		int index = v % M;
//
//		//遍历链表
//		node* p = hashtable[index];
//
//		while (p)
//		{
//			if (p->value == v)
//			{
//				cout << "success" << endl;
//				return;
//			}
//			p = p->next;
//		}
//		//失败
//		cout << "failed" << endl;
//	}
//};
//
//int main()
//{
//	HashTable h;
//	vector<int>nums = { 10,199,28,76,354,27,19,21,110,265,314,72 };
//	h.CreateHash(nums);
//	h.find(199);
//	return 0;
//}