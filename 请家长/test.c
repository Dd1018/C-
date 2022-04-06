#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, b;
    int i = 0;
    int j = 0, k = 0, l = 0, n = 0, m = 0;
    while (scanf("%d %d", &a, &b) != EOF)
    {
        getchar();
        for (i = a; i <= b; i++)
        {
            k = i / 100;      // 百位上的数字
            j = i % 10;         //各位上的数字
            l = (i / 10) % 10;
            m = b - a + 1;
            if (i != k * k * k + j * j * j + l * l * l)
            {
                n++;
                if (n == m)
                    printf("no\n");
            }
            else if (i == k * k * k + j * j * j + l * l * l)
                printf("%d ", i);
        }
    }
    return 0;
}