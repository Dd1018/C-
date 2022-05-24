#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//
//A说：不是我。
//
//B说：是C。
//
//C说：是D。
//
//D说：C在胡说
//
//已知3个人说了真话，1个人说的是假话。
//
//现在请根据这些信息，写一个程序来确定到底谁是凶手。
int main()
{
	int a = 0, b = 0, c = 0, d = 0;    //1是凶手，0不是凶手
	int i = 0;
	int FD;
	for (i = 1; i <= 4; i++)
	{
		if (i == 1)       //A在瞎说
		{
			c = 1;
			d = 1;
			d = 0;
			FD = 1;
		}
		if (i == 2)// B在瞎说
		{
			c = 0;
			a = 0;
			d = 1;
			d = 0;
			FD = 1;
		}
		if (i == 3)//C在瞎说
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
