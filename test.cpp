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
		void InOrder()//����
		{
			_InOrder(_root);
		}
		bool Find(const K& key)//����
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
		bool Erase(const K& key)//ɾ��
		{
			//����һ���ӽڵ㣬ɾ�����ڵ�����ӽڵ����
			//���������ӽڵ㣬���ڵ�ɾ����
			//1.�������������ڵ��滻���ڵ�
			//2.������������С�ڵ��滻���ڵ�
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
				else//�ҵ���
				{
					if (cur->_left == nullptr)//���Ҫɾ���Ľڵ���Ϊ��
					{
						if (cur == _root)//���Ҫɾ�����Ǹ��ڵ�(����������ڵ�ֻ������������Ϊ��Ϊ��)
						{
							_root = cur->_right;
						}
						else
						{
							if (cur == parent->_left)//�ж�Ҫɾ���Ľڵ��Ǹ��׵���ڵ㻹���ҽڵ�
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
					else if (cur->_right == nullptr)//���Ҫɾ���Ľڵ���Ϊ��
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (cur == parent->_left)//�ж�Ҫɾ���Ľڵ��Ǹ��׵���ڵ㻹���ҽڵ�
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
					else//���Ҷ�Ϊ�գ�Ҷ�ӽڵ�,�����������������С�ڵ����ɾ��
					{
						Node* minParent = cur;
						Node* min = cur->_right;//cur��Ҫɾ���Ľڵ�
						while (min->_left)//Ѱ����С�ڵ�
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
		void Destory(Node*& root)//�������ÿ���root�ÿ�������
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
					root = root->_left;//���������ã���ֱ����������������������
				}
				else
				{
					//������������ڵ�
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
			if (root == nullptr)//��Ϊ�գ�ֱ�Ӳ���
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
		BSTreeNode<K, V>* _left;//Key��Value��һ��
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

		Node* Find(const K& key)//���ҵ�ʱ����Kȥ���ң����ص�ʱ�򷵻ؽڵ�ָ�룬�Ա����޸�
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

		bool Erase(const K& key)//��Kɾ��
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
		dict.Insert("sort", "����");
		dict.Insert("left", "���");
		dict.Insert("right", "�ұ�");
		dict.Insert("string", "�ַ���");
		dict.Insert("insert", "����");
		string str;
		while (cin >> str)
		{
			BSTreeNode<string, string>* ret = dict.Find(str);
			if (ret)
			{
				cout << "��Ӧ������:" << ret->_value << endl;
			}
			else
			{
				cout << "��Ӧ������->�޴˵���" << endl;
			}
		}
	}

	void TestBSTree2()
	{
		string arr[] = { "�㽶", "ƻ��", "�㽶", "��ݮ", "�㽶", "ƻ��", "ƻ��", "ƻ��" };

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
			//λ��i�޷��������
			if (res[i] == 0)
				continue;
			get_yue_shu(i, a);
			//��¼����㵽i����С����
			for (int j = 0; j < a.size(); j++) {
				//�ɵ�i�����ܵ���ĵ�
				if ((a[j] + i) <= m && res[a[j] + i] != 0)
					//������Ҳ�ܵ���Ƚϴ�С����¼��С����
					res[a[j] + i] = min(res[a[j] + i], res[i] + 1);
				else if ((a[j] + i) <= m)
					//�����i����С������1
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