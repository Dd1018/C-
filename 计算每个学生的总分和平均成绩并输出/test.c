#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int student[3][4];
    int i = 0;
    int j = 0;
    double result[3][2];//三个同学的总分和平均分
    double sum = 0;
    double avg = 0;

    for (i = 0; i < 3; i++)
    {
        sum = 0;
        printf("请输入第%d个同学的四门成绩(中间用空格分隔):", i + 1);
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
        printf("第%d位同学的总分为：%.1lf,平均分为：%.1lf\n",
            i + 1, result[i][0], result[i][1]);
    }
    return 0;
}