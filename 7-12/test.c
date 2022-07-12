#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void fun(int* a)
//{
//	int sz1 = sizeof(a);
//	printf("%d\n", sz1);
//}
//void fun1(int a[])
//{
//	int sz2 = sizeof(a);
//	printf("%d\n", sz2);
//}
//int main()
//{
//	int a[10] = { 0 };
//	int sz = sizeof(a);
//	printf("%d\n", sz);
//	fun(a);
//	fun1(a);
//	return 0;
//}
//#define M 100
//enum Day//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//联合类型的声明
//union Un
//{
//	char a1;
//	char a2;
//	char a3;
//	char a4;
//	char a5;
//	int i;
//};
//union Un2
//{
//	short c[7];
//	int i;
//};
//int main()
//{
//	int* p = (int*)malloc(40);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	printf("\n");
//	//p=realloc(p, 80); 这里尽量不要用原来电指针去接收，因为有可能申请空间失败，原空间可能会找不到
//	int* ptr =(int *)realloc(p, 800);
//	if (ptr != NULL)
//	{
//		p = ptr;
//	}
//	for (i = 0; i < 20; i++)
//	{
//		*(p + i) = i;
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//  union
//  {
//    short k;
//    char i[2];
//  }*s, a;
//  s = &a;
//  s->i[0] = 0x39;
//  s->i[1] = 0x38;
//  printf("%x\n",a.k);
//  return 0;
//}
//int main()
//{
//	int a = 3;
//	printf("%d\n", (a += a -= a * a));
//	return 0;
//}
#include<stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    int i = 0;
    int b[2000] = { 0 };
    float sum = 0;
    int k = 0;
    float j = 0;
    float ave = 0.0;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &b[i]);
        if (b[i] < 0)
            k++;
        else if (b[i] > 0)
        {
            sum = sum + b[i];
            j++;
        }
    }
    if(j!=0)
    ave = sum/j;
  printf("%d %.1lf", k, ave);
    return 0;
}