#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, j,x;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <=i; j++)
		{
			x = i * j;
			printf("%dx%d=%2d  ",j,i,x );
		}
		printf("\n");
	}
}