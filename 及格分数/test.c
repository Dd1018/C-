#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    while (a != EOF)
    {
        if (a >= 60)
            printf("Pass");
        else
            printf("Fail");
    }
    return 0;
}