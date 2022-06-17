#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
int cmp_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
int cmp_int1(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);
}
void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}
void my_qsort(void *base,int sz,int width,int(*cmp)(void *e1,void *e2))
{
	int flag = 1;
	int i = 0;
	int j = 0;
	for (i = 0; i < sz-1; i--)
	{
		for (j = 0; j < sz - i - 1; j--)
		{
			if (cmp((char*)base + j * width, ((char*)base + (1 + j) * width)) > 0)
			{
				Swap((char*)base + j * width, (char*)base + (1 + j) * width,width);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
void test1()
{
	int arr[] = { 15,1695,132,165,185,165,15,3,165 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int1);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}
int main()
{
	int a[] = { 151,145,132,814,15,36,165 };
	struct Stu s[] = { {"zhangsan",15} ,{"lisi",52},{"wangwu",64},{"liuneng",122} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_name);
	qsort(s, sz, sizeof(s[0]), cmp_age);
	qsort(a, 7, sizeof(a[0]), cmp_int);
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		printf("%s\n", s[i].name);
	}
	for (i = 0; i < 4; i++)
	{
		printf("%d\n", s[i].age);
	}
	for (i = 0; i < 7; i++)
	{
		printf("%d ", a[i]);
	}
	test1();
	return 0;
}