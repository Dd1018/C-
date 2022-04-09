#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int i;
    int sum = 0;
    int k = a;
    for (i = 1; i <= a; i++)
    {
        k = i;
        while (k != 0)
        {
            if (k % 10 == b)
                sum++;
            k = k / 10;
        }
    }
    printf("%d", sum);
    return 0;
}