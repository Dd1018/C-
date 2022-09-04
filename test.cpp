#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//using namespace std;
//class Date
//{
//    friend istream& operator>>(istream& in, Date& d);
//public:
//    Date(int year = 1, int month = 1, int day = 1)
//        :_year(year),
//        _month(month),
//        _day(day)
//    {}
//    int GetMonthDay(int year, int month)
//    {
//        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//        int day = days[month];
//        if (month == 2
//            && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
//        {
//            day += 1;
//        }
//        return day;
//    }
//    bool operator>(Date& d)
//    {
//        if (_year > d._year)
//            return true;
//        else if (_year == d._year && _month > d._month)
//            return true;
//        else if (_year == d._year && _month == d._month && _day > d._day)
//            return true;
//        else
//            return false;
//    }
//    bool operator==(Date& d)
//    {
//        if (_year == d._year && _month == d._month && _day == d._day)
//            return true;
//        else
//            return false;
//    }
//    bool operator<(Date& d)
//    {
//        return !(*this >d)&&!(*this==d);
//    }
//    Date operator+=(int day)
//    {
//        _day += day;
//        while (_day > GetMonthDay(_year, _month))
//        {
//            _day -= GetMonthDay(_year, _month);
//            _month++;
//            if (_month == 13)
//            {
//                _month = 1;
//                _year++;
//            }
//        }
//        return *this;
//    }
//int operator-(Date& d)
//{
//    Date max = *this;
//    Date min = d;
//    if (d > *this)
//    {
//        max = d;
//        min = *this;
//    }
//    int n = 0;
//    while (min < max)
//    {
//        n++;
//        min += 1;
//    }
//    return n;
//}
//
//    private:
//        int _year;
//        int _month;
//        int _day;
//};
//istream& operator>>(istream& in, Date& d)
//{
//    in >> d._year >> d._month >> d._day;
//    return in;
//}
//int main()
//{
//    Date d1;
//    cin >> d1;
//    Date d2;
//    cin >> d2;
//    int n = d1 - d2;
//    printf("%d", n);
//    return 0;
//}
#include<iostream>
using namespace std;
class Date
{
    friend istream& operator>>(istream& in, Date& d);
public:
    Date(int year = 1, int month = 1, int day = 0)
        :_year(year),
        _month(month),
        _day(day)
    {}
    int GetMonthDay(int year, int month)
    {
        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int day = days[month];
        if (month == 2
            && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            day += 1;
        }
        return day;
    }
    Date operator+(int day)
    {
        _day += day;
        while (_day > GetMonthDay(_year, _month))
        {
            _month++;
            if (_month == 13)
            {
                _year++;
                _month = 1;
            }
        }
        return *this;
    }
    void Print()
    {
        if (_month < 10 && _day >= 10)
            cout << _year << "-0" << _month << "-" << _day << endl;
        else if (_month >= 10 && _day < 10)
            cout << _year << "-" << _month << "-0" << _day << endl;
        else if (_month < 10 && _day < 10)
            cout << _year << "-0" << _month << "-0" << _day << endl;
        else
            cout << _year << "-" << _month << "-" << _day << endl;
    }
private:
    int _year;
    int _month;
    int _day;
};
istream& operator>>(istream& in, Date& d)
{
    in >> d._year >> d._month >> d._day;
    return in;
}
int main()
{
    while (1)
    {
        int year;
        int day;
        cin >> year >> day;
        Date d(year);
        d = d + day;
        d.Print();
    }
    return 0;
}