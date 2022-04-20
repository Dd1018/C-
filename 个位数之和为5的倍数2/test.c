#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int x, int y)
{
	int count = 0;
	int i, j;
	for (i = x; i < y; i++)
	{
		for (j = i + 1; j <= y; j++)
		{
			if (((i % 10) + (j % 10)) % 5 == 0)
			{
				count++;
			}
		}
	}
	return count;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int z=fun(a, b);
	printf("%d", z);
	return 0;
}