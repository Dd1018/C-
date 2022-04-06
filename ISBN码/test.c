#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int  main()
{
    char a = 'w';
    int i = 0;
    int j = 0;
    int t = 1;
    int sum = 0;
    int mod;
    int k[10] = { 0 };
    for (i = 0; i < 13; i++)
    {
        scanf("%c", &a);
        if ((a - '0') >= 0 && (a - '0' <= 9) || a == 'X')
            k[j++] = a - '0';
    }
    for (i = 0; i < 9; i++)
    {
        sum = k[i] * (t++) + sum;
    }
    mod = sum % 11;
    if (mod == 10 && a == 'X')      // 余数为10，结尾位X
        printf("Right");
    if (mod == 10 && a != 'X')   //余数为10，结尾不为X
    {
        for (i = 0; i < 9; i++)
        {
            if (i == 0)
                printf("%d-", k[i]);
            else if (i == 4 || i == 9)
                printf("-%d", k[i]);
            else
                printf("%d", k[i]);
        }
        printf("-X");
    }
    if (k[9] == mod && mod != 10)         //结尾等于余数
        printf("Right");
    if (k[9] != mod && mod != 10)//结尾不等于余数
    {
        for (i = 0; i < 9; i++)
        {
            if (i == 0)
                printf("%d-", k[i]);
            else if (i == 4 || i == 9)
                printf("-%d", k[i]);
            else
                printf("%d", k[i]);
        }
        printf("-%d", mod);
    }
    return 0;
}
// CSDN链接：https://blog.csdn.net/weixin_49449676/article/details/123985939?spm=1001.2014.3001.5501