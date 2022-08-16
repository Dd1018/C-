#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"Stack.h"
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
int GetMindIndex(int* arr, int left, int right)
{
	int mid = (right + left) / 2;
	if (arr[left] < arr[mid])
	{
		if (arr[mid] < arr[right])
			return mid;
		else if (arr[right]<arr[left])
			return left;
		else
			return right;
	}
	else
	{
		if (arr[mid] > arr[right])
			return mid;
		else if (arr[right] > arr[left])
			return left;
		else
			return right;
	}
}
int PartSort(int* arr, int left, int right)
{
	int mid = GetMindIndex(arr, left, right);
	Swap(&arr[mid], &arr[left]);
	int keyi = left;
	while (left < right)
	{
		while (left < right && arr[right] >= arr[keyi])//left<right是为了防止这俩个错过
		{
			right--;
		}
		while (left < right && arr[left] <= arr[keyi])
		{
			left++;
		}
		
		if (left<right)
			Swap(&arr[left], &arr[right]);
	}
	int meeti = left;
	Swap(&arr[meeti], &arr[keyi]);
	return meeti;
}
void InsertSort(int* a, int n)
{

		for (int i = 0; i < n -1; i++)
		{
			int end = i;
			int tmp = a[end +1];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end +1] = a[end];
					end --;
				}
				else
				{
					break;
				}
			}
			a[end +1] = tmp;
		}
}

//挖坑法
int PartSort2(int* arr, int left, int right)
{
	int mid = GetMindIndex(arr, left, right);
	Swap(&arr[mid], &arr[left]);
	int hole = left;
	int key = arr[left];
	while (left < right)
	{
		while (left < right && arr[right] >= key)
		{
			right--;
		}
		arr[hole]=arr[right];
		hole = right;
		while (left < right && arr[left]<= key)
		{
			left++;
		}
		arr[hole] = arr[left];
		hole = left;
	}
	arr[hole] = key;
	return hole;
}
int PartSort3(int* arr, int left, int right)
{
	int mid = GetMindIndex(arr, left, right);
	Swap(&arr[mid], &arr[left]);
	int keyi = left;
	int cur = left + 1;
	int prev = left;
	while (cur <= right)
	{
		if (arr[cur] < arr[keyi] && ++prev != cur)//等于可以不用动那个值，让他留在哪里
		{
			Swap(&arr[cur], &arr[prev]);
		}
		++cur;
	}
	Swap(&arr[keyi], &arr[prev]);
	return prev;
}
void QuickSort(int* a, int begin, int end)
{
	if (begin >= end)
	{
		return;
	}
	if (end - begin <= 8)
	{
		InsertSort(a + begin, end - begin + 1);
	}
	else
	{
		int keyi = PartSort3(a, begin, end);
		QuickSort(a, begin, keyi - 1);//
		QuickSort(a, keyi + 1, end);
	}

}

void QuickSortNonR(int* a, int begin, int end)
{
	ST st;
	StackInit(&st);
	StackPush(&st, begin);
	StackPush(&st, end);

	while (!StackEmpty(&st))
	{
		int right = StackTop(&st);
		StackPop(&st);

		int left = StackTop(&st);
		StackPop(&st);

		/*if (left >= right)
		{
			continue;
		}*/

		int keyi = PartSort3(a, left, right);
		// [left, keyi-1] keyi [keyi+1,right]

		if (keyi + 1 < right)
		{
			StackPush(&st, keyi + 1);
			StackPush(&st, right);
		}

		if (left < right - 1)
		{
			StackPush(&st, left);
			StackPush(&st, keyi - 1);
		}
	}

	StackDestory(&st);
}


int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10 };
	int n = sizeof(arr) / sizeof(arr[0]);
	QuickSortNonR(arr, 0, n - 1);
	return 0;
}