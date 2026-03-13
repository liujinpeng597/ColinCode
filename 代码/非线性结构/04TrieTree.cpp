//#include<iostream>
//#include<vector>
//#include<string>
//using namespace std;
//
//class Node
//{
//public:
//	int count;
//	vector<Node*>character;
//	string str;
//	Node() :count(0), character(26, nullptr) {};
//};
//
//class TrieTree
//{
//public:
//	Node* root;
//	TrieTree()
//	{
//		root = new Node;
//	}
//public:
//
//	void addWord(string& s)
//	{
//
//		Node* tree = root;
//		//遍历字符串
//		for (char c : s)
//		{
//			//检查字符对应分组
//			if (tree->character[c - 97] == nullptr)
//			{
//				tree->character[c - 97] = new Node;
//			}
//			//下一个字符
//			tree = tree->character[c - 97];
//		}
//		//末尾标记
//		tree->count++;
//		tree->str = s;
//	}
//
//	void create(vector<string>& strarr)
//	{
//		//依次添加各个单词
//		for (string s : strarr)
//		{
//			addWord(s);
//		}
//	}
//
//	void search(string& s) {
//		int i = 0;
//		int len = s.size();
//		Node* tree = root;
//		while (i < len) {
//			//检查字符对应分组
//			if (tree->character[s[i] - 97] == nullptr) {
//				//报错
//				cout << "failed QAQ" << endl;
//				break;
//			}
//			//下一个
//			tree = tree->character[s[i] - 97];
//			i++;
//		}
//		//检查
//		if (tree->count != 0) {
//			cout << "success! QWQ" << endl;
//		}
//		else {
//			cout << "failed! QAQ" << endl;
//		}
//	}
//
//	void traversal(Node* tree)
//	{
//		if (tree == nullptr)return;
//		if (tree->count != 0)
//		{
//			cout << tree->str << endl;
//		}
//		for (int i = 0; i < 26; i++)
//		{
//			traversal(tree->character[i]);
//		}
//	}
//};
//
//int main() {
//	return 0;
//}