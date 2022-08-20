#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<assert.h>
#include <time.h>
// std是C++标准库的命名空间名，C++将标准库的定义实现都放到这个命名空间中
using namespace std;
//void Swap(int& left, int& right)
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}

//typedef struct SListNode
//{
//
//}SLTNode,*PL;
//
//void SlistPushBack(PL& phead, int x);//引用写法第二种
//struct A { int a[10000]; };
//
//void TestFunc1(A aa) {}
//void TestFunc2(A& aa) {}
//
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//int main()
//{
//	TestRefAndValue();
//	return 0;
//}
//int& Count()
//{
//	int n = 0;
//	n++;
//
//	 ...
//	return n;
//}
//
//int main()
//{
//	int& ret = Count();
//	printf("%d\n", ret);
//	printf("%d\n", ret);
//	cout << ret << endl;
//	cout << ret << endl;
//
//	return 0;
//}

typedef struct Seqlist
{
	int* a;
	int size;
	int capacity;
}SL;
void SLInit(SL& s, int capacity = 4)
{
	s.a = (int*)malloc(sizeof(int) * capacity);
	s.size = 0;
	s.capacity = capacity;
}
void SLPushBack(SL& s, int x)
{
	s.a[s.size++] = x;
}
//修改顺序表数据的函数
int& SLAt(SL& s, int pos)
{
	assert(pos >= 0 && pos <= s.size);
	return s.a[pos];
}
int main()
{
	SL sl;
	SLInit(sl);
	SLPushBack(sl, 1);
	SLPushBack(sl, 2);
	SLPushBack(sl, 3);
	SLPushBack(sl, 4);

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	SLAt(sl, 0)++;

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;

	SLAt(sl, 0) = 10;

	for (int i = 0; i < sl.size; ++i)
	{
		cout << SLAt(sl, i) << " ";
	}
	cout << endl;


	return 0;
}