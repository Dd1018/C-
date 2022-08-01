#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>
struct ListNode {
	int val;
	struct ListNode* next;
	
};
struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;

    struct ListNode* newhead = NULL;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            newhead = slow->next;
            slow->next = NULL;
            break;
        }
    }
    struct ListNode* Guard = head;//统计个数
    struct ListNode* Guard1 = head;
    struct ListNode* Guard2 = newhead;//第二个链表
    int lenA = 1;
    int lenB = 1;
    while (Guard->next)
    {
        Guard = Guard->next;
        lenA++;
    }//统计个数，统计完Guard指向最后一个节点
    while (newhead->next)
    {
        newhead = newhead->next;
        lenB++;
    }//统计完指向最后一个节点
    int c = abs(lenA - lenB);
    while (c--)
    {
        if (lenA > lenB)
            Guard1 = Guard1->next;
        else
            Guard2 = Guard2->next;
    }
    while (Guard1 && Guard2)
    {
        if (Guard2 == Guard1)
            return  Guard1;
        else
        {
            Guard1 = Guard1->next;//从头开始
            Guard2 = Guard2->next;//从第二个节点开始
        }
    }
    return NULL;
}
int main()
{
struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n1);
struct ListNode* n2 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n2);
struct ListNode* n3 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n3);
struct ListNode* n4 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n4);
struct ListNode* n5 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n5);
struct ListNode* n6 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n6);
struct ListNode* n7 = (struct ListNode*)malloc(sizeof(struct ListNode));
assert(n7);

n1->next = n2;
n2->next = n3;
n3->next = n4;
n4->next = n2;

n1->val = 3;
n2->val = 2;
n3->val = 0;
n4->val = -4;

struct ListNode* head = detectCycle(n1);


return 0;
}