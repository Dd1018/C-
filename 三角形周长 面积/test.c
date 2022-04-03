#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c;
    float d;
    float x;
    scanf("%d %d %d", &a, &b, &c);
    d = a + b + c;
    float p = d / 2;
   x = sqrt(p * (p - a) * (p - b) * (p - c));
    printf("circumference=%.2f area=%.2f", d, sqrt(p * (p - a) * (p - b) * (p - c)));
    return 0;
}