#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
long long int fun(int x, int y)
{
    int i = 0;
    long long int  sum = 1;
    long long int t = 1;
    if (x >= 0 && y >= 0)
    {
        for (i = 1; i <= x; i++)
            sum = i * sum;
        for (i = 1; i <= y; i++)
            t = t * i;
        return sum / t;
    }
    else
        return 0;
}
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", fun(a, a - b));
    return 0;
}