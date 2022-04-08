#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void fun(long a)
{
    int i;
    if (a == 0);
    else
    {
        i = a % 6;
        fun(a / 6);
        printf("%d", i);
    }
}
int main()
{
    long a;
    scanf("%d", &a);
    fun(a);
}