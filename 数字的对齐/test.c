#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n%8d\n%8d\n", a, b, c); //8 个空格的宽度靠右对齐输出。
    printf("%d\n%-8d\n%-8d", a, b, c); //8 个空格的宽度靠左对齐输出。
    return 0;
}