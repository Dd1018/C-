#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int b[100];
    int c[100];
    int i, j;
    int t = 0, z = 0;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < a; i++)
    {
        t = a-1;
        z = a-1;
        for (j = 0; j <= a - i-1; j++)
        {
            if (b[j] <= b[j + 1])
                t++;
            else if (b[j] >= b[j + 1])
                z++;
        }
    }
    if ((t == a&&t!=a-1)||(z==a&&z!=a-1))
    {
        printf("sorted");
        return 0;
    }
    else
    {
        printf("unsorted");
        return 0;
    }
}