#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    printf("%.2lf", (double)3.14 * a * a);
    return 0;
}