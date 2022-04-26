#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a, int b)
{
    if (b == 0)
        return a + 1;
    else if (b > 0 && a == 0)
        return fun(b, 1);
    else if (b > 0 && a > 0)
        return fun(b - 1, fun(b, a - 1));
}
int main()
{
    int a; int b;
    scanf("%d %d", &a, &b);
    printf("%d", fun(a, b));
    return 0;
}