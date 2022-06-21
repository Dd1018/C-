#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int i = 0;
	int j = 0;
	for (i = 0; i < a; i++)
	{
		for (j = 0; j < a - i; j++)
		{
			printf(" ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	for (i = 0; i < a - 1; i++)
	{
		for (j = 0; j <= i+1; j++)
		{
			printf(" ");
		}
		for (j = 0; j < a - i-1; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}