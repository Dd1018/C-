#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i;
    for (i = 10000; i < 100000; i++)
    {
        if (i == ((i / 10000) * (i % 10000)) + ((i / 1000) * (i % 1000)) + ((i / 100) * (i % 100)) + ((i / 10) * (i % 10)))
            printf("%d ", i);
    }
}