#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char a[20];
	int i = 0;
	while (i < 3)
	{
		printf("����������:");
		scanf("%s", a);
		if (strcmp(a, "1234567") == 0)
		{
			printf("\n��½�ɹ�");
			return 0;
		}
		else
		{
			printf("\n�������");
			i++;
		}
	}
	if (i == 3)
		printf("\n���λ���������");
	return 0;
}