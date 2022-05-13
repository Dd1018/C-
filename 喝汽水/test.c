#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int money;
	scanf("%d", &money);
	int s = 0;     
	int t = 0;
	int sum = money;
	while (money!=0)
	{
		if (money == 1)
		{
			s = money + t;
			t = 0;
		}
				sum = sum + s;
				if (money % 2 != 0&&money>1)
				{
					t++;
				}
				s=money = money / 2; 
				
	}
	printf("%d", sum);
	return 0;
}