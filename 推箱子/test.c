#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int n = 0;
	while (scanf("%d", &n) != EOF)
	{
		int row = 3 * n;
		int i = 0;
		int j = 0;
		for (i = 0; i < n; i++)
		{
			//ÿ�㵥λͼ����һ��ǰ��Ŀո�
			for (j = 0; j < row - 1; j++)
			{
				printf(" ");
			}
			//ÿ�㵥λͼ����һ�к���Ŀո�
			for (j = 0; j <= i; j++)
			{
				printf("*     ");
			}
			printf("\n");

			//ÿ�㵥λͼ���ڶ���ǰ��Ŀո�
			for (j = 0; j < row - 2; j++)
			{
				printf(" ");
			}
			//ÿ�㵥λͼ���ڶ��к���Ŀո�
			for (j = 0; j <= i; j++)
			{
				printf("* *   ");
			}
			printf("\n");

			//ÿ�㵥λͼ��������ǰ��Ŀո�
			for (j = 0; j < row - 3; j++)
			{
				printf(" ");
			}
			//ÿ�㵥λͼ�������к���Ŀո�
			for (j = 0; j <= i; j++)
			{
				printf("* * * ");
			}
			printf("\n");

			//ÿ���ӡ�꣬���е���һ��
			row -= 3;
		}

		//�����Ĵ�ӡ
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < (6 * n - 1) / 2; j++)
			{
				printf(" ");
			}
			printf("*\n");
		}
	}
	return 0;
}
