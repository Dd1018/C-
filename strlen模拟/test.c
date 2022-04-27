#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int Strlen(char* a)
{
	if (*a != '\0')
		return 1+Strlen(a + 1);
	else
		return 0;
}
int reverse_string(char* b)
{
	char tmp = *b;
	int len = Strlen(b) - 1;
	*b = *(b + len);
	*(b + len)='\0';
	if(strlen(b+1)>2)
	reverse_string(b + 1);
	*(b + len) = tmp;
}
int main()
{
	char a[] = "abcde";
	reverse_string(a);
	printf("%s", a);
	return 0;
}