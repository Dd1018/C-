#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[99][99];
	int h;
	scanf("%d", &h);
	int i, j, k;
	for (i = 0; i < h; i++)
	{
		for (j = 0; j < h - i; j++)
		{
			printf(" ");
		}
		a[i][0] = 1;
		for (j = 1; j <= i; j++)
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
		a[i][i] = 1;
		for (j = 0; j <= i; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}