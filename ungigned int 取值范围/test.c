#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	unsigned int a, b;
	a = 2147483647;
	b = a + 1;
	printf("%d %d", a, b);
	return 0;
}