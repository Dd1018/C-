#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
void test_string1()
{
	string s1;
	string s2("hello");
	cout << s1 << endl;
	cout <<s2 << endl;
	string s3(s2);
	cout << s3 << endl;
	string s4(s3, 2, 1);
	cout << s4<< endl;
	string s5(s3, 2, 100);
	cout << s5 << endl;
	string s6("what's your name", 5);
	cout << s6 << endl;
	string s7(100, 'a');
	cout << s7 << endl;
	string s8 = "hello world";
	cout << s8 << endl;
}
void test_string2()
{
	string s1 ;
	string s2 = "hello world";
	s1 = s2;
	cout << s1 << endl;
	s1 = "xxxxxx";
	cout << s1 << endl;
	s1 = 'a';
	cout << s1 << endl;
}
void test_string3()
{
	string s1("hello world");
	cout << s1.at(0) << endl;
	for (int i = 0; i < s1.size(); ++i)
	{
		cout << s1.at(i) << " ";
	}
}
class Solution {
public:
	bool Isletters(char a)
	{
		if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		{
			return true;
		}
		return false;
	}
	string reverseOnlyLetters(string s) {
		size_t begin = 0;
		size_t end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end)
			{
				while (Isletters(s[begin]) && Isletters(s[end]))
				{
					swap(s[begin], s[end]);
					begin++; end--;
				}
				if (Isletters(s[begin]))
					end--;
				else
					begin++;
			}
		}
	}
};
void test_string4()
{
	string s("hello");
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
}
void PrintSring(const string& str)
{
auto it = str.cbegin();//const begin
	while (it != str.cend())
	{
		cout << *it;
		it++;
	}
	cout << endl;
}
void test_string5()
{
	string s("hello");
	string::const_reverse_iterator rit = s.rbegin();

	PrintSring(s);
}
void test_string6()
{
	string s("hello ");
	size_t sz = s.capacity();
	//s.reserve(1000);
	s.resize(1000);
	cout << "capacity changed: " << sz << '\n';
	cout << "making s grow:\n";
	for (int i = 0; i < 1000; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
int main()
{
	printf("%d", 10 % 10);
	return 0;
}