#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int c = a / 3600;
    int d = (a - c * 3600) / 60;
    int e = a - c * 3600 - d * 60;
    printf("%d %d %d", c, d, e);
    return 0;
}