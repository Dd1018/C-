#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c[5][5];
    int i, j;
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < b; j++)
        {
            scanf("%d", &c[i][j]);
        }
    }
    int e, f;
    scanf("%d %d", &e, &f);
    printf("%d ", c[e - 1][f - 1]);
    return 0;

}