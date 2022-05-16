#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int* a, int sz)
{
	int i = 0;
	int j = 0;
	int c[10] = { 0 };
	int t = 0;
	for (i = 0; i < sz; i++)
	{
		if (a[i] % 2 != 0)
			a[j++] = a[i];
		else
			c[t++] = a[i];
	}
	for (i = 0; i < t; i++)
	{
		a[j++] = c[i];
	}
}
int main()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(a) / sizeof(a[0]);
	fun(a,sz);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}