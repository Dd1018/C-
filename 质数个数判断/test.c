#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    double n;
    int i;
    double j = 0;
    double l = 0;
    scanf("%lf", &n);
    for (i = 1; i <= n; i++)
    {
        j = 2 * i - 1;
        if (i % 2 == 0)
            j = -j;
        else j = j;
        l = 1 / j + l;
    }
    printf("%.3lf", l);
    return 0;
}