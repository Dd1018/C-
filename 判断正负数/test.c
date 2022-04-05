#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a[10] = {0};
    int i=0;
    int j = 0, k = 0;
    while (i < 10)
    {
        scanf("%d", &a[i]);
        i++;
    }
    for (i = 0; i < 10; i++)
    {
        if (a[i] > 0)
        {
            k++;
        }
        else if (a[i] < 0)
        {
            j++;
        }
    }
    printf("positive:%d\n", k);
    printf("negative:%d\n", j);
    return 0;
}