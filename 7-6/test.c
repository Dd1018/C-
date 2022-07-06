#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* des,const char* src)
{
	assert(des && src);
	char* tmp = des;
	while (*des != '\0')
	{
		des++;
	}
	while (*des++ = *src++)
	{
		;
	}
	return tmp;
}
size_t my_strlen(const char* a)
{
	assert(a);
	size_t b = 0;
	while (*a++!='\0')
	{
		b++;
	}
	return b;
}
char* my_strcpy(char* des, const char* src)
{
	char* tmp = des;
	assert(des && src);
	while (*des++ = *src++)
	{
		;
	}
	return tmp;
}
int main()
{
	char a []= "1234567";
	char b[20] = "abcdefg";
	char d[20] = "abcdef";
	char e[] = "1234567";
	size_t c = my_strlen(a);
	my_strcpy(d, e);
	printf("%d\n",c);
	my_strcat(b, a);
	printf("%s\n", b);
	printf("%s", d);
	return 0;
}