#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i = 0, j = 0, n, k = 0;
    while (scanf("%d", &n) != EOF)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n - i - 1; j++)
            {
                printf("  ");
            }
            for (k = 0; k <= i; k++)
            {
                printf("* ");
            }
            printf("\n");
        }
    }
    return 0;
}