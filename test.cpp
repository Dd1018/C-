#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>

using namespace std;
//void test1()
//{
//	vector<int> v1;
//	vector<int> v2(10, 1);
//	vector<int> v3(v2);
//	v1.push_back(1);
//	v1.push_back(2);
//	v1.push_back(3);
//	v1.push_back(4);
//	v1.push_back(5);
//	v1.push_back(6);
//	for (size_t i = 0; i < v1.size(); ++i)
//	{
//		v1[i]++;
//		cout << v1[i] << " ";
//	}
//	cout << endl;
//	vector<int>::iterator it = v1.begin();
//	while (it != v1.end())
//	{
//		cout << *it << " ";
//		it++;
//	}
//	cout << endl;
//	for (auto ch : v1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
//	if (pos != v1.end())
//	{
//		v1.insert(pos, 30);
//	}
//	for (auto ch : v1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//}
//#include <algorithm>
//void test2()
//{
//	vector<int>v1;
//	v1.push_back(54);
//	v1.push_back(24);
//	v1.push_back(58);
//	v1.push_back(12);
//	v1.push_back(69);
//	v1.push_back(36);
//	v1.push_back(29);
//	v1.push_back(25);
//	v1.push_back(100);
//	sort(v1.begin(), v1.end());
//	for (auto ch : v1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	less<int> ls;
//	greater<int>gt;
//	sort(v1.begin(), v1.end(),gt);
//	for (auto ch : v1)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	string s("hello31313131244");
//	sort(s.begin(), s.end());
//	for (auto ch : s)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//	sort(s.begin(), s.end(),greater<char>());
//	for (auto ch : s)
//	{
//		cout << ch << " ";
//	}
//	cout << endl;
//}
class Date
{
public:
	string reverseStr(string s, int k) {
		int n = s.size() / 2 * k;
		int i;
		while (n)
		{
			int j = 0;
			for (i = j; i < 4; ++i)
			{
				;
			}
			reverse(s[i - 4], s[i - 3]);
			j += 4;
			n--;
		}
		return s;
	}
};
int main()
{
	Date s;
	s.reverseStr("abcdefg", 2);
	string s1;
	s1.reserve
	return 0;
}