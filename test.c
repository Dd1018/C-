#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void InsertSort(int* arr, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i ;

		int key = arr[end+1];
		while (end >= 0)
		{
			if (key < arr[end])
			{
				arr[end+1] = arr[end];
				end--;
			}
			else
				break;
		}
		arr[end+ 1] = key;
	}
}
int main()
{
	int arr[] = { 165, 132, 13, 165, 132, 165, 132, 165, 132, 165, 132, 165 };
	int n = sizeof(arr) / sizeof(arr[0]);
	InsertSort(arr, n);
	return 0;
}