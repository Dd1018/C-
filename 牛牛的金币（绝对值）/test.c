#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
    int a, b, c, d;
    scanf("%d %d\n", &a, &b);
    scanf("%d %d", &c, &d);
    if (abs(c - a) + abs(d - b) == 1)
    {
        if (d == (b + 1))
            printf("u");
        else if (d == (b - 1))
            printf("d");
        else if (c == (a + 1))
            printf("r");
        else if (c == (a - 1))
            printf("l");
    }
    return 0;
}