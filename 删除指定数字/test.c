#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	scanf("%d", &a);
	int b[50];
	int d[50];
	int i = 0;
	for (i = 0; i < a; i++)
		scanf("%d", &b[i]);
	int c;
	int j = 0;
	scanf("%d", &c);
	for (i = 0; i < a; i++)
	{
		if (c != b[i])
		d[j++] = b[i];
	}
	for (i = 0; i < j; i++)
		printf("%d ", d[i]);
	return 0;
}