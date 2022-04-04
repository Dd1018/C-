#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    long long int a, b, c, d;
    scanf("%ld %ld", &a, &b);
    d = a * b;
    if (a < b)
    {
        c = a;
        a = b;
        b = c;
    }
    while (c != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%ld", a + d / a);
    return 0;
}