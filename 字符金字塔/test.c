#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    char a;
    scanf("%c", &a);
    int i = 1;//��
    int j = 1;
    for (i = 1; i <= 5; i++)//�ӵ�һ�п�ʼ  һ����5��
    {
        for (j = 5 - i; j >= 0; j--)//��ӡ�ո�  �ո�ӵ�һ�е������пո��ǵݼ���  ��һ���ĸ��ո������û�пո���������ѭ�� 5-i��ʾ��ӡ�Ŀո���ȥ��ӡ�ո�
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)//һ���м����ַ�ȡ�����ַ��ڵڼ��У��ڵڼ��д�ӡ��ӡ�����ַ�
        {
            printf("%c ", a);
        }
        printf("\n");//ѭ�����ӡ��һ�л���
    }
    return 0;
}