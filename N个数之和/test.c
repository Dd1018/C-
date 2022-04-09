#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    int i;
    int b[50] = {0};
    int sum = 0;
    for (i = 0; i < a; i++)
    {
        scanf("%d",&b[i]);
        sum = sum + b[i];
    }
    printf("%d", sum);
    return 0;
}