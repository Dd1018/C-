#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a)
{
    if (a <= 2)
        return a;
    else
        return fun(a - 1) + fun(a - 2);
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", fun(a));
    return 0;
}