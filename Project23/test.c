#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int money = 20;//�ܹ��ж�Ǯ
	int empty = 20;//��ƿ����
	int total = 20;//���˶���ƿ
	while(empty>=2)
	{
		total = total + empty/2;
	empty = empty / 2 + empty % 2;
	}
	printf("%d", total);
	return 0;
}