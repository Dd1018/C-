#define _CRT_SECURE_NO_WARNINGS
//void Test()
//{
//	// 动态申请一个int类型的空间
//	int* ptr4 = new int;
//	// 动态申请一个int类型的空间并初始化为10
//	int* ptr5 = new int(10);
//	// 动态申请10个int类型的空间
//	int* ptr6 = new int[3]{1,2,3};
//	delete ptr4;
//	delete ptr5;
//	delete[] ptr6;
//}
#include<iostream>
using namespace std;
//class A
//{
//public:
//	A(int a=0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//	A(const A& d)
//	{
//		cout << "A(const A& d):" << this << endl;
//	}
//
//private:
//	int _a;
//};
/*
operator delete: 该函数最终是通过free来释放空间的
*/
//void operator delete(void* pUserData)
//{
//	_CrtMemBlockHeader* pHead;
//	RTCCALLBACK(_RTC_Free_hook, (pUserData, 0));
//	if (pUserData == NULL)
//		return;
//	_mlock(_HEAP_LOCK); /* block other threads */
//	__TRY
//		/* get a pointer to memory block header */
//		pHead = pHdr(pUserData);
//	/* verify block type */
//	_ASSERTE(_BLOCK_TYPE_IS_VALID(pHead->nBlockUse));
//	_free_dbg(pUserData, pHead->nBlockUse);
//	__FINALLY
//		_munlock(_HEAP_LOCK); /* release other threads */
//	__END_TRY_FINALLY
//		return;
//}
///*
//free的实现
//*/
//#define free(p) _free_dbg(p, _NORMAL_BLOCK)
//int main()
////{
////	char* p2 = (char*)operator new(1024 * 1024);
////	return 0;
////}
// class A
//{
//public:
//	A(int a=0)
//		: _a(a)
//	{
//		cout << "A():" << this << endl;
//	}
//
//	~A()
//	{
//		cout << "~A():" << this << endl;
//	}
//	A(const A& d)
//	{
//		cout << "A(const A& d):" << this << endl;
//	}
//
//private:
//	int _a;
//};
//// 重载operator delete，在申请空间时：打印在哪个文件、哪个函数、第多少行，申请了多少个
//void* operator new(size_t size, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-"
//		<< size << endl;
//	return p;
//}
//// 重载operator delete，在释放空间时：打印再那个文件、哪个函数、第多少行释放
//void operator delete(void* p, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p <<
//		endl;
//	::operator delete(p);
//}
//// 上述调用显然太麻烦了，可以使用宏对调用进行简化
//// 只有在Debug方式下，才调用用户重载的 operator new 和 operator delete
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//int main()
//{
//	// 对重载的operator new 和 operator delete进行调用
//	A* p1 = new A;
//	A *p2 = new A;
//	A* p3 = new A;
//	A* p4 = new A;
//	A* p5 = new A;
//	A* p6 = new A;
//	delete p1;
//	delete p2;
//	delete p3;
//	delete p4;
////	delete p5;
////	delete p6;
////	return 0;
////}
//struct ListNode
//{
//	int _val;
//	ListNode* _next;
//
//	// 内存池
//	static allocator<ListNode> alloc;
//
//	void* operator new(size_t n)
//	{
//		cout << "operator new -> STL内存池allocator申请" << endl;
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete -> STL内存池allocator申请" << endl;
//
//		alloc.deallocate((ListNode*)ptr, 1);
//	}
//
//	struct ListNode(int val)
//		:_val(val)
//		, _next(nullptr)
//	{}
//};
//
//// allocator以后会讲，现在先会用即可
//allocator<ListNode> ListNode::alloc;

int main()
{
	// 频繁申请ListNode. 想提高效率 -- 申请ListNode时，不去malloc，而是自己定制内存池
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);

	delete node1;
	//delete node2;
	delete node3;

	return 0;
}