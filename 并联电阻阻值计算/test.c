#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%.1lf", 1 / ((1 / a) + (1 / b)));
    return 0;
}