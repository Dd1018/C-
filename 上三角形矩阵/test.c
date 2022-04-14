#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int b[100][100];
    int i, j;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (j >= i)
            {
                b[i][j] != 0;
            }
            else if (i>j)
            {
                if (b[i][j] != 0)
                {
                    printf("NO");
                    return 0;
                }
            }
        }
    }
    printf("YES");

    return 0;
}