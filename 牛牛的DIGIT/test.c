#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int a, int b)
{
    int sum = 0;
    int i = 10;
    while (b)
    {
        sum = a % i;
        i = i * 10;
        b--;
    }
    return sum;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", fun(a, b));
    return 0;
}