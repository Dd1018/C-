#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a = 0;
	int n = 0;
	scanf("%d %d", &a, &n);//2 5
	int i = 0;
	int sum = 0;
	int k = 0;

	for (i = 0; i < n; i++)
	{
		k = k * 10 + a;
		sum += k;
	}

	printf("%d\n", sum);

	return 0;
}