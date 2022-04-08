#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, i, j;
    while (scanf("%d", &a) != EOF)
    {
        for (i = 0; i < a; i++)
        {
            for (j = 0; j < i; j++)
            {
                printf(" ");
            }
            for (j = a - i; j != 0; j--)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}