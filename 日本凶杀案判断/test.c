#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//
//A˵�������ҡ�
//
//B˵����C��
//
//C˵����D��
//
//D˵��C�ں�˵
//
//��֪3����˵���滰��1����˵���Ǽٻ���
//
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
int main()
{
	int a = 0, b = 0, c = 0, d = 0;    //1�����֣�0��������
	int i = 0;
	int FD;
	for (i = 1; i <= 4; i++)
	{
		if (i == 1)       //A��Ϲ˵
		{
			c = 1;
			d = 1;
			d = 0;
			FD = 1;
		}
		if (i == 2)// B��Ϲ˵
		{
			c = 0;
			a = 0;
			d = 1;
			d = 0;
			FD = 1;
		}
		if (i == 3)//C��Ϲ˵
		{
			a = 0;
			c = 1;
			d = 0;
			FD = 0;
		}
		if (i == 4)
		{
			a = 0;
			c = 1;
			d = 1;
			FD = 1;
		}
		if (a + b + c + d == 1 && FD == d)
		{
			printf("A=%d B=%d C=%d D=%d",a, b, c, d);
		}
	}
	return 0;
}
