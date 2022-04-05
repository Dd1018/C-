#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    double a[4] = { 0 };
    int i = 0;
    int c, b;
    while (i < 4)
    {
        scanf("%lf", a[i]);
        i++;
    }
    if (a[1] == 11 && a[2] == 11)
    {
        if (a[3] == 1)
        {
            c = a[0] * 0.7 - 50;
            if (c <= 0.0)
                printf("%.2lf", 0.0);
            else
                printf("%.2lf", c);
        }
        else
            printf("%.2lf", a[0] * 0.7);
    }
    else if (a[1] == 12 && a[2] == 12)
    {
        if (a[3] == 1)
        {
            b = a[0] * 0.8 - 50;
            if (b< 0.0)
                printf("%.2lf", 0.0);
            else
                printf("%.2lf", b);
        }
        else
            printf("%.2lf", a[0] * 0.8);
    }
    else
        printf("%.2lf", a[0]);
    return 0;
}