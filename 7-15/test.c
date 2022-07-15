#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//int main()
//{
//	int a[12] = { 1,2,3,4,5,1,2,3,4,5,6,7 };
//	int i = 0;
//	int j = 0;
//	int sum = 0;
//	for (i = 0; i < 12; i++)
//	{
//		sum = 0;
//		for (j =0; j < 12; j++)
//		{
//			if (a[i] == a[j]&&i!=j)
//			{
//				sum++;
//			}
//			if (sum ==1)
//				break;
//		}
//		if (sum ==0)
//		{
//			printf("%d ", a[i]);
//		}
//	}
//	return 0;
//}
#include<assert.h>
int *my_atoi(char* arr)
{
	assert(arr);
	int flag = 1;
	if (*arr == '-')
	{
		flag == -1;
		arr++;
	}
	if (*arr == ' ')
	{
		arr++;
	}
	int sum = 0;
	while (*arr >= '0' && *arr <= '9')
	{
		sum = sum * 10 + *arr - '0';
		arr++;
	}
	return flag*sum;
}

	int main()
	{
		char ch;
		while ((ch = getchar()) != '\n')
		{
			if (ch % 2 != 0 && (ch >= 'a' && ch <= 'z'))
				ch = ch - 'a' + 'A';
			putchar(ch);
		}
		printf("\n");
		return 0;
	}