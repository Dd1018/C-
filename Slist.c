#define _CRT_SECURE_NO_WARNINGS
#include"Slist.h"
void SListprint(SLTNode* phead)
{
	//phead可能会为空这里不需要断言
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}

}
SLTNode* BuySLTnode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newnode == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
void SListpushfront(SLTNode**pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTnode(x);
	newnode->next =*pphead;
	*pphead = newnode;
}
void SListpushback(SLTNode** pphead, SLTDataType x)
{
	//pphead不可能为空，pphead是plist的地址，pphead永远不为空
	//1.链表为空
	SLTNode* newnode = BuySLTnode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	//2.不为空
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail =tail->next;
		}
		tail->next = newnode;
	}
}
void SListpopfront(SLTNode** pphead)//头删
{
	if (*pphead == NULL)
	{
		return;
	}
	SLTNode* del = *pphead;
	*pphead = (*pphead)->next;
	free(del);//删除第一个节点 
	del = NULL;
}
void SListpopback(SLTNode** pphead)
{
	if (*pphead == NULL)
		return;
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* prev = NULL;
		SLTNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		prev->next = NULL;
		free(tail);
		tail = NULL;
	}
}
void SListDestory(SLTNode** pphead)//用二级指针会更好
{

	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}
SLTNode *SListFind(SLTNode** pphead, SLTDataType x)
{
	SLTNode* cur = *pphead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);
	if (pos == *pphead)
	{
		SListpushfront(pphead, x);
	}
	else
	{
		SLTNode* prve = *pphead;
		while (prve->next != pos)
		{
			prve = prve->next;
			assert(prve);//找不到
		}
		SLTNode* newnode = BuySLTnode(x);
		prve->next = newnode;
		newnode->next = pos;
	}
}
void SListInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	SLTNode* newnode = BuySLTnode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}