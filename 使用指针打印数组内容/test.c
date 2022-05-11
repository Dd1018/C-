#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void print(int *a,int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(a + i));
	}
}
int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(a) / sizeof(a[0]);
	print(a,sz);
	return 0;
}