#define _CRT_SECURE_NO_WARNINGS
#include"Stack.h"
void StackInit(ST* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->capacity = ps->top = 0;
}
void StackDestory(ST* ps)
{
	assert(ps);
	free(ps->data);
	ps->capacity = ps->top = 0;
	ps->data = NULL;
}
void StackPush(ST* ps, STDdtaTtype x)//ע��Ҫ��top��λ����0����-1
{
	assert(ps);
	int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
	if (ps->capacity == ps->top)//�ж��Ƿ�����
	{
		STDdtaTtype* tmp = realloc(ps->data, sizeof(ps) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1);

		}
		ps->data = tmp;
		ps->capacity = newcapacity;
	}
	ps->data[ps->top] = x;
	ps->top++;
}
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	--ps->top;
}
STDdtaTtype StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->top - 1];
}
bool StackEmpty(ST* ps)//�ж��Ƿ�Ϊ��ջ
{
	assert(ps);
	return ps->top == 0;
}
int StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}