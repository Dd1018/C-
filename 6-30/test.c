#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
void Daozhi1(char* a,int sz)
{
int left = 0;
char tmp;
int right = sz;
while (left < right)
{
	tmp = a[left];
	a[left] = a[right];
	a[right] = tmp;
	left++;
	right--;
}
}
void Daozhi2(char *a)
{
	int left = 0;
	int right = 0;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		while ((a[right] != ' ')&&( a[right] != '\0'))
		{
			right++;
		}
		int k = right;
		right--;
		char tmp;
		while (left < right)
		{
			tmp = a[left];
			a[left] = a[right];
			a[right] = tmp;
			left++;
			right--;
		}
		left = ++k;
		right = ++k;
	}
}
int main()
{
	char a[] = "i like beijing.";
	int sz = sizeof(a) -2;
	Daozhi1(a,sz);
	Daozhi2(a);
	printf("%s\n", a);
	printf("%s\n", a);
	return 0;
}