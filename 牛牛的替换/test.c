#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    getchar();
    char c[100];
    char d[4];
    int i;
    for (i = 0; i <= 3; i++)
    {
        if (i == 3)
            scanf("%c", &d[i]);
        else
            scanf("%c ", &d[i]);
    }
    getchar();
    for (i = 0; i < a; i++)
        scanf("%c", &c[i]);
    for (i = 0; i < a; i++)
    {
    
            if (c[i] == d[0])
            {
                c[i] = d[1];
                 
            }
            if (c[i] == d[2])
            {
                c[i] = d[3];
            }
            printf("%c", c[i]);
    }
    return 0;
}