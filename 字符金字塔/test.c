#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char a;
    scanf("%c", &a);
    int i = 1;//行
    int j = 1;
    for (i = 1; i <= 5; i++)//从第一行开始  一共有5行
    {
        for (j = 5 - i; j >= 0; j--)//打印空格  空格从第一行到第五行空格是递减的  第一行四个空格第五行没有空格，所以利用循环 5-i表示打印的空格数去打印空格
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)//一行有几个字符取决于字符在第几行，在第几行打印打印几个字符
        {
            printf("%c ", a);
        }
        printf("\n");//循环完打印完一行换行
    }
    return 0;
}