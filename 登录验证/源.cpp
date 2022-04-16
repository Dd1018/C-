#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char a[10];
    char b[10];
    scanf("%s %s", &a, &b);
    if (strcmp(a, "admin") + strcmp(b, "admin") == 0)
    {
        printf("Login Success!");
    }
    else
    {
        printf("Login Fail!");
    }
    return 0;
}