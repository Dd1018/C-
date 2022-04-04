#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c, d, e;
    scanf("%d %d", &a, &b);
    if (a >= 00 || b >= 00)
    {
        c = a % 100;
        d = b % 100;
    }
    if (c + d >= 100)
        e = (c + d) % 100;
    else
        e = c + d;
    printf("%d", e);
    return 0;
}