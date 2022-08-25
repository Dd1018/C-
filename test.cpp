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
	int _year ;   // 注意这里不是初始化，给缺省值
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
			perror("malloc申请空间失败!!!");
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

// C++类型分类：
// 内置类型/基本类型：int/double/char/指针等等 
// 自定义类型：struct/class

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