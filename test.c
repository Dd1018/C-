#define _CRT_SECURE_NO_WARNINGS
#include"Dlist.h"
int main()
{
	LTNode* plist = ListInit();
	ListPushBack(plist, 10);	
	ListPushBack(plist, 10);
	ListPushBack(plist, 30);
	ListPrint(plist);
	return 0;
}