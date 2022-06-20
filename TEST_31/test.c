#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
struct Peo
{
	char name[20];
	char tel[11];
	int high;
};
struct P
{
	struct Peo a;
	int num;
	float h;
};
void print(struct Peo a)
{
	printf("%s %s %d\n", a.name, a.tel, a.high);
}
void print1(struct Peo* a)
{
	printf("%s %s %d\n",a->name,a->tel,a->high );
}
int main()
{
	struct Peo a = { "asddsa","12345678",187 };
	struct P b = { {"kkk","789456",186},54,2.0};
	printf("%s %s %d\n",a.name,a.tel,a.high);
	printf("%s %s %d %d %lf\n", b.a.name, b.a.tel, b.a.high, b.num, b.h);
	print(a);
	print1(&a);
	return 0;
}