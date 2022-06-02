#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Stu
{
	char name[20];
	int age;
};
int cmp_name(const void* e1,const void * e2)
{
	return ((struct Stu*)e1)->age-((struct Stu*)e2)->age;
}
void test2()//使用qsort来排序结构数据
{
	struct Stu s[] = { {"zhangsan", 15}, {"lisi",25}, {"wangwu", 13} };
		int sz = sizeof(s) / sizeof(s[0]);
		qsort(s, sz, sizeof(s[0]), cmp_name);
		int i = 0;
		for (i = 0; i < 3; i++)
		{
			printf("%s\n", s[i].name);
		}
}
int main()
{
	test2();
	return 0;
}