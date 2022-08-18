#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;
	int mid = (begin + end) / 2;
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid+1, end, tmp);
	int begin1 = begin; int end1 = mid;
	int i = begin1;
	int begin2 = mid + 1; int end2 = end;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[i++] = a[begin1++];
		else
			tmp[i++] = a[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = a[begin1++];
	while (begin2<= end2)
		tmp[i++] = a[begin2++];
	memcpy(a + begin, tmp + begin, ((end - begin) + 1) * sizeof(int));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		return;
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}
void _MergeSort1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
		return;
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i = i + 2 * gap)
		{
			int begin1 = i; int end1 = i + gap - 1;
			int begin2 = i + gap; int end2 = i + 2 * gap - 1;
			int j = begin1;
			if (end1 >= n)
			{
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			else if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
					tmp[j++] = a[begin1++];
				else
					tmp[j++] = a[begin2++];
			}
			while (begin1 <= end1)
				tmp[j++] = a[begin1++];
			while (begin2 <= end2)
				tmp[j++] = a[begin2++];
		
	
		}
		memcpy(a, tmp, n * sizeof(int));
		gap = gap * 2;
	}
	PrintArray(a, 10);
}
void MergeSortNonR(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	int gap = 1;
	while (gap < n)
	{
		//printf("gap=%d->", gap);
		for (int i = 0; i < n; i += 2 * gap)
		{
			// [i,i+gap-1][i+gap, i+2*gap-1]
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			// end1越界或者begin2越界，则可以不归并了
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			else if (end2 >= n)
			{
				end2 = n - 1;
			}
			//printf("[%d,%d] [%d, %d]--", begin1, end1, begin2, end2);

			int m = end2 - begin1 + 1;
			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}

			memcpy(a + i, tmp + i, sizeof(int) * m);
		}

		gap *= 2;
	}

	free(tmp);
}
void MergeSort1(int* a, int n)
{

	_MergeSort1(a, n);
}
void CountSort(int *a,int n)
{
	int min = a[0], max = a[0];//先找到最大值和最小值
	for (int i = 0; i < n; i++)
	{
		if (a[i] < min)
		{
			min = a[i];
		}
		if (a[i] >max)
		{
			max = a[i];
		}
	}
	int range = max - min + 1;//算出范围
	int* count =(int*) malloc(sizeof(int) * range);
	if (count == NULL)
		return;
	memset(count, 0, sizeof(int) * range);
	for (int i = 0; i < n; ++i)
	{
		count[a[i] - min]++;//统计次数
	}
	//排序
	int j = 0;
	for (int i = 0; i < range; ++i)
	{
		//出现几次，回写几个i+min
		while (count[i]--)
		{
			a[j++] = i + min;
	}
	}
}
int main()
{
	int a[10] = {10,6,7,1,3,9,4,2,10,11 };
	CountSort(a,10);
	return 0;
}