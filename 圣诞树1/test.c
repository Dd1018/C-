#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int o, x, y, g, e, n;
    int m;
    printf("请输入圣诞树层数：");
    scanf("%d", &o);
    for (x = 0; x <= 1; x++)//树上星星
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
        if (e == o + 5)//右偏
        {
            printf("*");
            continue;
        }
        printf(" ");
    }
    printf("\n");
    for (x = 0; x <= o; x++)//第一个
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
    for (x = 2; x <= o + 3; x++)//层数  第二个
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
    for (n = 1; n <= o; n++)//树干
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