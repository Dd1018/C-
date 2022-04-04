#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a, b,c;
	scanf("%d %d", &a, &b);
	if (a <= b)
	{
		c = a;
		a = b;
		b = c;
	}
	c = b;
	while (c != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	printf("%d\n", a);
	return a;
}