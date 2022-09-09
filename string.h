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
				::swap(_str, tmp._str);//库里面的swap
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
		string& operator=(string s)
		{
			swap(s);
			return *this;
		}
		/*string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}*/
		string& operator+=(char* str)
		{
			append(str);
			return *this;
		}
		void append(const char* str)
		{
			/*size_t len=strlen(str);
			if (_size + len > _capacity)
			{
				reserve(_size + len);
			}
			strcpy(_str + _size, str);*/
			insert(_size, str);
		}
		void reserve(size_t n)//保留数据
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[]_str;
				_str = tmp;
				_capacity = n;
			}
		}
		void push_back(char ch)
		{
			/*if (_size==_capacity)
			{
				reserve(_capacity == 0 ? 4 : 2 * _capacity);
			}
			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';*/
			insert(_size, ch);
		}
		void append(const string& s)
		{
			append(s._str);
		}
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			reserve(_capacity==0?4:_capacity*2);
			size_t end = _size+1;
			while (end > pos)
			{
				_str[end ] = _str[end-1];
				end--;
			}
			_str[end] = ch;
			++_size;
			return *this;
		}
		string& insert(size_t pos,const char* str)
		{
			assert(pos<=_size);
			size_t len = strlen(str);
			if (_size +len> _capacity)
			{
				reserve(_size + len);
			}
			size_t end = _size+len;
			while (end >=pos+len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			strncpy(_str + pos, str, len);
			_size += len;
			return *this;
		}
		void erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			if (len == npos || pos + len >= _size)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + len + pos);
				_size -= len;
			}
		}
		size_t find(char ch,size_t pos=0);
		size_t find(const char*sub);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		 static size_t npos;
	};
	size_t string::npos = -1;
	ostream& operator<<(ostream& out, const string& s)
	{
		for (size_t i = 0; i < s.size(); ++i)
		{
			out << s[i];
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		//如果输入字符串很长,不断+=，频繁扩容，效率很低
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	void test_string1()
	{
		string s1("hello world");
		cout << s1;
	}
}