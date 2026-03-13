#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	//构造函数
	TreeNode(int val) :val(val), left(nullptr), right(nullptr) {};
};

class BinaryTree {
public:
	TreeNode* root;
	BinaryTree() :root(nullptr) {};

	//创建树
	void CreateBinaryTree() {
		root = new TreeNode(1);
		root->left = new TreeNode(2);
		root->left->left = new TreeNode(4);
		root->left->right = new TreeNode(5);
		root->right = new TreeNode(3);
 	}
	//第二种创建树的方式
	void CreateBinaryTree2(TreeNode*& root,vector<int>nums,int& index) {
		    int num = nums[index++];
			if (num == -1) {
				root = nullptr;
				return;
			}
			root = new TreeNode(num);
			CreateBinaryTree2(root->left,nums,index);
			CreateBinaryTree2(root->right,nums,index);
	}
	TreeNode* VectorCreateBinaryTree(vector<int>nums) {
		int index = 0;
		TreeNode* root = nullptr;
		CreateBinaryTree2(root, nums, index);
		cout << "VectorCreateBinaryTree创建成功!" << endl;
		return root;
	}
	//创建完全二叉树
	TreeNode* CreateCompleteBinaryTree(vector<int>nums) {
		if (nums.empty())return nullptr;
		vector<TreeNode*>tn;
		tn.reserve(nums.size());
		for (int v : nums) {
			tn.push_back(new TreeNode(v));
		}
		int n = nums.size();
		for (int i = 0;i<n;i++) {
			int leftIdx = 2 * i + 1;
			int rightIdx = 2 * i + 2;
			if (leftIdx < n) {
				tn[i]->left = tn[leftIdx];
			}
			if (rightIdx < n) {
				tn[i]->right = tn[rightIdx];
			}
		}
		return tn[0];
	}
	// 前序(根)遍历
	void preorder(TreeNode* root) {
		if (root == nullptr) return;
		cout << root->val << " ";  // 访问根节点
		preorder(root->left);      // 遍历左子树
		preorder(root->right);     // 遍历右子树
	}

	// 中序(根)遍历
	void inorder(TreeNode* root) {
		if (root == nullptr) return;
		inorder(root->left);       // 遍历左子树
		cout << root->val << " ";  // 访问根节点
		inorder(root->right);      // 遍历右子树
	}

	// 后序(根)遍历
	void postorder(TreeNode* root) {
		if (root == nullptr) return;
		postorder(root->left);     // 遍历左子树
		postorder(root->right);    // 遍历右子树
		cout << root->val << " ";  // 访问根节点
	}
	//递归深度优先遍历
	void CreateCBT(vector<int>& nums)
	{
		int len = nums.size();
		if (len == 0)return;
		//申请节点数组
		vector<TreeNode*>tree(len, nullptr);
		for (int i = 0; i < len; i++)
		{
			tree[i] = new TreeNode(nums[i]);
		}

		//关联
		for (int i = 0; i < len / 2; i++)
		{
			if (2 * i + 1 < len)
			{
				tree[i]->left = tree[2 * i + 1];
			}
			if (2 * i + 2 < len)
			{
				tree[i]->right = tree[2 * i + 2];
			}
		}
		root = tree[0];
	}
	//广度优先遍历
	void LevelTraversal() {
		if (root == nullptr)return;
		queue<TreeNode*>q;

		q.push(root);

		while (!q.empty()) {
			cout << q.front()->val << " ";

			if (q.front()->left != nullptr) {
				q.push(q.front()->left);
			}
			if (q.front()->right != nullptr) {
				q.push(q.front()->right);
			}
			q.pop();
		}
	}
	//非递归深度优先遍历
	void NRDFTraversal()
	{
		TreeNode* cur = root;
		if (cur == nullptr)return;
		stack<TreeNode*>s;
		while (cur!=nullptr||!s.empty()) {
			//左子树
			while (cur != nullptr) {
				cout << cur->val << " ";
				s.push(cur);
				cur = cur->left;
			}
			//右子树
			if (!s.empty()) {
				cur = s.top();
				s.pop();
				cur = cur->right;
			}
		}
	}
};

int main()
{
	BinaryTree bt;
	vector<int>nums = { 10,12,3,-1,-1,5,-1,6,-1,-1,8,-1,1,-1,-1 };
	TreeNode* root = bt.VectorCreateBinaryTree(nums);
	bt.preorder(root);
	cout << endl;
	bt.inorder(root);
	cout << endl;
	bt.postorder(root);
	cout << endl;
	return 0;
}