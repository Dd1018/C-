#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	//ึธี๋สýื้
	/*int a[] = { 1,2,3,4,5 };
	int b[] = { 6,7,8,9,10 };
	int c[] = { 11,12,13,14,15 };
	int* p[] = { a,b,c };
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d ", *(p[i]+ j));
		}
	}*/
	int a[4] = { 1,2,3,4};
	int b[4] = { 5,6,7,8 };
	int c[4] = { 9,10,11,12};
	int(*p[3])[4] = { &a ,&b,&c};
	int i = 0, j = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%d ", *(*(*p+i)+j));
		}
		printf("\n");
	}
	return 0;
}