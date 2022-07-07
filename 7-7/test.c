#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<assert.h>
//int my_strcmp(const char* arr1, const char* arr2)
//{
//	assert(arr1 && arr2);
//	while (*arr1!='\0'&& * arr1 == *arr2)
//	{
//		arr1++;
//		arr2++;
//	}
//	return (*arr1 - *arr2);
//}
//int main()
//{
//	char arr1[] = "abc";
//	char arr2[] = "abcdefg";
//	int c=my_strcmp(arr1, arr2);
//	if (c > 0)
//		printf(">");
//	else if (c == 0)
//		printf("=");
//	else
//		printf("<");
//	return 0;
//}
#include<string.h>
//int main()
//{
//	char arr1[20] = "abcdefghhhh";
//	char arr2[20] = "1234567";
//	strncpy(arr1, arr2, 10);
//	printf("%s", arr1);
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "123\0 56789";
//	char arr2[20] = "abcdefg";
//	strncat(arr1, arr2, 3);
//	printf("%s", arr1);
//	return 0;
//}
//int main()
//{
//	char arr1[20] = "abcdef";
//	char arr2[10] = "acdfff";
//	int ret=strncmp(arr1, arr2, 3);
//	if (ret < 0)
//		printf("<");
//	else if (ret == 0)
//		printf("==");
//	else if (ret > 0)
//		printf(">");
//	return 0;
//}
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[] = "1";
//	char* ret = strstr(arr1, arr2);
//	if (ret ==NULL)
//		printf("没找到");
//	else
//		printf("%s", ret);
//	return 0;
//}
//char* my_strstr(char* a, char* b)
//{
//	assert(a && b);
//	const char* s1 = a;
//	const char* s2 = b;
//	const char* p = a;
//	while (*p)
//	{
//		s1 = p;
//		s2 = b;
//		while (*s1!='\0'&&*s2!='\0'&& * s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return p;
//		p++;
//	}
//	return NULL;
//}
//int main()
//{
//	char a[] = "abbbcdef";
//	char b[] = "bcc";
//	char *ret=my_strstr(a, b);
//	printf("%s", ret);
//	return 0;
//}
//char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	char* s1 = str1;
//	char* s2 = str2;
//	char* p = str1;
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (*s1 == *s2&&*s1!='\0'&&*s2!='\0')
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//			return p;
//		p++;
//	}
//	return NULL;
//}
//int main()
//{
//	char str1[] = "132456879";
//	char str2[] = "56";
//	char *ret=my_strstr(str1, str2);
//	printf("%s", ret);
//	return 0;
//}
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1== *str2&&str1!='\0')
//	{
//		str1++;
//		str2++;
//	}
//	return (*str1 - *str2);
//}
//int main()
//{
//	char a[] = "abcdefg";
//	char b[] = "z";
//	int c=my_strcmp(a, b);
//	if (c> 0)
//		printf(">");
//	else if (c< 0)
//		printf("<");
//	else
//		printf("==");
//	return 0;
//}
//int main()
//{
//	char a[] = "123@@456#789";
//	char b[] = "@#";
//	for (char* ret = strtok(a, b); ret != NULL; ret = strtok(NULL, b))
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}
//#include<errno.h>
//int main()
//{
//	//errno:全局错误码存放的全局变量
//	FILE *pf=fopen("test.txt", "r");
//	if (pf == NULL)
//	{
//		printf("%s", strerror(errno));
//		return 1;
//	}
//	return 0;
//}
//#include<ctype.h>
//int main()
//{
//	int a = isspace('w');
//	printf("%d", a);
//	return 0;
//}
void* my_memcpy(void* a,const void* b, int s)
{
	assert(a && b);
	void* ret = a;
	while (s--)
	{
		*(char*)a = *(char*)b;
		a=(char*)a+1;
		b=(char*)b+1;
	}
	return ret;
}
int main()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10 };
	//             1,2,1,2,3,4,5,6,7,8
	int arr2[] = { 0 };
	my_memcpy(arr1+2, arr1, 20);
	for (int i = 0; i < 10; i++)
		printf("%d ", arr1[i]);
	return 0;
}