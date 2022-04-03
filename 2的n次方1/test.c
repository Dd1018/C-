#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int c = 1;
	int i;
	for (i = 0; i < a; i++)
	{
		c = c * 2;
	}
	printf("%d", c);
	return 0;
}