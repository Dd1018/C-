#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a)
{
    int sum = 1;
    while (a > 0)
    {
        sum = a * sum;
        a--;
    }
    return sum;
}
int main()
{
    int a;
    scanf("%d", &a);
    printf("%d", fun(a));
    return 0;
}