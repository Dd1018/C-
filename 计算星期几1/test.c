#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
    int a;
    int b;
    scanf("%d %d", &a, &b);
    if (a >= 1 && a <= 7 && b >= 1 && b <= 1000)
    {
        if((a+b)%7==0)              //�� 2 5���7 7%7=0 ��ʱ��+7
            printf("%d", ((a + b) % 7)+7);
        else
        printf("%d", (a + b) % 7);
    }
    return 0;
}