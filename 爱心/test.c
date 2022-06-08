#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <windows.h>
#include<tchar.h>
int main()
{
    system("color F1");     //控制面板的颜色，F4为红色
    double x, y, a;
    for (y = 1.5; y > -1.5; y -= 0.1214)  //调好的参数，爱心形状，可以自行调参数，改变爱心的形状
    {
        for (x = -1.5; x < 1.5; x += 0.05)
        {
            a = x * x + y * y - 1;
            if (a * a * a - x * x * y * y * y <= 0)    //爱心方程
            {
                printf("*");
                Sleep(1);        //Sleep调节速度，可以调节爱心打印的速度
            }
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

