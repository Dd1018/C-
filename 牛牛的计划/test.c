#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b, c, d, e, f;
    while (scanf("%d", &a) != EOF && scanf("%d", &b) != EOF && scanf("%d", &c) != EOF)
    {
        getchar();
        while (scanf("%d", &d) != EOF && scanf("%d", &e) != EOF && scanf("%d", &f) != EOF)
        {
            getchar();
            if (a < d)
            {
                printf("yes\n");
                break;
            }
            else if (a <= d && b < e)
            {
                printf("yes\n");
                break;
            }
            else if (a <= d && b <= e && c <= f)
            {
                printf("yes\n");
                break;
            }
            else
            {
                printf("no\n");
                break;
            }
        }
    }
    return 0;
}