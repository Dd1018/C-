#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int i = 0;
    int b[1000];
    int j = 0;
    int max = 0;
    int t = 0;
    for (i = 0; i < a; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < a; i++)
    {
        for (j = 1; j * j <= b[i]; j++)
        {
            if (j * j == b[i])
            {
                t = b[i];
                break;
            }
        }
        if (t != b[i] && b[i] > max)
            max = b[i];
    }
    printf("%d", max);
    return 0;
}