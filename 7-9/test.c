#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//void* my_memmove(void* des, const void* src, size_t num)
//{
//	assert(des && src);
//	char* ret = des;
//	if (des < src)
//	{
//		while (num--)
//		{
//			*(char*)des = *(char*)src;
//			des = (char*)des + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (num--)
//		{
//			*((char*)des + num) = *((char*)src + num);
//		}
//	}
//	return ret;
//}
//int main()
//{
//	int arr1[] = { 1,23,54,165,56,1,51,65 };
//	int arr2[] = { 165,195 };
//	my_memmove(arr1+2, arr1, 12);
//	for (int i = 0; i < 8; i++)
//		printf("%d ", arr1[i]);
//	return 0;
//}
//int main()
//{
//	int a[10] = {0};
//	memset(a, 1, 40);
//	for (int i = 0; i < 10; i++)
//		printf("%d ", a[i]);
//	return 0;
//}
//int main()
//{
//	int i = 0, j = 0,n=0;
//	while (scanf("%d", &n) != EOF)
//	{
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j < n - i; j++)
//			{
//				printf("  ");
//			}
//			for (j = 0; j <= i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//		for (i = 0; i <= n; i++)
//		{
//			for (j = 0; j <= i; j++)
//			{
//				printf("  ");
//			}
//			for (j = 0; j < n - i; j++)
//			{
//				printf("* ");
//			}
//			printf("\n");
//		}
//	}
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//    int a[7] = { 0 };
//    int i;
//    double sum = 0.0;
//    while (scanf("%d%d%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6]) != EOF)
//    {
//        sum = 0.0;
//        getchar();
//        int max = a[0];
//        int min = a[0];
//        for (i = 0; i < 7; i++)
//        {
//            if (a[i] > max)
//                max = a[i];
//            else if (a[i] < min)
//                min = a[i];
//        }
//        for (i = 0; i < 7; i++)
//        {
//            sum = sum + a[i];
//        }
//        sum = sum - max - min;
//        printf("%.2lf\n", sum / 5);
//    }
//    return 0;
//int main()
//{
//	int year, month, day;
//	scanf("%d %d %d", &year, &month, &day);
//	int sum = 0;
//	int i = 0;
//	for (i = 1; i < month; i++)
//	{
//		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
//		{
//			sum = sum + 31;
//		}
//		else if (i == 2)
//		{
//			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//				sum = sum + 29;
//			else
//				sum = sum + 28;
//		}
//		else
//		{
//			sum = sum + 30;
//		}
//	}
//	printf("%d", sum + day);
//	return 0;
//}
#define INT_PTR int*
int main()
{
typedef int* int_ptr;
INT_PTR a, b;
int_ptr c, d;
return 0;
}

