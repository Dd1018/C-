#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string.h>
#include <iostream>
#include <string>
#include <list>
#include <assert.h>
#include<iostream>
using namespace std;
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		string(const char* str="")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		/*string()
			:_str(new char[1])
			, _size(0)
			, _capacity(0)
		{
			_str[0] = '\0';
		}*/
		size_t size()const
		{
			return _size;
		}
		const char& operator[](size_t pos)const
		{
			assert(pos < _size);
			return _str[pos];
		}
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}
		const char* c_str()const
		{
			return _str;
		}
		void swap(string& tmp)
		{
				::swap(_str, tmp._str);//¿âÀïÃæµÄswap
				::swap(_size, tmp._size);
				::swap(_capacity, tmp._capacity);
			}
		string(const string& s)
			:_str(nullptr),
			_size(0),
			_capacity(0)
		{
			string tmp(s._str);
			swap(tmp);//this->swap
		}
		~string()
		{
			delete[]_str;
			_str = nullptr;
			_size = _capacity = 0;
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(tmp);
			}
			return *this;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
	void test_string1()
	{
		string s1("hello world");
		string s2 = s1;
		cout << s1.c_str() << endl;
		cout << s1.c_str() << endl;
	}
}