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
    if (mod == 10 && a == 'X')      // ����Ϊ10����βλX
        printf("Right");
    if (mod == 10 && a != 'X')   //����Ϊ10����β��ΪX
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
    if (k[9] == mod && mod != 10)         //��β��������
        printf("Right");
    if (k[9] != mod && mod != 10)//��β����������
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
// CSDN���ӣ�https://blog.csdn.net/weixin_49449676/article/details/123985939?spm=1001.2014.3001.5501