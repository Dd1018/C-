#define _CRT_SECURE_NO_WARNINGS
#include"date.h"
bool Date::operator==(const Date& d)
{
	return _year == d._year &&
		_month == d._month &&
		_day == d._day;
}
bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}
bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
		return false;
}
bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator>=(const Date& d)
{
	return (*this > d) || (*this == d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}
// ����Ҫ�ı�
Date&  Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= -day;
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_month = 1;
			_year ++;
		}
	}
	return *this;
}
//�����ı�
Date  Date::operator+(int day)
{
	Date ret(*this);//��������
	//Date ret= *this;�������������ǿ������죬��*this��ʼ��ret���Ѿ����ڵĶ��߲��Ǹ�ֵ
	ret += day;
	return ret;//��ֵ���ص�ʱ�򣬻�����һ�ݿ���
}
void  Date::Print()
{
	cout << _year<<"/" << _month<<"/"<<_day << endl;
}
Date& Date::operator++()//ǰ��
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)//����,����++֮ǰ��ֵ
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}
Date& Date::operator-= (int day)
{
	if (day < 0)
	{
		return *this += -day;
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
		_day += GetMonthDay(_year,_month);
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date ret = *this;
	ret -= day;
	return ret;
}
Date& Date::operator--()//ǰ��--
{
	*this -= 1;
	return *this;
}
Date   Date::operator--(int)//����--
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
int  Date::operator-(const Date& d)//�������
{
	int flag = 1;
	Date max = *this;
	Date min = d;
	if (*this < d)
	{
		min = *this;
		max = d;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n*flag;
}

//void Date::operator<<(ostream& out)
//{
//	out << _year << "-" << _month <<"-" << _day;
//}
