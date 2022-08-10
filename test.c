#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void BigAdjustDown(int *a,int n,int parent)
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		if (minChild + 1 < n && a[minChild + 1] > a[minChild])
		{
			minChild = minChild + 1;
		}
		if (a[minChild] > a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
			break;
	}
}
void SmallAdjustDown(int* a, int n, int parent)
{
	int minChild = parent * 2 + 1;
	while (minChild < n)
	{
		if (minChild + 1 < n && a[minChild + 1] <a[minChild])
		{
			minChild = minChild + 1;
		}
		if (a[minChild]<a[parent])
		{
			Swap(&a[minChild], &a[parent]);
			parent = minChild;
			minChild = parent * 2 + 1;
		}
		else
			break;
	}
}
int main()
{
	int a[] = { 165,19869,123,46,26,165,213 };
	int sz = sizeof(a) / sizeof(a[0]);
	for (int i = (sz-2)/2; i >= 0; i--)
	{
		BigAdjustDown(a, sz, i);
	}
	int i = 1;
	while (i < sz)
	{
		Swap(&a[0], &a[sz - i]);
		BigAdjustDown(a, sz-i, 0);
		++i;
	}
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	int b[] = { 165,654,18,123,4986,364 };
	int k = 3;
	 i = 0;
	for (i = (k - 2) / 2; i >= 0; i--)
	{
		SmallAdjustDown(b, k, i);
	}
	for (i=3; i < 6; i++)
	{
		if (b[i] > b[0])
		{
	
		b[0] = b[i];
	
			SmallAdjustDown(b, 6, 0);
		}
	}
	for (i = 0; i < 6; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}