#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
float fun(int x, int y[100])
{
	float sum = 0.0f;
	int i;
	for (i = 0; i < x; i++)
	{
		if (y[i] > 60)
			sum = sum + 0.2;
		else
			sum = sum + 0.1;
	}
	return sum;
}
int main()
{
	int a;
	int b[100];
	scanf("%d", &a);
	int i = 0;
	for (i = 0; i < a; i++)
	{
		scanf("%d", &b[i]);
	}
	printf("%.1lf", fun(a, b));
	return 0;
}