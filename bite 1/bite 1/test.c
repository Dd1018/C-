#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a;
	printf("输入 1 开启C语言之路\n");
	scanf("%d", &a);
	if (a == 1)
		printf("C语言正式开启,未来的路很漫长，加油！！！\n");
	else
		printf("开启失败\n");
	return 0;
}