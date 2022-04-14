#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int i, j;
    int b[100][100];
    for (i = 0; i < a; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == i)
            {
                b[i][j] = 1;
                printf("1");
            }
            else if (j == 0)
            {
                b[i][j] = 1;
                printf("1");
            }
            else
            {
                b[i][j] = b[i - 1][j - 1] + b[i - 1][j];
                printf("%2d", b[i][j]);
            }

        }
        printf("\n");
    }
    return 0;
}