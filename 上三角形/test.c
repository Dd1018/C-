#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int x = 5;
	int i = 0;
	int j = 0;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < x - i; j++)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}