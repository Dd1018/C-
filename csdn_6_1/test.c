#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int Add(int x, int y)
{
	return x + y;
}

void calc(int(*pf)(int, int))
{
	int a = 3;
	int b = 5;
	int ret = pf(a, b);
	printf("%d\n", ret);
}

int main()
{
	calc(Add);

	return 0;
}