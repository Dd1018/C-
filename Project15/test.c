#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int i;
int main()
{
    i--;
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
    return 0;
}