#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
using namespace std;

namespace my_space
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());

			return _start[pos];
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());

			return _start[pos];
		}

		size_t size() const
		{
			return _finish - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * sz);
					delete[] _start;
				}

				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		void push_back(const T& x)//加const防止隐式类型转换的中间常量传参错误，引用可避免深拷贝
		{
				if (_finish == _end_of_storage)
				{

					reserve(capacity() == 0 ? 4 : capacity() * 2);
				}

				*_finish = x;
				++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			--_finish;
		}
		void insert(iterator& pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			if (_finish == _end_of_storage)
			{
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			// 挪动数据
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;

			++_finish;
		}
		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}
			--_finish;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(4);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		auto it = v.begin();
		while (it != v.end())
		{
			if (*it % 2 == 0)
				v.erase(it);
			++it;
		}
		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;
	}
};
