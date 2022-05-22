#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void reserve(char* left, char* right)
{
    char tmp;
    while (left < right)
    {
        tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}
int main()
{
    char a[1000];
    gets(a);
    int sz = strlen(a) - 1;
    char* right = &a[sz];
    reserve(a, right);
    printf("%s", a);
    return 0;
}