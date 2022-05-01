#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//int main()
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//    int i;
//    int c[100];
//    int d[100];
//    int e[100];
//    int sum = 0;
//    for (i = 0; i < a; i++)
//    {
//        scanf("%d",&c[i]);
//        sum = c[i] + sum;
//    }
//    for (i = 0; i < b; i++)
//    {
//        scanf("%d", &d[i]);
//    }
//    int j = 0;
//    int t = 0;
//    for (i = 0,j=0; i < b/2; j=j+2,i++)
//    {
//        e[i] = sum - d[j]-d[j+1];
//    }
//    for (i = 0; i < b; i++)
//    {
//        if (e[0] > e[i])
//        {
//            e[0] = e[i];
//            t = i;
//        }
//    }
//    printf("%d %d\n", e[2*t],e[2*t+1]);
//    return 0;
//}
int num(int a, int b)
{
    if (a >= b)
        return a - b;
    else
        return b - a;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[100] = { 0 };
    int b[100] = { 0 };
    int sum1 = 0, sum2 = 0, min, k, l;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];
    }
    min = sum1;       //min等于第一个数组的和
    for (int i = 0; i < m; i++)
    {
        sum2 = b[i];
        for (int j = i + 1; j <= m; j++)
        {
            if (num(sum1, sum2) < min)            //第一个数组的和减第二个数组每一个数字
            {
                min = num(sum1, sum2);
                k = i;                             //把i和j的值进行保存
                l = j;
            }
            sum2 += b[j];                            //sum2+他隔壁的数字

        }
    }
    for (int i = k; i < l; i++)
    {
        printf("%d ", b[i]);
    }

    return 0;
}