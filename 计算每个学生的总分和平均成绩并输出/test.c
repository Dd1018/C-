#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int student[3][4];
    int i = 0;
    int j = 0;
    double result[3][2];//����ͬѧ���ֺܷ�ƽ����
    double sum = 0;
    double avg = 0;

    for (i = 0; i < 3; i++)
    {
        sum = 0;
        printf("�������%d��ͬѧ�����ųɼ�(�м��ÿո�ָ�):", i + 1);
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &student[i][j]);
            sum += student[i][j];
        }
        result[i][0] = sum;
        result[i][1] = sum / 4.0;

    }

    for (i = 0; i < 3; i++)
    {
        printf("��%dλͬѧ���ܷ�Ϊ��%.1lf,ƽ����Ϊ��%.1lf\n",
            i + 1, result[i][0], result[i][1]);
    }
    return 0;
}