#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void swap(int b[],int a)
{
	int i = 0;
	int o = 0;
	int j = 0;
	int k = 0;
	for (k = 0; k < a; k++)
		{
			for (i = 0; i < 32; i++)
			{
			if ((b[k] >> i) & 1)
			{
				o++;
			}
			else
				j++;
		}
			if (o % 2 == 0 && o != 0&&j%2!=0)
				printf("1 ");
			else if (j % 2 == 0 && j != 0&&o%2!=0)
				printf("0 ", j);
			else if (o%2==0&&j%2==0&&j!=0&&o!=0)
				printf("10 ");
			else
				printf("100 ");
			o = 0;
			j = 0;
	}
}
int main()
{
	int a;
	scanf("%d", &a);
	int b[100] = {0};
	int i = 0;
	for (i = 0; i < a; i++)
		scanf("%d", &b[i]);
	swap(b,a);
	return 0;
}