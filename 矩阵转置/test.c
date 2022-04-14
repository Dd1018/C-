#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int i = 0, j = 0;
    int c[100][100];
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    for (i = 0; i < b; i++)
    {
        for (j = 0; j < a; j++)
        {
            printf("%d ", c[j][i]);
        }
        printf("\n");
    }
    return 0;
}