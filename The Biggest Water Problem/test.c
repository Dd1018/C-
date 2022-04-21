#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int x)
{
	int count = 0;
	int i = 1;
	int t = 0;
	int z = x;
	while (1)
	{
		for (; z != 0;)
		{
			t = z % 10;
			z = z / 10;
			count = count + t;
		}
		if (count < 10)
			break;
		else
		{
			z = count;
			count = 0;
		}
	}

	return count;
}
int main()
{
	int a;
	scanf("%d", &a);
	printf("%d",fun(a));
	return 0;
}