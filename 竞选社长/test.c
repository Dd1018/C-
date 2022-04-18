#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    char a[1000];
    scanf("%s", a);
    int i = 0, j = 0, t = 0;
    for (i = 0; a[i] != 0; i++)
    {
        if (a[i] == 'A')
        {
            t++;
        }
        if (a[i] == 'B')
        {
            j++;
        }
    }
    if (t > j)
    {
        printf("A");
    }
    else if (t < j)
        printf("B");
    else if (t == j)
    {
        printf("E");
    }

    return 0;
}