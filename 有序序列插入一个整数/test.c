#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a, c;
    scanf("%d", &a);
    int b[50];
    int d[50];
    int i, j, k;
    for (i = 0; i < a; i++)
    {
        scanf("%d", &b[i]);
    }
    scanf("%d", &c);
    for (i = 0, j = 0; i < a; i++, j++)
    {
        if ((b[i]<=c)&&(b[i+1]>=c))
        {
            d[j] = b[i];
            d[j+1] = c;
            j++;
        }
        else  if (c <= b[i] && i == 0)
        {
            d[j] = c;
            d[j + 1] = b[i];
            j++;
        }
        else if (i==a-1&&b[i]<c)
        {
            d[j] = b[i];
            d[j + 1] = c;
        }
        else
        {
            d[j] = b[i];
        }
    }
    for (i = 0; i <= a; i++)
    {
        printf("%d ",d[i]);
    }
    return 0;
}
