#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
int main()
{
    double a, b, c, d, e;
    while (scanf("%lf", &a) != EOF && scanf("%lf", &b) != EOF && scanf("%lf", &c) != EOF)
    {
        getchar();
        e = b * b - 4 * a * c;
        if (a == 0)
        {
            printf("Not quadratic equation");
            return 0;
        }
        else
        {
            if (e == 0)
            {
                e = (-b + sqrt(e)) / (2 * a);
                if (e == 0)
                    printf("x1=x2=0.00\n");
                else
                    printf("x1=x2=%.2lf\n", e);
            }
            else if (e > 0)
            {
                printf("x1=%.2lf;", (-b - sqrt(e)) / (2 * a));
                printf("x2=%.2lf", (-b + sqrt(e)) / (2 * a));
            }
            else if (e < 0.0)
            {
                d = (-b) / (2 * a);
                e = sqrt(-e) / (2 * a);
                if (e < 0)
                {
                    printf("x1=%.2lf%.2lfi;", d, e);
                    printf("x2=%.2lf+%.2lfi", d, -e);
                }
                else
                {
                    printf("x1=%.2lf-%.2lfi;", d, e);
                    printf("x2=%.2lf+%.2lfi", d, e);
                }
            }
        }
    }
    return 0;
}/*�Ӽ�������a, b, c��ֵ����̼��㲢���һԪ���η���ax2 + bx + c = 0�ĸ�����a = 0ʱ�������Not quadratic equation������a �� 0ʱ�����ݡ� = b2 - 4 * a * c������������㲢������̵ĸ���
����������
�������룬һ�У���������������a, b, c����һ���ո�ָ�����ʾһԪ���η���ax2 + bx + c = 0��ϵ����
���������
���ÿ�����룬���һ�У����һԪ���η���ax2 + bx + c = 0�ĸ��������

���a = 0�������Not quadratic equation����

���a ��  0�������������

�� = 0��������ʵ����ȣ������ʽΪ��x1 = x2 = ...��

�� > 0��������ʵ�����ȣ������ʽΪ��x1 = ...; x2 = ...������x1 <= x2��

�� < 0����������������������x1 = ʵ�� - �鲿i; x2 = ʵ�� + �鲿i����x1���鲿ϵ��С�ڵ���x2���鲿ϵ����ʵ��Ϊ0ʱ����ʡ�ԡ�ʵ�� = -b / (2 * a), �鲿 = sqrt(-��) / (2 * a)

    ����ʵ������Ҫ��ȷ��С�����2λ�����֡�����֮��û�пո�*/