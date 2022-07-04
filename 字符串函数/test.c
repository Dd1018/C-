#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
char* my_strcat(char *dest,const char *sorc)
{
	assert(dest && sorc);
	char* tmp = dest;
	while (*dest != '\0')
	{
		dest++;
	}//找到目标字符串里的\0
	while (*dest++ = *sorc++)
	{
		;
	}
	return dest;
}
int main()
{
	char arr1[20] = "hello ";
     my_strcat(arr1,arr1);
	printf("%s", arr1);
	return 0;
}