#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int i, j, a, k;
    while (scanf("%d", &a) != EOF)
    {
        getchar();
        for (i = 0; i <= a; i++)
        {
            for (j = 0; j <= a - i - 1; j++)
            {
                printf(" ");
            }
            for (j = 0; j <= i; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
        for (k = 0; k < a; k++)
        {
            for (j = 0; j <= k; j++)
            {
                printf(" ");
            }
            for (j = 0; j <= a - k - 1; j++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}