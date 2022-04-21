#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int x, int y)
{
	int i;
	int z = 0;
	int g = 0;
	int t = 0;
	int sum = 0;
	int count = 0;
	for (i = x; i <= y; i++)
	{
		count = 0;
		z = i;                
		for (t=1; z != 0;t*=10)
		{
			g = (i /t)% 10;
			count = count + g;
			z = z / 10;
			if ((count) % 5 == 0&&z==0)
			{
				sum++;
			}
		}
	}
	return sum;
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d",fun(a, b));
	return 0;
}