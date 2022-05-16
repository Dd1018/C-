#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <assert.h>
void my_strcpy(char* a, const char* b)
{
	assert(a != NULL);
	assert(b != NULL);
	while (*a++=*b++)
	{
		;
	}
}
int main()
{
	char a[] = "asd";
	char b []= "123";
	my_strcpy(a, b);
	printf("%s", a);
	return 0;
}