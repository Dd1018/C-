#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int my_strlen(char* a)
{
	int count = 0;
	while (*a != '\0')
	{
		a++;
		count++;
	}
	return count;
}
int main()
{
	char a[] = "asd";
	int c=my_strlen(a);
	printf("%d", c);
	return 0;
}