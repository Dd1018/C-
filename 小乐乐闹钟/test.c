#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdio.h>
int main()
{
    int a, b, c;
    scanf("%d:%d %d", &a, &b, &c);
    printf("%02d:%02d", (a + (b + c) / 60) % 24, (b + c) % 60);        //(a+(b+c)/60)%24 (ԭ����ʱ��+��ԭ���ķ�+�룩/60)%24 ��ֹ����24Сʱ
    return 0;
}