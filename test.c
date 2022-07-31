#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct ListNode
{
    int val;
   struct ListNode* next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prve = NULL;
    while (cur)
    {
        if (head->val == val)
        {
            if (head->next == NULL)
                head = NULL;
            else
            {
                head = head->next;
                cur = head;
            }
        }
        else
        {
            while (cur->val != val)
            {
                prve = cur;
                cur = cur->next;
            }
            if (cur->val == val)
            {
                prve->next = cur->next;
                cur = cur->next;
            }
        }
    }
    return head;
}
void Slistprint(struct ListNode*head)
{
    while (head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
}
struct ListNode* Buynewnode(int x)
{
   struct ListNode*newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
   newnode->val = x;
   newnode->next = NULL;
   return newnode;
}
void Pushfront(struct ListNode** head, int val)
{
    struct ListNode* newnode = Buynewnode(val);
    if (*head == NULL)
    {
        *head = newnode;
    }
    else
    {
       struct ListNode* cur = *head;
       while (cur->next!= NULL)
       {
           cur = cur->next;
       }
       cur->next = newnode;
    }
}
int main()
{
    struct ListNode* List = NULL;
    int i = 0;
    for (i = 1; i <=2; i++)
    {
        Pushfront(&List, i);
    }
    removeElements(&List, 1);
    Slistprint(List);
return 0;
}