#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    char a,b;
    while (scanf("%c", &a) != EOF)
    {
        b=getchar();
        if (a == 'a' || a == 'A' || a == 'E' || a == 'e' || a == 'i' || a == 'I' || a == 'U' || a == 'u' || a == 'O' || a == 'o')
            printf("Vowel\n");
        else
            printf("Consonant\n");
    }
    return 0;
}