#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	int i, j;
	int c[100] = { 0 };
	int d[100] = { 0 };
	for (i = 0; i < a; i++)
	{
		scanf("%d", &c[i]);
	}
	for (j = 0; j < b; j++)
	{
		scanf("%d", &d[j]);
	}
	i = 0;
	j = 0;
	while (i < a && j < b)
	{
		if (c[i] < d[j])
		{
			printf("%d ", c[i]);
			i++;
		}
		else
		{
			printf("%d ", d[j]);
			j++;
		}
		if (i == a)
		{
			for (; j < b; j++)
				printf("%d ", d[j]);
		}
		else if(j==b)
		{
			for (; i< a; i++)
				printf("%d ", c[i]);
		}
	}
	return 0;
}
