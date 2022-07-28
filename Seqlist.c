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
void SLPpopfront(SL* psl)//头删
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
}//这里不能进行所任，缩容是需要代价的，缩容分俩种，一种原地缩，第二种异地找个新空间大小为缩后的大小，若后期要插入元素，则又要开辟空间，比较麻烦
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
	* 这种写法 pos会隐式提升为size_t（unsigned int）类型
	* end 和 pos都为0之后，再--end，此时end变为一个非常大的数字
	* 注意这里的隐式提升
	* end和pos，俩个不能有一个是size_t类型，不然程序会出现错误
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