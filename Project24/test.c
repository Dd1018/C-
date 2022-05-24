#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			for (c = 1; c <=5; c++)
			{
				for (d = 1; d <= 5; d++)
				{
					for (e = 1; e <= 5; e++)
					{
						if (((a != b) && (b != c) && (c != d) && (d != e)))
						{
							if (((b == 2) + (a == 3) == 1)&& 
								((b == 2) + (e == 4) == 1) && 
								((c == 1) + (d == 2) == 1) &&
								((c == 5) + (d == 3) == 1) && 
								((e == 4) + (a == 1) == 1))
							{
								if ((a * b * c * d * e) == 120)
								{
									printf("a=%d名\n", a);
									printf("b=%d名\n", b);
									printf("c=%d名\n", c);
									printf("d=%d名\n", d);
									printf("e=%d名\n", e);
								}
							}
						}
					}
				}
			}
		}
	}
	system("pause");
	return 0;
}