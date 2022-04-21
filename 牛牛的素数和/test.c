#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int fun(int x, int y)
{
	int i = 0;
	int count = 0;
	int j = 0;
	for (i = x; i <= y; i++)
	{
		if (i == 1)
			count=count+1;
		for (j = 2; j <i; j++)
		{
			if (i % j==0 )
				break;
		}
		if (j == i)
			count = count + i;
	}
	return count;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", fun(a, b));
	return 0;
}