#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c, d;
    scanf("%d %d %d", &a, &b, &c);
    if (c % b == 0)
        printf("%d", a - (c / b));
    else
        printf("%d", a - (c / b) - c % b);
    return 0;

//}//oBo买了一箱酸奶，里面有n盒未打开的酸奶，KiKi喜欢喝酸奶，第一时间发现了酸奶。KiKi每h分钟能喝光一盒酸奶，并且KiKi在喝光一盒酸奶之前不会喝另一个，那么经过m分钟后还有多少盒未打开的酸奶？
//
//输入描述：
//多组输入，每组输入仅一行，包括n，h和m（均为整数）。输入数据保证m <= n * h。
//输出描述：
//针对每组输入，输出也仅一行，剩下的未打开的酸奶盒数。