#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a[20];
	int i = 0;
	while (i < 3)
	{
		printf("请输入密码:");
		scanf("%s", a);
		if (strcmp(a, "1234567") == 0)
		{
			printf("\n登陆成功");
			return 0;
		}
		else
		{
			printf("\n密码错误");
			i++;
		}
	}
	if (i == 3)
		printf("\n三次机会已用完");
	return 0;
}