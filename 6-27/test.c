#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	int a = 0;
	int b = 0;
	int c;
	scanf("%d %d", &a, &b);
	int i = 0;
	int sum = 0;
	c = a ^ b;
	for (i = 0; i < 32; i++)
	{
		if ((c >> i) & 1)
			sum++;
	}
	printf("%d", sum);
	return 0;
}