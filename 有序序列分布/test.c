#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c[1000];
    int d[1000];
    int e = a + b;
    int z[1000];
    int i = 0;
    int h = 0;
    int t = 0, j = 0;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &c[i]);
        t++;
    }
    for (i = 0; i < b; i++)
    {
        scanf("%d", &d[i]);
        j++;
    }
    for (i = 0; i <(t+j); i++)
    {
        if (i < t)
            z[i] = c[i];
        if (i >=t && i < t + j)
            z[i] = d[h++];
    }
    for (i = 0; i < e; i++)
    {
        for (j = 0; j <e - i-1; j++)
        {
            if (z[j] >= z[j+1] )
            {
                t = z[j];
                z[j] = z[j + 1];
                z[j + 1] = t;
            }
        }
    }
        for (i = 0; i < e; i++)
        {
            printf("%d ", z[i]);
        }
    return 0;
}