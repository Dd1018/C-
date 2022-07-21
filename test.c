#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main()
//{
//    int left = 0;
//    int right = 0;
//    scanf("%d %d", &left, &right);
//    int  returnSize[100];
//    int i = 0;
//    int k = 0;
//    int j = 0;
//    int z = 0;
//    for (i = left; i <= right; i++)
//    {
//        j = i;
//        while (j != 0)
//        {
//            k = j % 10;
//            if (k == 0)
//                break;
//            if (i % k != 0)
//                break;
//            j = j / 10;
//        }
//        if (j == 0)
//            returnSize[z++] = i;
//    }
//    for (i = 0; i < z; i++)
//    {
//        printf("%d ", returnSize[i]);
//    }
//    return 0;
//}
//int main()
//{
//    int arr[100];
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int j = 0;
//    int ans[100];
//    int sum = 1;
//    int z = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i <n; i++)
//    {
//        sum = 1;
//        j = 0;
//        while (j < n)
//        {
//            if (j == i)
//                j++;
//            else if (j != i)
//            {
//                sum = sum * arr[j];
//                j++;
//            }
//        }
//        ans[z++] = sum;
//    }
//    for (i = 0; i <z; i++)
//    {
//        printf("%d ", ans[i]);
//    }
//    return 0;
//}

#include<stdio.h>
int main()
{
    int n = 0;
    scanf("%d", &n);
    int a = 0;
    int b = 1;
    int c = a + b;
    int sum1 = 0;
    int sum2 = 0;
    while (1)
    {
        if (a == n || b == n)
        {
            printf("%d", 0);
            break;
        }
        else if (n > a && n < b)
        {
            sum1 = n - a;
            sum2 = b - n;
            if (sum1 > sum2)
                printf("%d", sum2);
            else
                printf("%d", sum1);
            break;
        }
        a = b;
        b = c;
        c = a + b;
    }
    return 0;
}