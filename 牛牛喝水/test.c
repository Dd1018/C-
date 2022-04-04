#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, d;
    scanf("%d %d", &a, &b);
    d = (a * b * b * 3.14);
    printf("%d", (10000 / d) + 1);
    return 0;
}
//牛牛口渴了，要喝10升水才能解渴，但现在只有一个深 h 厘米，底面半径是 r 厘米的水杯，牛牛最少要喝多少杯水才能解渴。
//
//水杯的体积公式是 \pi \times h \times r ^ 2 \π×h×r
//2
//，其中 \pi \π  取 3.14 ，h\h  和 r\r  是整数。
//输入描述：
//输入杯子的高度 h ，底面半径 r 。
//输出描述：
//输出牛牛最少要喝多少杯水