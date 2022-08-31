#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
//class Time
//{
//public:
//	Time(int hour)
//	{
//		_hour = hour;
//	}
//private:
//	int _hour;
//};
//class Date
//{
//public:
//
//	Date(int year, int month, int day,int x)
//		:_t(day)
//		, _N(100)
//		,a(x)
//
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	Time _t;
//	int _year; // 年
//	int _month; // 月
//	int _day; // 日
//	const int _N;
//	int& a;
//};
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
//int main() {
//	A aa(1);
//	aa.Print();
//}
//class Date
//{
//public:
	//Date(int year)
	//{
	//	cout << "Date(int year)" << endl;
	//}
 //Date(const Date& d)
	//{
	//	cout << "Date(const Date& d)" << endl;
//	//}
// //~Date()
// //{
//	// cout << "Date(const Date& d)" << endl;
// //}
//	class Date
//	{
//	public:
// void Print()
// {
//	 cout << " Print()" << endl;
// }
//	 // explicit修饰构造函数，禁止类型转换
// explicit Date(int year, int month = 1, int day = 1)
//	 : _year(year)
//	 , _month(month)
//	 , _day(day)
// {}
// 
//private:
//	int _year; // 年
//	int _month;
//	int _day;
//};
//class A
//{
//public:
//	A()
//	{ ++_scount; }
//
//	A(const A& t) { ++_scount; }
//	~A() { --_scount; }
//	static int GetACount() { return _scount; }
//	void Print()
//	{
//		cout << _scount << endl;
//	}
//	static int GetCount()
//	{
//		return _scount;
//	}
//private:
//	static int _scount;
//};
//int A::_scount = 1;
//int main()
//{
//	return 0;
//}
//class StackOnly
//{
//public:
//	static StackOnly CreatObj()
//	{
//		StackOnly so;
//		return so;
//	}
//private:
//	StackOnly(int x = 0,int y=0)
//		:_x(x),
//		_y(y)
//	{}
//private:
//	int _x = 0;
//	int _y = 0;
//};
//int main()
//{
//	StackOnly so;
//	return 0;
//}
class Time
{
	friend class Date; // 声明日期类为时间类的友元类，则在日期类中就直接访问Time类中的私有成员变量
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void SetTimeOfDate(int hour, int minute, int second)
	{
		// 直接访问时间类私有的成员变量
		_t._hour = hour;
		_t._minute = minute;
		_t._second = second;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
class A
{
private:
	int _h;
	static int a;
public:
	class B // B天生就是A的友元
	{
	public:
		void Print(const A& k)
		{
			cout << k.a << endl;
		}
	private:
		int _b;
	};
	B _b;
};
int A::a = 1;
int main()
{
	A::B b;
	return 0;
}