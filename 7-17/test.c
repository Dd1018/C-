#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int fun(int x)
{
    return (x == 1) ? 1 : (x + fun(x - 1));
}
int main()
{
    int k = fun(10);
    return 0;
}