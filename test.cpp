#define _CRT_SECURE_NO_WARNINGS
#include<string>
#include<iostream>
using namespace std;
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//protected:
//	string _name = "peter"; // ����
//	int _age = 18; // ����
//};
//class Student :public Person
//{
//public:
//	void Set(const char* name, int age)
//	{
//		_name = name;
//		_age = age;
//	}
//protected:
//	int _stuid;//ѧ��
//
//};
// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111; // ���֤��
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ���֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999; // ѧ��
};
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
	{
		A::fun();
		cout << "func(int i)->" << i << endl;
	}
};
void Test()
{
	B b;
	b.A::fun();
};
int main()
{
	Test();
	return 0;
}