#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "���캯��" << endl;
	}
	//Date(const Date& d)//�������캯��
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year = 1;   // ע�����ﲻ�ǳ�ʼ������ȱʡֵ
	int _month = 1;
	int _day = 1;
};
typedef int DataType;
class Stack
{
public:
	Stack(int capacity=4)
	{
		cout << "Stack(int capacity = 4)" << endl;
		_array = (DataType*)malloc(sizeof(DataType) * capacity);
		if (NULL == _array)
		{
			perror("malloc����ռ�ʧ��!!!");
			return;
		}
		_size = 0;
		_capacity = capacity;
	}

	void Push(DataType data)
	{
		// CheckCapacity();
		_array[_size] = data;
		_size++;
	}
	~Stack()
	{
		cout << "~Stack()" << endl;
		free(_array);
		_capacity = _size = 0;
		_array = nullptr;
	}
private:
	DataType* _array;
	int _capacity;
	int _size;
};
class MyQueue
{
private:
	int _size;
	Stack _st1;
	Stack _st2;
};
void get1(Date d)//d1����ʱ����
{

}
void get2(Date& d)
{

}
void fun()
{
	Stack st;
	Stack st1(st);
}
int main()
{
	fun();
	return 0;
}