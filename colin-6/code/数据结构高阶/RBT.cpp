#include<iostream>
#include<vector>

using namespace std;

enum COLOR { RED, BLACK };

class node
{
public:
	int value;
	node* parent;
	node* left;
	node* right;
	int col;

	node(int v):value(v), parent(nullptr),left(nullptr),right(nullptr),col(RED){}
};

class RBT
{
public:
	node* root;
	RBT():root(nullptr){}

	node* Find(int num)
	{
		if (root == nullptr) return nullptr;
		node* tmp = root;
		while (tmp)
		{
			if (tmp->value > num)
			{
				if (tmp->left == nullptr)
				{
					return tmp;
				}
				tmp = tmp->left;
			}
			else if (tmp->value < num) {
				if (tmp->right == nullptr)
				{
					return tmp;
				}
				tmp = tmp->right;
			}
			else
			{
				cout << "data error" << endl;
				return nullptr;
			}
		}
	}

	node* GetUncle(node* father) {
		if (father == father->parent->left) {
			return father->parent->right;
		}
		else {
			return father->parent->left;
		}
	}

	void AddNode(int num) {
		node* father = Find(num);

		node* tmp = new node(num);
		tmp->parent = father;

		if (father == nullptr) {
			tmp->col = BLACK;
			root = tmp;
			return;
		}

		if (father->value > num) {
			father->left = tmp;
		}
		else {
			father->right = tmp;
		}

		if (father->col == BLACK)return;

		node* grandpa = nullptr;
		node* uncle = nullptr;

		while (father->col == RED) {
			grandpa = father->parent;
			uncle = GetUncle(father);

			if (uncle != nullptr && uncle->col == RED) {
				father->col = BLACK;
				grandpa->col = RED;
				uncle->col = BLACK;

				tmp = grandpa;
				father = tmp->parent;

				if (father == nullptr)
				{
					root->col = BLACK;
					break;
				}
				continue;
			}

			if (uncle == nullptr || uncle->col == BLACK) {
				if (father == grandpa->left) {
					if (tmp == father->right) {
						tmp = father;
						LeftRotate(tmp);

						father = tmp->parent;
					}

					if (tmp == father->left)
					{
						father->col = BLACK;
						grandpa->col = RED;
						RightRotate(grandpa);
						break;
					}
				}

				if (father == grandpa->right)
				{
					if (tmp == father->left) {
						tmp = father;
						RightRotate(tmp);
						father = tmp->parent;
					}

					if (tmp == father->right) {
						father->col = BLACK;
						grandpa->col = RED;
						LeftRotate(grandpa);
						break;
					}
				}
			}
		}
	}

	node* Search(int num) {
		node* tmp = root;
		while (tmp) {
			if (tmp->value == num) {
				return tmp;
			}
			else if (tmp->value > num) {
				tmp = tmp->left;
			}
			else {
				tmp = tmp->right;
			}
		}
			return nullptr;
	}

