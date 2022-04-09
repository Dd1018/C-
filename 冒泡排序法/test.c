#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int b[50];
    int i, j;
    int k;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a -i-1; j++)
        {
            if (b[j] <= b[j+1])
            {
                k = b[j];
                b[j] = b[j+1];
                b[j+1] = k;
            }
        }
    }
    for (i = 0; i < a; i++)
    {
        printf("%d ", b[i]);
    }
    return 0;
}