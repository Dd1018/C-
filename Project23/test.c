#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int money = 20;//总共有多钱
	int empty = 20;//空瓶个数
	int total = 20;//换了多少瓶
	while(empty>=2)
	{
		total = total + empty/2;
	empty = empty / 2 + empty % 2;
	}
	printf("%d", total);
	return 0;
}