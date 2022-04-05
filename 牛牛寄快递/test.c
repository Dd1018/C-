#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    float a, c, d;
    char b;
    scanf("%f %c", &a, &b);
    if (a >= 1.0)
    {
        if (b == 'y')
        {
            c = a - (int)(a * 10) / 10;
            if (c > 0.0 && c < 1.0)
                printf("%d", (int)(a - 1 + 20 + 1 + 5));
            else
                printf("%d",(int)( a - 1 + 20+5));
        }
            else if (b == 'n')
            {
                c = a - (int)(a * 10) / 10;
                if (c > 0.0 && c < 1.0)
                    printf("%d", (int)(a - 1 + 20 + 1));
                else
                    printf("%d", (int)(a - 1 + 20));
            }
        else
        {
            if (b == 'y')
                printf("%d", 25);
            else if (b == 'n')
                printf("%d", 20);
        }
        return 0;

    }
}