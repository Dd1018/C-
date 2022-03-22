#define _CRT_SECURE_NO_WARNINGS 1
#define N 99
#include<stdio.h>
int main()
{
	int i, j, k, h;
	int a[N][N] = { 0 };
	printf("请显示第X行杨辉三角:");
	scanf("%d", &h);
	for (i = 0; i < h; i++)
	{
		for (j = 0; j <h-i; j++)
			printf("   ");
		for (j = 0; j <= i; j++)
			a[j][0] = 1;
		a[j][j] = 1;
		for (j = 2; j <= i; j++)
		{
			for (k = 1; k < i; k++)
				a[j][k] = a[j - 1][k - 1] + a[j - 1][k];
		}
		for (j = 0; j < i; j++)
		{
				printf("%6d", a[i][j]);
		}
		printf("\n");

	}
	return 0;
}