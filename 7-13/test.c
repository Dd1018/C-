#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//char* my_strncpy(char* des, char* src, size_t num)
//{
//	char* p = des;
//	while (num--)
//	{
//		*p= *src;
//		p++;
//		src++;
//	}
//	return des;
//}
//char* my_strncat(char *des,char *src,size_t num)
//{
//	char* p = des;
//	while (*p != '\0')
//	{
//		p++;
//	}
//	while (num--)
//	{
//		*p = *src;
//		src++;
//		p++;
//	}
//	return des;
//}
//int main()
//{
//	char arr1[20] = "123456";
//	char arr2[] = "abcdef";
//	my_strncat(arr1, arr2, 5);
//	printf("%s", arr1);
//	return 0;
//}
#include <stdio.h>
//int main()
//{
//	int a[] = { 4, 0, 2, 3, 1 }, i, j, t;
//	for (i = 1; i < 5; i++)
//	{
//		t = a[i];
//		j = i - 1;
//		while (j >= 0 && t < a[j])
//		{
//			a[j + 1] = a[j];
//			--j;
//		}
//		a[j + 1] = t;
//	}
//		return 0;
//}
#include<stdio.h>
int main()
{
    int a = 0;
    scanf("%d", &a);
    int z = 0;
    char arr[100] = { 0 };
    for (z = 0; z < a; z++)
    {
        int i = 0;
        int j = 0;
        int k = 0;
        int h = 0;
        scanf("%s", arr);
        while ((arr[0] >= 'a' && arr[0] <= 'z') || (arr[0] >= 'A' && arr[0] <= 'Z'))
        {
            for (i = 0; arr[i] != '\0'; i++)
            {
                {
                    if (arr[i] >= 'a' && arr[i] <= 'z')
                    {
                        j++;
                    }
                    if (arr[i] >= 'A' && arr[i] < 'z')
                    {
                        k++;
                    }
                    if (arr[i] >= 0 && arr[i] <= 9)
                    {
                        h++;
                    }
                }
            }
            break;
        }
        if (h + j + k >= 2&&i>=8)
        {
            printf("YES\n");
        }
        else
            printf("NO\n");
    }
    return 0;
}