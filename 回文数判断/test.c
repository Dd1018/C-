#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    long int a;
    scanf("%ld", &a);
    long int i = 1;
    long int c;
    for (i = 1; i <= a; i++)
    {
        if ((i % 10 == i / 100000) && (i % 100 == i / 10000) && (i % 1000 == i / 1000))
        {
            c = i;
            printf("%ld\n", c);
        }
    }
    return 0;
}