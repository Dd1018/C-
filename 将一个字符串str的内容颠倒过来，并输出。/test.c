#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a[1000];
	int i = 0;
	int j = 0;
	char* p = a;
	while (scanf("%c", &a[i]))
	{
		if (a[i] == '\n')
			break;
		else
			i++;
	}
	for (j = i; j >= 0; j--)
	{
		printf("%c", *(p + j));
	}
	return 0;
}