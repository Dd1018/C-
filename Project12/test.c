#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(int a)
{
	int i = 0;
	printf("ÆæÊý:");
	for (i = 31; i>=1 ; i=i-2)
	{
			printf("%d ", (a >> i) & 1);
	}
	printf("\nÅ¼Êý:");
	for (i = 30; i >= 0; i = i - 2)
	{
		printf("%d ", (a >> i) & 1);
	}
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	fun(a);
	return 0;
}