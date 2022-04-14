#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    getchar();
    char c[1001][1001];
    int i, j;
    int count;
    for (i = 0; i < a + 2; i++)
    {
        for (j = 0; j < b + 2; j++)
        {
            c[i][j] = '0';
        }
    }
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            scanf("%c ", &c[i][j]);
        }
    }
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            if (c[i][j] != '*')
            {
                count = 0;
                if (c[i - 1][j - 1] == '*')
                    count++;
                if (c[i][j - 1] == '*')
                    count++;
                if (c[i + 1][j - 1] == '*')
                    count++;
                if (c[i + 1][j] == '*')
                    count++;
                if (c[i + 1][j + 1] == '*')
                    count++;
                if (c[i][j + 1] == '*')
                    count++;
                if (c[i - 1][j + 1] == '*')
                    count++;
                if (c[i - 1][j] == '*')
                    count++;
                c[i][j] = count;
            }

        }
    }
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= b; j++)
        {
            if (c[i][j] == '*')
                printf("*");
            else
                printf("%d", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}