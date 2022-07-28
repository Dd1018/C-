#define _CRT_SECURE_NO_WARNINGS
#include"Seqlist.h"
void SLInit(SL *psl)
{
	assert(psl);
	psl->a = NULL;
	psl->capacity = psl->size = 0;
}
void Checkcapacity(SL* psl)
{
	if (psl->capacity == psl->size)
	{
		int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDatatype* tmp = (SLDatatype*)realloc(psl->a, sizeof(SLDatatype) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		psl->a = tmp;
		psl->capacity = newcapacity;
	}
}
void SLDestory(SL* psl)
{
	assert(psl);
	if (psl->a != NULL)
	{
		free(psl->a);
		psl->capacity = psl->size = 0;
	}
}
void SLPpushback(SL* psl, SLDatatype x)
{
	assert(psl);
	Checkcapacity(psl);
	psl->a[psl->size] = x;
	psl->size++;
}
void SLPprint(SL* psl)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->a[i]);
	}
}
void SLPpushfront(SL* psl, SLDatatype x)
{
	assert(psl);
	Checkcapacity(psl);
	int end = psl->size - 1;
	while (end >= 0)
	{
		psl->a[end + 1] = psl->a[end];
		end--;
	}
	psl->a[0] = x;
	psl->size++;
}
void SLPpopback(SL* psl)
{
	assert(psl);
	if (psl->size == 0)
		return;
	psl->size--;
}
void SLPpopfront(SL* psl)//ͷɾ
{
	assert(psl);
	if (psl->size == 0)
		return;
	int i = 0;
	for (i = 0; i < psl->size -1; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}
	psl->size--;
}//���ﲻ�ܽ������Σ���������Ҫ���۵ģ����ݷ����֣�һ��ԭ�������ڶ�������Ҹ��¿ռ��СΪ����Ĵ�С��������Ҫ����Ԫ�أ�����Ҫ���ٿռ䣬�Ƚ��鷳
int SLPfine(SL* psl, SLDatatype x)
{
	assert(psl);
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->a[i] == x)
			return i;
	}
	return -1;
}
void SLInsert(SL* psl, int pos, SLDatatype x)
{
	assert(psl);
	assert(pos <= psl->size);
	int i = 0;
	Checkcapacity(psl);
	for (i = psl->size; i >= pos; i--)
	{
		if (i == pos)
			psl->a[i] = x;
		else
			psl->a[i] = psl->a[i - 1];
	}
	psl->size++;
}
	/*size_t end=pls->size-1;
	* while(end>=pos)
	* {
	* psl->a[end+1]=psl->a[end];
	* --end;
	* }
	* psl->a[pos]=x;
	* ++psl->size;
	* ����д�� pos����ʽ����Ϊsize_t��unsigned int������
	* end �� pos��Ϊ0֮����--end����ʱend��Ϊһ���ǳ��������
	* ע���������ʽ����
	* end��pos������������һ����size_t���ͣ���Ȼ�������ִ���
	*/
void SLErase(SL* psl, size_t pos)
{
	assert(psl);
	assert(pos < psl->size);
	int i = 0;
	for (i = pos; i < psl->size - 1; i++)
	{
		psl->a[i] = psl->a[i + 1];
	}
	psl->size--;
}
void SLModify(SL* psl, size_t pos, SLDatatype x)
{
	assert(psl);
	assert(pos < psl->size);
	psl->a[pos] = x;
}