//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<utility>
//using namespace std;
//
//class TreeNode {
//public:
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	//构造函数
//	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {};
//};
//
//class BinaryTree {
//public:
//	TreeNode* root;
//	BinaryTree() :root(nullptr) {};
//
//	//创建树
//	void CreateBinaryTree() {
//		root = new TreeNode(1);
//		root->left = new TreeNode(2);
//		root->left->left = new TreeNode(4);
//		root->left->right = new TreeNode(5);
//		root->right = new TreeNode(3);
//	}
//
//	void PreorderTraversal(){
//		if (root == nullptr)return;
//		TreeNode* tree = root;
//		stack<TreeNode*>s;
//		while (tree!=nullptr||!s.empty()) {
//			if (tree != nullptr) {
//				cout << tree->val << " ";
//				s.push(tree);
//				tree = tree->left;
//			}
//			else {
//				if (s.empty())break;
//				tree = s.top()->right;
//				s.pop();
//			}
//		}
//	}
//
//	void InorderTraversal() {
//		if (root == nullptr)return;
//		TreeNode* cur = root;
//		stack<TreeNode*>s;
//		while (cur != nullptr || !s.empty()) {
//			while (cur != nullptr) {
//				s.push(cur);
//				cur = cur->left;
//			}
//			cur = s.top();
//			s.pop();
//			cout << cur->val << " ";
//
//			cur = cur->right;
//		}
//	}
//
//	void LastorderTraversal() {
//		if (root == nullptr)return;
//		TreeNode* cur = root;
//		stack<TreeNode*>s;
//		TreeNode* flag = nullptr;
//		while (cur!=nullptr||!s.empty()) {
//			//非空
//
//			if (cur != nullptr) {
//				s.push(cur);
//				cur = cur->left;
//			}
//			else{
//				if (s.empty())break;
//				//检查栈顶元素的右子树
//				if (s.top()->right == nullptr || s.top()->right == flag) {
//					//弹出 打印 标记
//					cout << s.top()->val << " ";
//					flag = s.top();
//					s.pop();
//				}
//				else {
//					//右子树
//					cur = s.top()->right;
//				}
//			}
//		}
//		cout << endl;
//	}
//};
//
//int main(){
//
//}