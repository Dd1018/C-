#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int fun(int x)
{
    if (x < 0)
        printf("1");
    else if (x == 0)
        printf("0");
    else if (x > 0)
        printf("-1");
        return 0;
}

int main()
{
    int a;
    scanf("%d", &a);
    fun(a);
    return 0;
}