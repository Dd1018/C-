#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int a;
    int b;
    while ((a = getchar()) != EOF) 
    {
        b=getchar();   // ���տո��س�
        putchar(a + 32);
        printf("\n");
    }
    return 0;
}