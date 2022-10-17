#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
//
//class Person
//{
//public:
//	//Person(const char* name = "peter")
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//protected:
//	string _name; // 姓名
//};
//
//class Student : public Person
//{
//public:
//	Student(const char* name, int num)
//		:Person(name)
//		, _num(num)
//	{
//		cout << "Student()" << endl;
//	}
//
//	Student(const Student& s)
//		:Person(s)
//		, _num(s._num)
//	{
//		cout << "Student(const Student& s)" << endl;
//	}
//
//	Student& operator=(const Student& s)
//	{
//		if (this != &s)
//		{
//			Person::operator=(s);
//
//			_num = s._num;
//		}
//
//		cout << "Student& operator=(const Student& s)" << endl;
//
//		return *this;
//	}
//
//protected:
//	int _num;
//};
//
//
//int main()
//{
//	Student s1("张三", 1);
//
//	//Student s2(s1);
//	Student s2 = s1;
//
//	Student s3("李四", 2);
//
//	s1 = s3;
//
//	cout << &s1 << endl;
//
//	return 0;
//}
//class Time
//{
//	friend class Date; 
//public:
//	Time(int hour=1, int minute=1, int second=1)
//		: _hour(hour)
//		, _minute(minute)
//		, _second(second)
//	{}
//	void fun()
//	{
//		s._year = 1;
//	}
//private:
//	int _hour;
//	int _minute;
//	int _second;
//	Date s;
//};
//class Date
//{
//public:
//	Date(int year = 1900, int month = 1, int day = 1)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	void SetTimeOfDate(int hour, int minute, int second)
//	{
//		_t._hour = hour;
//		_t._minute = minute;
//		_t._second = second;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	Time _t;
//};
//class Person
//{
//public:
//	Person(const char* name)
//		: _name(name)
//	{
//		cout << "Person()" << endl;
//	}
//	Person(const Person& p)
//		: _name(p._name)
//	{
//		cout << "Person(const Person& p)" << endl;
//	}
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//			_name = p._name;
//		return *this;
//	}
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name; // 姓名
//};
//class Student : public Person
//	{
//	public:
//		Student(const char* name="peter", int num=1)
//			:Person(name),
//			_num(num)
//		{
//
//		}
//		Student(const Student&s)
//			:Person(s)//赋值转换，切片
//             ,_num(s._num)
//		{}
//		Student& operator=(const Student& s)
//		{
//			if (this != &s)//指针
//			{
//				Person::operator=(s);//父类赋值
//				_num = s._num;
//			}
//			return *this;
//		}
//		~Student()
//		{
//			cout << "~Student()" << endl;
//		
//		}
//	protected:
//		int _num;
//	};
//class Person
//{
//public:
//	Person() { ++_count; }
//protected:
//	string _name; // 姓名
//public:
//	static int _count; // 统计人的个数。
//};
//int Person::_count = 0;
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//class Graduate : public Student
//{
//protected:
//	string _seminarCourse; // 研究科目
//};
//void TestPerson()
//{
//	Student s1;//++一次
//	Student s2;//++一次
//	Student s3;//++一次
//	Graduate s4;//++一次
//	cout << " 人数 :" << Person::_count << endl;
//	Student::_count = 0;
//	cout << " 人数 :" << Person::_count << endl;
//}
//int main()
//{
//	TestPerson();
//	return 0;
//}
//#include<string>
//class Student;
//class Person
//{
//public:
//	friend void Display(const Person& p, const Student& s);
//protected:
//	string _name; // 姓名
//};
//class Student : public Person
//{
//protected:
//	int _stuNum; // 学号
//};
//void Display(const Person& p, const Student& s)
//{
//	cout << p._name << endl;
//}
//class Base1 { public: int _b1; };
//class Base2 { public: int _b2; };
//					class Derive : public Base1, public Base2 { public: int _d; };
//					int main() {
//						Derive d;
//						Base1* p1 = &d;
//						Base2* p2 = &d;
//						Derive* p3 = &d;
////						return 0;
////					}
//class Person
//{
//public:
//	string _name; // 姓名
//};
//class Student :virtual public Person
//{
//protected:
//	int _num; //学号
//};
//class Teacher :virtual public Person
//{
//protected:
//	int _id; // 职工编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse; // 主修课程
//};
//void Test()
//{
//
//	Assistant a;
//
//	a._name = "www";
//	a.Student::_name = "xxx";
//	a.Teacher::_name = "yyy";
//}
class A
{
public:
	int _a;
};

//class B : public A
class B : virtual public A
{
public:
	int _b;
};

//class C : public A
class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};
int main()
{
	B b;
	b._a = 1;
	b._b = 2;
	cout << sizeof B;
	return 0;
}
