#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[] = { 1,1,2,2,3,3,4,4,5,5,6,6,7,7 };
	int i = 0;
	int j = 0;
	for (i = 0; i < 14; i++)
	{
		if (a[i] != a[i + 1])
			a[j++] = a[i];
	}
	for (i = 0; i < j; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}