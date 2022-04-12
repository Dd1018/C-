#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int i, j;
    int k, l;
    int c[100][100];
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            scanf("%d",& c[i][j]);
        }
    }
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            if (c[0][0] <= c[i][j])
            {
                c[0][0] = c[i][j];
                k = i + 1; l = j + 1;
            }
        }
    }
    printf("%d %d", k, l);
    return 0;
}
