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
	bool operator==(const Date& x2)//�ж��Ƿ����
	{
		return _year == x2._year &&
			_month == x2._month &&
			_day == x2._day;
	}
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		//��ε��õ�ʱ��ÿ�ζ�Ҫ�������飬���ڸ�Ϊ��̬���ŵ���̬��

		if (month == 2
			&& ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))//����2��
		{
			return 29;
		}
		else
		{
			return days[month];
		}
	}
	Date operator+(int day)
	{
		Date ret(*this);
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year,ret._month))
		{
			ret._day -= GetMonthDay(ret._year,ret. _month);
			++ret._month;
			if (ret._month == 13)//12�����⴦��
			{
				ret._month = 1;
				ret._year++;
			}
		}
		return ret;
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
	Date d1(2022,7,23);
	Date ret = (d1 + 50);
	Date ret1(d1 + 50);
	return 0;
}