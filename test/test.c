#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void Swap(char* e1, char* e2, int width)
{
	char tmp;
	int i = 0;
	for (i = 0; i < width; i++)
	{
		tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;
	}
}
void my_qsort(void *a,int sz,int width,int(*cmp)(void *e1,void*e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i++)
	{
		int flag = 1;
		for (j = 0; j < sz - i - 1; j++)
		{
			if ((cmp((char*)a + j * width, (char*)a + (j + 1) * width))>0)
			{
				Swap((char*)a + j * width, (char*)a + (j + 1) * width, width);
				flag = 1;
			}
			if (flag == 0)
				break;
		}
	}
}
int my_int(void *e1,void *e2)
{
	return (*((int*)e1) - (*((int*)e2)));
}
void test()
{
	int a[10] = { 15,165,123,156,184,165,18,321,158,621 };
	int sz = sizeof(a) / sizeof(a[0]);
	my_qsort(a, sz, sizeof(a[0]), my_int);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}
}
int main()
{
	test();
	return 0;
}