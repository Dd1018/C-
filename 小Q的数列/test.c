#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void num(int b[], int a,int d[])
{
    int i, j, t; t = 0;
    for (i = 0; i < 2 * a; i=i+2)
    {
        for (j = t; j < a; j++)
        {
            if (b[j] == 0)
            {
                d[i] = 0;
                break;
            }
            else if (b[j] == 1)
            {
                d[i] = 1;
                break;
            }
            else
            {
                d[i] = d[i / 2] + d[i % 2];
                break;
            }
        }
        t = j + 1;
    }
}
void num1(int b[], int a, int d[])
{
    int i,j;
    for (i = 1; i < 2 * a; i = i + 2)
    {
        for (j = 0; j < a; j++)
        {
            if (d[i - 1] == b[j])
            {
                d[i] = j ;
                break;
            }
        }
    }
}
int main()
{
    int a;
    scanf("%d", &a);
    int b[100];
    int i = 0;
    for (i = 0; i < a; i++)
        scanf("%d", &b[i]);
    int d[1000];
    int j = 0;
    num(b, a, d);
    num1(b, a, d);
    for (i = 0; i < 2 * a; i++)
    {
        printf("%d ", d[i]);
        if (i % 2 == 1&&i>0)
            printf("\n");
    }
    return 0;
}