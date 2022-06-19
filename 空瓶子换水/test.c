#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int money = 20;
	int sum = 20;//×ÜÆ¿Êý
	int t = 0;
	while (money % 2 == 0)
	{
		sum = sum + money / 2;
		money = money / 2;
	}
	while (money / 2 != 0)
	{
		sum = sum + money /2;
		t = t + money % 2;
		money = money / 2;
	}
	sum = sum + t;
	printf("%d", sum);
	return 0;
}
