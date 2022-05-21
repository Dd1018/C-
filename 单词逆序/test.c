#define _CRT_SECURE_NO_WARNINGS
#include<string.h> 
#include<stdio.h>
int main()
{
	char a[100];
	gets(a);
	char c[100]; int sz = strlen(a); 
	int right = sz - 1;
	int t = sz;
	int j = 0;
	int i = 1; 
	int sum = 0; 
	for (int s = 0; s != sz; s++)
	{
		if (a[s] == ' ')
		sum++;
	}
	for (sum; sum >= 0; sum--)
		{ 
		while (a[right] != ' '&&right>=0)
		{ 
			right--;
			i++;
		}
		int k = right + 1; 
		i--; 
		for (i; i != 0; i--)
		{ 
			c[j++] = a[k++];
		}
		if (right >= 0)
			c[j++] = ' ';
		else
			c[j] = '\0';
		right = right - 1;
		i = 1; 
	}
 printf("%s", c);
	return 0;
}