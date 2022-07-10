#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//void left_move(char arr[], int n)
//{
//	int str=strlen(arr);
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		char tmp = arr[0];
//		for (j = 0; j < str - 1; j++)
//		{
//			arr[j] = arr[j + 1];
//		}
//		arr[j] = tmp;
//	}
//}
//int main()
//{
//	char arr1[] = "ABCDEFG";
//	int n = 0;
//	scanf("%d", &n);
//	left_move(arr1, n);
//	printf("%s", arr1);
//	return 0;
//}
//void resever(char *left,char *right)
//{
//	while (left<right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//int main()
//{
//	char arr1[] = "ABCDEFG";
//	int n = 0;
//	scanf("%d", &n);
//	int str = strlen(arr1);
//	resever(arr1,arr1+n);
//	resever(arr1+n, arr1+str-1);
//	resever(arr1, arr1 + str - 1);
//	printf("%s", arr1);
//	return 0;
//}

// void find_num(int a[][3], int *row, int *col,int n)
//{
//	int x = 0;
//	int y = *col - 1;
//
//	while (x<=*row-1&&y>=0)
//	{
//		if (n < a[x][y])
//		{
//			y--;
//		}
//		else if (n > a[x][y])
//		{
//			x++;
//		}
//		else if (n == a[x][y])
//		{
//			*row = x;
//			*col = y;
//			break;
//		}
//	}
//}
//int main()
//{
//	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int b = 3;
//	int c = 3;
//	int n = 0;
//	scanf("%d", &n);
//	find_num(a,&b,&c,n);
//	printf("%d %d", b,c);
//	return 0;
//}
//int is_left_move(char* arr1, char* arr2)
//{
//	int str = strlen(arr1);
//	int i = 0, j = 0;
//	for (i = 0; i < str; i++)
//	{
//		char tmp = arr1[0];
//		for (j = 0; j < str - 1; j++)
//		{
//			arr1[j] = arr1[j + 1];
//		}
//		arr1[j] = tmp;
//		if (strcmp(arr1, arr2) == 0)
//			return 1;
//	}
//	return 0;
//}
//int is_left_move(char* arr1, char* arr2)
//{
//	int str1 = strlen(arr1);
//	int str2 = strlen(arr2);
//	if (str1!=str2)
//		return 0;
//	strncat(arr1, arr2, str1);
//	char* ret = strstr(arr1, arr2);
//	if (ret == NULL)
//		return 0;
//	else
//		return 1;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[] = "bcdefa";
//	int z=is_left_move(arr1, arr2);
//	if (z == 1)
//		printf("是");
//	else
//		printf("否");
//	return 0;
//}
//int main()
//{
//    int n = 0;
//    int arr[50] = { 0 };
//    scanf("%d", &n);
//    int i = 0;
//    int flag1 = 0;
//    int flag2 = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//        if (i > 0)
//        {
//            if (arr[i] > arr[i - 1])
//                flag1 = 1;
//            else if (arr[i] < arr[i - 1])
//                flag2 = 1;
//        }
//    }
//    //flag1 和 flag2 都为1是乱序的
//    if (flag1 + flag2 > 1)
//        printf("unsorted\n");
//    else
//        printf("sorted\n");
//    return 0;
//}
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));
//	return 0;
//}
//#define N 2
//#define M N + 1
//#define NUM (M + 1) * M / 2
//int main()
//{
//	printf("%d\n", NUM);
//	return 0;
//}
//int f(int n)
//{
//	static int i = 1;
//	if (n >= 5)
//		return n;
//	n = n + i;
//	i++;
//	return f(n);
//}
//int main()
//{
//	int a = f(1);
//	return 0;
//}
//#include<math.h>
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int b=pow(a, 3);
//	int i = 0;
//	int j = 0;
//	int t=0;
//	int sum = 0;
//	for (i = 1; i <= 1000000;i=i + 2)
//	{
//		t = i;
//		for (j = 0; j < a; j++,t=t+2)
//		{
//				sum = sum + t;
//				if (sum == b)
//				{
//					for (j=0; j<a;j++)
//					{
//						if (j == a - 1)
//							printf("%d", i);
//						else
//						printf("%d+", i);
//						i = i + 2;
//					}
//					return 0;
//				}
//		}
//		sum = 0;
//	}
//	return 0;
//}

int main()
{
    int a = 0;
    scanf("%d", &a);
    int i = 0;
    int j = 2;
    int sum = 0;
    for (i = 0; i < a;i++,j=j+3)
    {
        sum = sum + j;
    }
    printf("%d", sum);
    return 0;
}