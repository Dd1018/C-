#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    char a = 0;
    int num = 0;
    while ((a = getchar()) != '\n')
    {
        if (a >= 'a' && a <= 'z')
            num++;
        if (a >= 'A' && a <= 'Z')
            num++;
        if (a >= '0' && a <= '9')
            num++;
    }
    printf("%d", num);
    return 0;
}