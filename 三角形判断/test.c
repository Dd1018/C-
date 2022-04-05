#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c;
    while (scanf("%d", &a) != EOF && scanf("%d", &b) != EOF && scanf("%d", &c) != EOF)
    {
        getchar();
        if (a + b > c && a + c > b && b + c > a)
        {
            if (a == b && b == c)
                printf("Equilateral triangle!\n");
            else if (a == b || b == c || c == a)
                printf("Isosceles triangle!\n");
            else
                printf("Ordinary triangle!\n");
        }
        else
        {
            printf("Not a triangle!\n");
        }
    }
    return 0;
}