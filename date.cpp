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
// 自身要改变
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
//自身不改变
Date  Date::operator+(int day)
{
	Date ret(*this);//拷贝构造
	//Date ret= *this;在这里，这条语句是拷贝构造，拿*this初始化ret，已经存在的对线才是赋值
	ret += day;
	return ret;//传值返回的时候，会生成一份拷贝
}
void  Date::Print()
{
	cout << _year<<"/" << _month<<"/"<<_day << endl;
}
Date& Date::operator++()//前置
{
	*this += 1;
	return *this;
}
Date Date::operator++(int)//后置,返回++之前的值
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
Date& Date::operator--()//前置--
{
	*this -= 1;
	return *this;
}
Date   Date::operator--(int)//后置--
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}
int  Date::operator-(const Date& d)//日期相减
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
