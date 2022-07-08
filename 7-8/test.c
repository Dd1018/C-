#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* tmp = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return tmp;
//}
//int main()
//{
//	char a[20] = "1234657";
//	char b[] = "abcdefg";
//	my_strcat(a, b);
//	printf("%s", a);
//	return 0;
//}
//int my_strcmp(char* a, char* b)
//{
//	while (*a == *b && *a != '\0')
//	{
//		a++;
//		b++;
//	}
//	return (*a - *b);
//}
//int main()
//{
//	char a[] = "abcdef";
//	char b[] = "1234567";
//	int ret = my_strcmp(a, b);
//	if (ret == 0)
//		printf("==");
//	else if (ret > 0)
//		printf(">");
//	else
//		printf("<");
//	return 0;
//}
//char* my_strstr(const char* des, const char* src)
//{
//	char* p = des;
//	char* str1 = des;
//	char* str2 = src;
//	while (*p)
//	{
//		str1 = p;
//		str2 = src;
//		while (*str1!='\0'&& * str1 == *str2)
//		{
//			str1++;
//			str2++;
//		}
//		if (*str1 == '\0')
//			return p;
//		p++;
//	}
//	return NULL;
//}
//int main()
//{
//	char a[] = "1234567";
//	char b[] = "567";
//	char*ret=my_strstr(a, b);
//	printf("%s", ret);
//	return 0;
//}
void* my_memcpy(void* str1, void* str2, int num)
{
	while (num--)
	{
		*(char*)str1 =* (char*)str2;
		str1 = (char*)str1 + 1;
		str2 = (char*)str2 + 1;
	}
	return str1;
}
int main()
{
	char a[] = "123.123.165@156#";
		char b[] = ".@#";
		for (char *ret=strtok(a, b);ret!=NULL ; ret=strtok(NULL, b))
		{
			printf("%s \n", ret);
		}
		char c[20] = "123465";
		char d[10] = "abcdef";
		char e[10] = "778899";
		memcpy(c, d, 4);
		printf("%s\n", c);
		my_memcpy(c, e, 2);
		printf("%s\n", c);
		return 0;
}