#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    int sum = 0;
    scanf("%d", &a);
    int b[10000] = { 0 };
    int i;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < a; i++)
    {
        int k;
        if (b[0] <= b[i])
        {
            k = b[0];
            b[0] = b[i];
            b[i] = k;
        }
    }
    for (i = 0; i < a; i++)
    {
        if (b[1] >= b[i])
            b[1] = b[i];
    }
    if (a != 1)
        sum = b[0] - b[1];
    else
        sum = 0;
    printf("%d", sum);
    return 0;
}