	void DelNode(int num)
	{
		//查找
		node* tmp = Search(num);
		//不存在，空
		if (tmp == nullptr)
		{
			return;
		}
		//两个孩子
		node* mark = nullptr;
		if (tmp->left != nullptr && tmp->right != nullptr)
		{
			//找到左子树的最大值节点
			mark = tmp;
			tmp = tmp->left;
			while (tmp->right != nullptr)
			{
				tmp = tmp->right;
			}
			//替换
			mark->value = tmp->value;
		}
		//情况讨论
		node* father = tmp->parent;
		//删除节点是根节点
		if (father == nullptr)
		{
			//无子
			if (tmp->left == nullptr && tmp->right == nullptr)
			{
				delete tmp;
				tmp = nullptr;
				root = nullptr;
				return;
			}
			//有一个子
			else
			{
				root = tmp->left ? tmp->left : tmp->right;
				root->col = BLACK;
				root->parent = nullptr;
				delete tmp;
				tmp = nullptr;
				return;
			}
		}
		else
		{
			//红色
			if (tmp->col == RED)
			{
				if (tmp == father->left)
				{
					father->left = nullptr;
				}
				else
				{
					father->right = nullptr;
				}
				delete tmp;
				tmp = nullptr;
				return;
			}
			//黑色有一个子
			if (tmp->col == BLACK && (tmp->left != nullptr || tmp->right != nullptr))
			{
				if (tmp == father->left)
				{
					father->left = tmp->left ? tmp->left : tmp->right;
					father->left->col = BLACK;
					father->left->parent = father;
				}
				else
				{
					father->right = tmp->left ? tmp->left : tmp->right;
					father->right->col = BLACK;
					father->right->parent = father;
				}
				delete tmp;
				tmp = nullptr;
				return;
			}
			//黑色非根无子
			node* brother = GetUncle(tmp);
			//删除
			if (tmp == father->left)
			{
				father->left = nullptr;
			}
			else
			{
				father->right = nullptr;
			}
			delete tmp;
			tmp = nullptr;
			while (1)
			{
				//兄弟红色
				if (brother->col == RED)
				{
					father->col = RED;
					brother->col = BLACK;
					//看兄弟在父亲的左还是右
					if (brother == father->left)
					{
						RightRotate(father);
						brother = father->left;
						continue;
					}
					else
					{
						LeftRotate(father);
						brother = father->right;
						continue;
					}
				}
				//兄弟黑色
				if (brother->col == BLACK)
				{
					//两个侄子都是黑色
					if ((brother->left == nullptr && brother->right == nullptr) ||
						(brother->left != nullptr && brother->left->col == BLACK && brother->right != nullptr && brother->right->col == BLACK))
					{
						//父亲是红色
						if (father->col == RED)
						{
							brother->col = RED;
							father->col = BLACK;
							break;
						}
						//父亲是黑色
						if (father->col == BLACK)
						{
							brother->col = RED;
							tmp = father;
							father = tmp->parent;
							if (father == nullptr)
								//根节点
							{
								break;
							}
							brother = GetUncle(tmp);
							continue;
						}
					}
					//左侄子红色，右侄子黑色
					if (brother->left != nullptr && brother->left->col == RED && (brother->right == nullptr || brother->right->col == BLACK))
					{
						//看兄弟在父亲右
						if (brother == father->right)
						{
							brother->col = RED;
							brother->left->col = BLACK;
							RightRotate(brother);
							brother = father->right;
							continue;
						}
						//看兄弟在父亲左
						if (brother == father->left)
						{
							brother->col = father->col;
							father->col = BLACK;
							brother->left->col = BLACK;
							RightRotate(father);
							break;
						}

					}
					//右侄子红色
					if (brother->right != nullptr && brother->right->col == RED)
					{
						//看兄弟在父亲左
						if (brother == father->left)
						{
							brother->col = RED;
							brother->right->col = BLACK;
							LeftRotate(brother);
							brother = father->left;
							continue;
						}
						//看兄弟在父亲右
						if (brother == father->right)
						{
							brother->col = father->col;
							father->col = BLACK;
							brother->right->col = BLACK;
							LeftRotate(father);
							break;
						}

					}
				}
			}
		}

	}


	void CreateRBT(vector<int>& nums)
	{
		for (int v : nums) {
			AddNode(v);
		}
	}

	void RightRotate(node* tree) {
		if (tree == nullptr || tree->left == nullptr)return;

		node* mark = tree->left;

		tree->left = mark->right;

		mark->right = tree;

		if (tree->parent != nullptr) {
			if (tree == tree->parent->left) {
				tree->parent->left = mark;
			}
			else {
				tree->parent->right = mark;
			}
		}
		else {
			root = mark;
		}

		if (tree->left != nullptr) {
			tree->left->parent = tree;
		}


		mark->parent = tree->parent;
		tree->parent = mark;

	}

	void LeftRotate(node* tree) {
		if (tree == nullptr || tree->right == nullptr)return;

		node* mark = tree->right;

		tree->right = mark->left;

		mark->left = tree;

		if (tree->parent != nullptr) {
			if (tree == tree->parent->right) {
				tree->parent->right = mark;
			}
			else {
				tree->parent->left = mark;
			}
		}
		else {
			root = mark;
		}

		if (tree->right != nullptr) {
			tree->right->parent = tree;
		}


		mark->parent = tree->parent;
		tree->parent = mark;

	}

		void Preorder(node* tree){
		if (tree == nullptr) {
			return;
		}

		cout << "val----" << tree->value << "    col----" << tree->col << endl;;
		Preorder(tree->left);
		Preorder(tree->right);

	}
};

int main()
{

	//int val;
	//vector<int> values;
	//while (cin >> val) {
	//	values.push_back(val);
	//}
	RBT tree;
	vector<int>nums = { 11,2,14,1,7,15,5,8 };

	

	tree.CreateRBT(nums);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;
	//tree.AddNode(4);
	//tree.Preorder(tree.root);
	tree.DelNode(1);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	tree.DelNode(8);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	tree.DelNode(14);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	tree.DelNode(2);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	tree.DelNode(5);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	tree.DelNode(7);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	tree.DelNode(15);
	tree.Preorder(tree.root);
	cout << "-----------------------------------" << endl;

	return 0;
}