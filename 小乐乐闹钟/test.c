#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d:%d %d", &a, &b, &c);
    printf("%02d:%02d", (a + (b + c) / 60) % 24, (b + c) % 60);        //(a+(b+c)/60)%24 (原定的时钟+（原定的分+秒）/60)%24 防止超过24小时
    return 0;
}