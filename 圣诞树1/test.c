#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int o, x, y, g, e, n;
    int m;
    printf("������ʥ����������");
    scanf("%d", &o);
    for (x = 0; x <= 1; x++)//��������
    {
        for (y = 0; y <= o - x + 3; y++)
        {
            printf(" ");
        }
        for (g = 0; g <= x * 2; g++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (e = 1; e <= 2 * o + 3; e++)//shushangxinxin
    {
        if (e == o + 5)//��ƫ
        {
            printf("*");
            continue;
        }
        printf(" ");
    }
    printf("\n");
    for (x = 0; x <= o; x++)//��һ��
    {
        for (y = 0; y <= o - x + 3; y++)
        {
            printf(" ");
        }
        for (g = 0; g <= x * 2; g++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (x = 2; x <= o + 3; x++)//����  �ڶ���
    {
        for (y = 0; y <= o - x + 3; y++)
        {
            printf(" ");
        }
        for (g = 0; g <= x * 2; g++)
        {
            printf("*");
        }
        printf("\n");
    }
    for (n = 1; n <= o; n++)//����
    {
        for (e = 1; e <= o + 5; e++)
        {
            if (e == o + 5)
            {
                printf("*\n");
                continue;
            }
            printf(" ");
        }
    }
    for (e = 1; e <= 2 * o + 5; e++)
    {
        if (e == o + 5)
        {
            printf("V");
            continue;
        }
        printf(" ");
    }
    printf("\n");
    printf("Merry Christmas!");
    return 0;
}