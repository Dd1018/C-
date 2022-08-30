#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	//Date* operator&()
	//{
	//	return this;
	//}
	//const Date* operator&()const
	//{
	//	return this;
	//}
	void Print()const
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	Date()
	{

	}
private:
	int _year; // Äê
	int _month; // ÔÂ
	int _day; // ÈÕ
};
int i = 1;
int sum = 0;
class Sum
{
public:
	Sum()
	{
		sum += i;
		++i;
	}
};
class A
{
public:
	int Sum_A(int n)
	{
		Sum a[10];
		return sum;
	}
};
int main()
{
	A s1;
	s1.Sum_A(10);
	return 0;
}