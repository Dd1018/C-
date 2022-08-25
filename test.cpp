#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Date
{
public:
	Date(int year, int month , int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year ;   // ע�����ﲻ�ǳ�ʼ������ȱʡֵ
	int _month ;
	int _day ;
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
private:
	DataType* _array;
	int _capacity;
	int _size;
};

// C++���ͷ��ࣺ
// ��������/�������ͣ�int/double/char/ָ��ȵ� 
// �Զ������ͣ�struct/class

class MyQueue
{
private:
	Stack _st1;
	Stack _st2;
};
int main()
{
	Date a;
	return 0;
}