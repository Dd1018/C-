#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int x, int y)
{
	int i = 0;
	int j,t,z;
	int count = 0;
	for (i = x; i <= y; i++)
	{
		z = i;
		for (;z!=0;)
		{
			j = z % 10;
			z = z / 10;
			if (j ==2)
				count++;
		}

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