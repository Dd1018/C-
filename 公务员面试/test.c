#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a[7] = { 0 };
    int i,k;
    double j = 0.0;
    for (i = 0; i < 7; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 7; i++)
    {
        if (a[0] <= a[i])
        {
            k = a[0];
            a[0] = a[i];
            a[i] = k;
        }
    }
    for (i = 0; i < 7; i++)
    {
        if (a[6] >= a[i])
        {
            k = a[6];
            a[6] = a[i];
            a[i] = k;
        }
    }
    for (i = 1; i < 6; i++)
    {
        j = j + a[i];
    }
    printf("%.2lf", j / 5);
    return 0;
}