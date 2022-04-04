#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c, i, n;
    int d = 0;
    scanf("%d", &n);
    a = b = n;
    for (i = 1; b != 0; i=i * 10)
    {
        c = a % 10;
        b = b / 10;
        a = b;
        if (c % 2 == 0)
        {
            c = 0;
        }
        else
            c = 1;
        d= c*i+d;
    }
    printf("%d", d);
    return 0;
}