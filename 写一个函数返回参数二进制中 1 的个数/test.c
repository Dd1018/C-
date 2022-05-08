#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a)
{
	int sum = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((a >> i) & 1)
			sum++;
	}
	return sum;
}
int main()
{
	int a;
	scanf("%d", &a);
	printf("%d",fun(a));
	return 0;
}