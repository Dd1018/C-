#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Ackmann(int a, int b)
{
    if (b == 0)
        return a + 1;
    if (b > 0 && a == 0)
        return Ackmann(b, 1);
    if (b > 0 && a > 0)
        return Ackmann(b - 1, Ackmann(b, a - 1));
}
int main()
{
    int a; int b;
    scanf("%d %d", &a, &b);
    printf("%d", Ackmann(a, b));
    return 0;
}