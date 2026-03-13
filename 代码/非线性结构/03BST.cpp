#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<utility>
using namespace std;
//树节点
class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	//构造函数
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {};
};
//链表节点
class LinkNode {
public:
	int val;
	LinkNode* prev;
	LinkNode* next;
	LinkNode(int val) :val(val), prev(nullptr), next(nullptr) {};
};
//链表
class LinkedList {
public:
	LinkNode* head;
	LinkNode* tail;
	LinkedList() :head(nullptr), tail(nullptr) {};
	//双向链表尾添加函数
	void Add(int val) {
		LinkNode* Node = new LinkNode(val);
		if (head == nullptr) {
			head = Node;
			tail = Node;
		}
		else {
			tail->next = Node;
			Node->prev = tail;
			tail = Node;
		}
	}
	//遍历双向链表
	void Print() {
		LinkNode* cur = head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};
//BST
class BST {
public:
	TreeNode* root;
	BST() :root(nullptr) {};
	//创建BST
	void CreateBST(vector<int>&nums) {
		for (int v : nums) {
			TreeNode* node = new TreeNode(v);
			TreeNode* cur = root;
			if (root == nullptr) {
				root = node;
				continue;
			}
			while (true) {
				if (node->val < cur->val) {
					if (cur->left == nullptr) {
						cur->left = node;
						break;
					}
					else {
						cur = cur->left;
					}

				}
				else if (node->val > cur->val) {
					if (cur->right == nullptr) {
						cur->right = node;
						break;
					}
					else {
						cur = cur->right;
					}
				}
				else {
					delete node;
					node = nullptr;
					break;
				}
			}
		}
	}
	//搜索函数,用于DelNode
	void Search(TreeNode* tree, int num, TreeNode*& del, TreeNode*& parent) {
		while (tree) {
			if (tree->val == num) {
				del = tree;
				return;
			}
			else if (tree->val > num) {
				parent = tree;
				tree = tree->left;
			}
			else {
				parent = tree;
				tree = tree->right;
			}
		}
		parent = nullptr;
	}
	//删除BST中的结点
	void DelNode(int num) {
		TreeNode* del = nullptr;
		TreeNode* parent = nullptr;
		Search(root, num, del, parent);
		//如果没找到要删除的值 返回
		if (del == nullptr)return;

		TreeNode* mark = nullptr;
		//有两个孩子
		//mark找到左子树最大值
		if (del->left != nullptr && del->right != nullptr) {
			mark = del;
			parent = del;
			del = del->left;
			while (del->right) {
				parent = del;
				del = del->right;
			}
			//值覆盖
			mark->val = del->val;
		}

		//0个或1个
		//根
		if (parent == nullptr) {
			//换根
			root == del->left ? del->left : del->right;
			delete del;
			del = nullptr;
			return; 
		}
		//非根
		if (del == parent->left) {
			parent->left == del->left ? del->left : del->right;
		}
		else {
			parent->right = del->left ? del->left : del->right;
		}
		delete del;
		del = nullptr;
	}
	//将BST转换为双向链表
	LinkNode* Transformation(TreeNode*& root,LinkNode*& head,LinkNode*& tail) {
		if (root == nullptr)return nullptr;
		TreeNode* cur = root;
		stack<TreeNode*>s;
		while (cur != nullptr || !s.empty()) {
			while (cur != nullptr) {
				s.push(cur);
				cur = cur->left;
			}
			cur = s.top();
			s.pop();
			LinkNode* Node = new LinkNode(cur->val);
			if (head == nullptr) {
				head = Node;
				tail = Node;
			}
			else {
				tail->next = Node;
				Node->prev = tail;
				tail = Node;
			}

			cur = cur->right;
		}
		return head;
	}
};

//void heapify(vector<int>nums,int size,int root) {
//	int largest = root;
//	int left = 2 * root + 1;
//	int right = 2 * root + 2;
//	if (left <  size&& nums[left] > nums[largest]) {
//		largest = left;
//	}
//	if (right < size && nums[right] > nums[largest]) {
//		largest = right;
//	}
//	//largest不等于root了 说明孩子结点的值是大于根节点的
//	if (largest != root) {
//		//交换孩子节点与根节点
//		swap(nums[root], nums[largest]);
//		heapify(nums, size, largest);
//	}
//}
//
//void heapSort(vector<int>nums) {
//	int len = nums.size();
//	//先把大顶堆构建出来 然后才能执行下面的操作
//	for (int i = len/2-1; i >=0; i--) {
//		heapify(nums, len, i);
//	}
//
//	//大顶堆构建完成 可以取最大值 并继续调整
//	for (int i = len - 1; i > 0; i--) {
//		swap(nums[0], nums[i]);
//		heapify(nums, i, 0);
//	}
//}

int main(){
	vector<int>nums = { 8,2,3,5,6,7,10,24,12 };
	BST bst;
	bst.CreateBST(nums);
	LinkedList l;
	bst.Transformation(bst.root, l.head, l.tail);
	l.Print();
	return 0;
}

//堆化
void heapify(vector<int>&nums, int size,int root) {
	int largest = root;
	int left = 2 * root + 1;
	int right = 2 * root + 2;
	if (left<size && nums[left] > nums[largest]) {
		largest = left;
	}
	if (right<size&&nums[right] > nums[largest]) {
		largest = right;
	}
	if (largest != root) {
		swap(nums[largest], nums[root]);
		heapify(nums, size, largest);
	}
}

void heapSort(vector<int>&nums) {
	int size = nums.size();
	for (int i = size / 2 - 1; i >= 0; i--) {
		heapify(nums, size, i);
	}
	for (int i = size - 1; i > 0; i--) {
		swap(nums[0], nums[i]);
		heapify(nums, size, 0);
	}
}