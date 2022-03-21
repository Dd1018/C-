#define _CRT_SECURE_NO_WARNINGS 1
#define N 5
#include<stdio.h>
int main()
{
	int i, j, k, h;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N-i; j++)
		printf(" ");
		for (j = 0; j <= i; j++)
			printf("%c", (char)('A' + j));
		for (k = i; k; k--)
			printf("%c", (char)('A' + k-1));
		printf("\n");
	}
		return 0;
	
}