#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//void quick_qsort(int* arr, int left, int right)
//{
//	if (left >= right)
//		return;
//	int i = left-1;
//	int j = right+1;
//	int x = arr[left];
//	while (i < j)
//	{
//		do
//		{
//			i++;
//		} while (arr[i] < x);
//		do
//		{
//			j--;
//		} while (arr[j] > x);
//		if (i < j)
//		{
//			int tmp = arr[i];
//			arr[i] = arr[j];
//			arr[j] = tmp;
//		}
//	}
//	quick_qsort(arr, left, j);
//	quick_qsort(arr, j + 1, right);
//}
//int main()
//{
//	int arr[50];
//	int n;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	quick_qsort(arr, 0, n - 1);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
////}
//void merge_sort(int* arr, int l, int r)
//{
//	if (l >= r)
//		return;
//	int mid = (l + r) / 2;
//	merge_sort(arr, l, mid );
//	merge_sort(arr, mid+1, r);
//	int tmp[100];
//	int i = l;
//	int j = mid + 1;
//	int k = 0;
//	while (i <= mid&&j<=r)
//	{
//		if (arr[i] < arr[j])
//			tmp[k++] = arr[i++];
//		else
//			tmp[k++] = arr[j++];
//	}
//	while (i <= mid)
//		tmp[k++] = arr[i++];
//	while (j <= r)
//		tmp[k++] = arr[j++];
//
//	for (i = l,j=0; i <=r; i++,j++)
//	{
//		arr[i] = tmp[j];
//	}
//}
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	int arr[100];
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	merge_sort(arr, 0, n-1);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}
int main()
{
    int n;
    int m;
    scanf("%d%d", &n, &m);
    int i = 0;
    int arr[100000];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int k = 0;

    while (m--)
    {
        scanf("%d", &k);
        int l = 0;
        int r = n - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (k >= arr[mid])
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
            if (k != arr[l])
            {
                printf("-1 -1\n");
            }
            else
            {
                printf("%d ", l);
                int l = 0;
                int r = n - 1;
                while (l < r)
                {
                    int mid = (l + r) / 2;
                    if (k <= arr[mid])
                    {
                        r = mid;
                    }
                    else
                        l = mid + 1;
                }
                printf("%d ", l);
            }
    }
    return 0;
}