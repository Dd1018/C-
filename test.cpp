#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
namespace Key
{
	template<class K>
	class BStreeNode
	{
	public:
		BStreeNode(const K& key)
			:_left(nullptr),
			_right(nullptr),
			_key(key)
		{}
		BStreeNode<K>* _left;
		BStreeNode<K>* _right;
		K _key;
	};
	template<class K>
	class BStree
	{
		typedef BStreeNode<K> Node;
	public:
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}
		void InOrder()//排序
		{
			_InOrder(_root);
		}
		bool Find(const K& key)//查找
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}

			return true;
		}
		bool Erase(const K& key)//删除
		{
			//若有一个子节点，删除父节点后，让子节点填充
			//若有俩个子节点，父节点删除后
			//1.用左子树的最大节点替换父节点
			//2.或右子树的最小节点替换父节点
			Node* parent = nullptr;
			Node* cur = _root;

			while (cur)
			{
				if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else//找到了
				{
					if (cur->_left == nullptr)//如果要删除的节点左为空
					{
						if (cur == _root)//如果要删除的是根节点(这种情况根节点只有右子树，因为左为空)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)//判断要删除的节点是父亲的左节点还是右节点
							{
								parent->_left = cur->_right;
							}
							else
							{
								parent->_right = cur->_right;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else if (cur->_right == nullptr)//如果要删除的节点右为空
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)//判断要删除的节点是父亲的左节点还是右节点
							{
								parent->_left = cur->_left;
							}
							else
							{
								parent->_right = cur->_left;
							}
						}
						delete cur;
						cur = nullptr;
					}
					else//左右都为空，叶子节点,这里采用用右树的最小节点进行删除
					{
						Node* minParent = cur;
						Node* min = cur->_right;//cur是要删除的节点
						while (min->_left)//寻找最小节点
						{
							minParent = min;
							min = min->_left;
						}
						swap(cur->_key, min->_key);
						if (minParent->_left == min)
						{
							minParent->_left = min->_right;
						}
						else
							minParent->_right = min->_right;
						delete min;
					}
					return true;
				}
			}
			return false;
		}
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
		bool InsertR(const K& key)
		{
			return _InsertR(_root, key);
		}
		bool EraseR(const K& key)
		{
			return _Eraser(_root, key);
		}
		~BStree()
		{
			Destory(_root);
		}
		BStree()
		{}
		BStree(const BStree<K>& t)
		{
			_root = _Copy(t._root);
		}
		BStree<K>& operator=(BStree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}
	private:
		Node* _Copy(Node* root)
		{
			if (root == nullptr)
			{
				return nullptr;
			}
			Node* copyRoot = new Node(root->_key);
			copyRoot->_left = _Copy(root->_left);
			copyRoot->_right = _Copy(root->_right);
			return copyRoot;
		}
		void Destory(Node*& root)//采用引用可让root置空起作用
		{
			if (root == nullptr)
				return;
			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root = nullptr;
		}
		bool _Eraser(Node*& root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
			{
				return _Eraser(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _Eraser(root->_left, key);
			}
			else
			{
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;//由于是引用，可直接这样将二叉树连接起来
				}
				else
				{
					//找右树的最左节点
					Node* min = root->_right;
					while (min->_left)
					{
						min = min->_left;
					}
					swap(root->_key, min->_key);
					return _Eraser(root->_right, key);
				}
				delete del;
				return true;
			}
		}
		bool _InsertR(Node*& root, const K& key)
		{
			if (root == nullptr)//根为空，直接插入
			{
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return false;
			}
		}
		bool _FindR(Node* root, const K& key)
		{
			if (root == nullptr)
				return false;
			if (root->_key < key)
			{
				return _FindR(root->right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->left, key);
			}
			else
			{
				return true;
			}
		}
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};
	int main()
	{
		BStree<int> t;
		int a[] = { 1,1,2,2,3,6,165,132,4185,123 };
		for (auto e : a)
		{
			t.Insert(e);
		}
		BStree<int> copy = t;
		copy.InOrder();
		t.InOrder();
		BStree<int> t1;
		t1.Insert(2);
		t1.Insert(1);
		t1.Insert(3);
		copy = t1;
		copy.InOrder();
		cout << endl;
		t1.InOrder();
		cout << endl;
		return 0;
	}
}
namespace KeyValue
{
	template<class K, class V>
	struct BSTreeNode
	{
		BSTreeNode<K, V>* _left;//Key和Value绑到一起
		BSTreeNode<K, V>* _right;
		K _key;
		V _value;

		BSTreeNode(const K& key, const V& value)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
			, _value(value)
		{}
	};

	template<class K, class V>
	class BSTree
	{
		typedef BSTreeNode<K, V> Node;
	public:
		bool Insert(const K& key, const V& value)
		{
			if (_root == nullptr)
			{
				_root = new Node(key, value);
				return true;
			}

			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else
				{
					return false;
				}
			}

			cur = new Node(key, value);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else
			{
				parent->_left = cur;
			}

			return true;
		}

		Node* Find(const K& key)//查找的时候以K去查找，返回的时候返回节点指针，以便于修改
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return cur;
				}
			}

			return nullptr;
		}

		bool Erase(const K& key)//用K删除
		{
			//...

			return true;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
	private:

		void _InOrder(Node* root)
		{
			if (root == nullptr)
			{
				return;
			}

			_InOrder(root->_left);
			cout << root->_key << ":" << root->_value << endl;
			_InOrder(root->_right);
		}
	private:
		Node* _root = nullptr;
	};

	void TestBSTree1()
	{
		BSTree<string, string> dict;
		dict.Insert("sort", "排序");
		dict.Insert("left", "左边");
		dict.Insert("right", "右边");
		dict.Insert("string", "字符串");
		dict.Insert("insert", "插入");
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret)
			{
				cout << "对应的中文:" << ret->_value << endl;
			}
			else
			{
				cout << "对应的中文->无此单词" << endl;
			}
		}
	}

	void TestBSTree2()
	{
		string arr[] = { "香蕉", "苹果", "香蕉", "草莓", "香蕉", "苹果", "苹果", "苹果" };

		BSTree<string, int> countTree;
		for (auto& str : arr)
		{
			//BSTreeNode<string, int>* ret = countTree.Find(str);
			auto ret = countTree.Find(str);
			if (ret)
			{
				ret->_value++;
			}
			else
			{
				countTree.Insert(str, 1);
			}
		}

		countTree.InOrder();
	}
}
#include<iostream>
#include<vector>
#include<set>
#include<math.h>
using namespace std;

void get_yue_shu(int n, vector<int>& a) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			a.push_back(i);
			if (n / i != i)
				a.push_back(n / i);
		}
	}
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> res(m + 1, 0);
		res[n] = 1;
		for (int i = n; i <= m; i++) {
			vector<int>a;
			//位置i无法到达，跳过
			if (res[i] == 0)
				continue;
			get_yue_shu(i, a);
			//记录从起点到i的最小步数
			for (int j = 0; j < a.size(); j++) {
				//由点i出发能到达的点
				if ((a[j] + i) <= m && res[a[j] + i] != 0)
					//其它点也能到达，比较大小，记录最小步数
					res[a[j] + i] = min(res[a[j] + i], res[i] + 1);
				else if ((a[j] + i) <= m)
					//到达点i的最小步数加1
					res[a[j] + i] = res[i] + 1;
			}
		}
		if (res[m] == 0)
			cout << -1 << endl;
		else
			cout << res[m] - 1 << endl;
	}
	return 0;
}