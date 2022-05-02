#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
    int a;
    scanf("%d", &a);
    int b[100];
    int i, j;
    for (i = 0; i < a; i++)
        scanf("%d", &b[i]);
    for (i = 0; i < a; i++)
    {
        for (j = 2; j < sqrt(b[i]); j++)
        {

            if (b[i] % j == 0)
            {
                printf("false\n");
                break;
            }
        }
        if (j >=sqrt(b[i]))
        {
            printf("true\n");
        }
    }
    return 0;
}