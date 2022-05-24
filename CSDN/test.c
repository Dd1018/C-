#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[99][99] = { 0 };
	int b;
	scanf("%d", &b);
	int i = 0;
	int j = 0;
	int k = 1;
	for (i = 0; i < b; i++)
	{
		for (j = 0; j < b - i; j++)
		{
			printf("  ");
		}
		for (j = 0; j <= i; j++)
		{
			a[j][0] = 1;
			if (i == j)
				a[i][j] = 1;
		}
		for (j = 2; j <=i; j++)
		{
			for (k = 1; k < i; k++)
			{
				a[j][k] = a[j - 1][k - 1] + a[j - 1][k];
			}
		}
		for (j = 0; j <= i; j++)
		{
			printf("%6d", a[i][j]);  // 打印，j为二维数组的列数
		}
		printf("\n");
	}
	return 0;
}