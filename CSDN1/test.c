#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100] = "asdasd";
	int sz1 = strlen(a);
	char b [100]= "asdasdasdasdasdasd";
	int sz2 = strlen(b);
	unsigned int c = sz1 - sz2;
	printf("%d %d", sz1, sz2);

	return 0;
}