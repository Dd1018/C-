#define _CRT_SECURE_NO_WARNINGS
//void Test()
//{
//	// ��̬����һ��int���͵Ŀռ�
//	int* ptr4 = new int;
//	// ��̬����һ��int���͵Ŀռ䲢��ʼ��Ϊ10
//	int* ptr5 = new int(10);
//	// ��̬����10��int���͵Ŀռ�
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
operator delete: �ú���������ͨ��free���ͷſռ��
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
//free��ʵ��
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
//// ����operator delete��������ռ�ʱ����ӡ���ĸ��ļ����ĸ��������ڶ����У������˶��ٸ�
//void* operator new(size_t size, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	void* p = ::operator new(size);
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p << "-"
//		<< size << endl;
//	return p;
//}
//// ����operator delete�����ͷſռ�ʱ����ӡ���Ǹ��ļ����ĸ��������ڶ������ͷ�
//void operator delete(void* p, const char* fileName, const char* funcName,
//	size_t lineNo)
//{
//	cout << fileName << "-" << funcName << "-" << lineNo << "-" << p <<
//		endl;
//	::operator delete(p);
//}
//// ����������Ȼ̫�鷳�ˣ�����ʹ�ú�Ե��ý��м�
//// ֻ����Debug��ʽ�£��ŵ����û����ص� operator new �� operator delete
//#ifdef _DEBUG
//#define new new(__FILE__, __FUNCTION__, __LINE__)
//#define delete(p) operator delete(p, __FILE__, __FUNCTION__, __LINE__)
//#endif
//int main()
//{
//	// �����ص�operator new �� operator delete���е���
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
//	// �ڴ��
//	static allocator<ListNode> alloc;
//
//	void* operator new(size_t n)
//	{
//		cout << "operator new -> STL�ڴ��allocator����" << endl;
//		void* obj = alloc.allocate(1);
//		return obj;
//	}
//
//	void operator delete(void* ptr)
//	{
//		cout << "operator delete -> STL�ڴ��allocator����" << endl;
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
//// allocator�Ժ�ὲ�������Ȼ��ü���
//allocator<ListNode> ListNode::alloc;

int main()
{
	// Ƶ������ListNode. �����Ч�� -- ����ListNodeʱ����ȥmalloc�������Լ������ڴ��
	ListNode* node1 = new ListNode(1);
	ListNode* node2 = new ListNode(2);
	ListNode* node3 = new ListNode(3);

	delete node1;
	//delete node2;
	delete node3;

	return 0;
}