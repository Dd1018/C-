#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int row = 3 * n;
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++)
		{
			//每层单位图案第一行前面的空格
			for (j = 0; j < row - 1; j++)
			{
				printf(" ");
			}
			//每层单位图案第一行后面的空格
			for (j = 0; j <= i; j++)
			{
				printf("*     ");
			}
			printf("\n");

			//每层单位图案第二行前面的空格
			for (j = 0; j < row - 2; j++)
			{
				printf(" ");
			}
			//每层单位图案第二行后面的空格
			for (j = 0; j <= i; j++)
			{
				printf("* *   ");
			}
			printf("\n");

			//每层单位图案第三行前面的空格
			for (j = 0; j < row - 3; j++)
			{
				printf(" ");
			}
			//每层单位图案第三行后面的空格
			for (j = 0; j <= i; j++)
			{
				printf("* * * ");
			}
			printf("\n");

			//每层打印完，进行到下一层
			row -= 3;
		}

		//树根的打印
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < (6 * n - 1) / 2; j++)
			{
				printf(" ");
			}
			printf("*\n");
		}
	}
	return 0;
}
