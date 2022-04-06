#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int i;
    int j;
    int k = 0;
    for (i = 1; i <= 2019; i++)
    {
        for (j = i; j != 0; j)
        {
            if (j % 10 == 9 || (j % 100) / 10 == 9 || (j % 1000) / 100 == 9)
            {
                k++;
                break;
            }
            j = j / 10;
        }
    }
    printf("%d", k);
    return 0;
}