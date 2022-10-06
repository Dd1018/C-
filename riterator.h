#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<vector>
#include<list>
namespace bit
{
	// ã
	template<class Iterator, class Ref, class Ptr>
	struct __reverse_iterator
	{
		Iterator _cur;
		typedef __reverse_iterator<Iterator, Ref, Ptr> RIterator;

		__reverse_iterator(Iterator it)
			:_cur(it)
		{}

		RIterator operator++()
		{
			--_cur;
			return *this;
		}

		RIterator operator--()
		{
			++_cur;
			return *this;
		}

		Ref operator*()
		{
			//return *_cur;
			auto tmp = _cur;
			--tmp;
			return *tmp;
		}

		Ptr operator->()
		{
			//return _cur.operator->();
			return &(operator*());
		}

		bool operator!=(const RIterator& it)
		{
			return _cur != it._cur;
		}
	};
}