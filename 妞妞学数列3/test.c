#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int n;
	scanf("%d", &n);
	double j=0.0;
	double sum = 0.0;
	double x = 1.0;
	int i;
	for (i = 1; i <= n; i++)
	{
		j = x*(2 * i - 1) + j;   // 改变前面的正负号
		sum = 1 / j + sum;
		x = -x;
}
	printf("%.3lf", sum);
	return 0;
}