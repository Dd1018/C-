#define _CRT_SECURE_NO_WARNINGS
#include"Heap.h"
void HeapInit(HP* php)
{
	assert(php);
	php->a = NULL;
	php->capacity = php->size = 0;
}
void Swap(HPDataTypedef* a, HPDataTypedef* b)
{
	HPDataTypedef tmp = *a;
	*a = *b;
	*b = tmp;
}
void AdjusuUp(HPDataTypedef* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child]< a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(HP* php, HPDataTypedef x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		int newcapacity = php->capacity == 0 ? 4 : 2 * php->capacity;
		HPDataTypedef* tmp = (HPDataTypedef*)realloc(php->a,sizeof(HPDataTypedef) * newcapacity);
		if (tmp == NULL)
		{
			perror("malloc fail:");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}
	php->a[php->size] = x;
	php->size++;
	AdjusuUp(php->a, php->size - 1);
}

void HeapPrint(HP* php)
{
	assert(php);
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
}
void AdjusuDown(HPDataTypedef* a,int n, HPDataTypedef parent)
{
	HPDataTypedef minChild = parent * 2 + 1;
	while (minChild+1<n)
	{
		if (minChild+1<n&&a[minChild] > a[minChild + 1])
		{
			minChild = a[minChild + 1];
		}
		if (a[parent] > a[minChild])
		{
			Swap(&a[parent], &a[minChild + 1]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
			break;
	}
}
void HeapPop(HP* php)
{
	Swap(&php->a[0], &php->a[php->size-1]);
	php->size--;
	AdjusuDown(php->a,php->size, 0);
}
HPDataTypedef Pop(HP* php)
{
	assert(php);
	assert(!HeapEmpt(php));
	return php->a[0];
}
void Destory(HP* php)
{
	free(php->a);
	php->capacity = php->size = 0;
	php->a = NULL;
}
bool HeapEmpt(HP* php)
{
	assert(php);
	
	return php->size == 0;
}