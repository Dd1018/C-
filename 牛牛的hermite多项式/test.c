#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int n, int x)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return 2 * n;
    else
        return (2 * x * fun(n - 1, x) - 2 * (n - 1) * fun(n - 2, x));
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", fun(a, b));
    return 0;
}