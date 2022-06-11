#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
    int i, j, n, m;
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &n);
        for (i = n; i >= 1; i--)
        {
            for (j = i; j < n; j++)
                printf(" ");
            for (j = 1; j <= 2 * i - 1; j++)
                printf("*");
            printf("\n");
        }
    }
}