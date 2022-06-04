#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    char a[] = "ABCD";
    int k = 0;
    scanf("%d", &k);
    char tmp;
    int i = 0;
    int str = strlen(a);
    while (k>0)
    {
        tmp = a[0];
        for (i = 0; a[i + 1] != '\0'; i++)
        {
            a[i] = a[i + 1];
        }
        a[i] = tmp;
        k--;
    }
    printf("%s", a);
    return 0;
}