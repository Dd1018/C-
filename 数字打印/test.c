#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    char a;
    int b;
    float c;
    scanf("%c    %d    %f", &a, &b, &c);      
    printf("%c %d %.6f", a, b, c);      //%.6f打印6位小数
    return 0;
}