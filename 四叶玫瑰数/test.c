#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    int s = a;
    int i = 0;
    int t;
    int k = 0;
    int l = 0;
    int sum = 0;
    int c[100];
    if (a < 1000)
        a = 1000;
    int j = a;
    for (i = a; j <= b; j++)
    {
        i = j;
        while (i != 0)
        {
            t = i % 10;
            k = t * t * t * t + k;
            i = i / 10;
        }
        if (k == j)
        {
            c[l++] = j;
            sum = sum++;
            break;
        }
        k = 0;
    }
    if (a != b)
        printf("%d ", sum);
    for (i = 0; i < l; i++)
        printf("%d", c[i]);
    return 0;
}