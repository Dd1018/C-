#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int n;//输入一定的天数
    scanf("%d",& n);
    int i;
    int j=1;
    int z=1;
    int sum = 0;
    for (i = 1; i <= n; i++)
    {
        sum = sum + z;
        if (i == j)
        {
            z++;
            j = j + z;
        }

    }
    printf("%d", sum);
    return 0;
}