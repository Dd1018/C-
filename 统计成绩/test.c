#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    float a[100] = { 0 };
    float b = 0;
    float c = 0;
    float d = 100;
    int n = 0, i = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
        b = a[i] / n + b;
        if (c <= a[i])
        {
            c = a[i];
        }
        if (d >= a[i])
        {
            d = a[i];
        }
    }
    printf("%.2f %.2f %.2f", c, d, b);
    return 0;
}