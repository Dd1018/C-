#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void resever(char *left,char *right)
{
	char tmp;
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
int main()
{
	char a[101];
	gets(a);
	int left =a;
	int len = strlen(a);
	resever(a, a+len-1);
	char* start = a;
	char* end = a;
	while (*end)
	{

		while (*end != ' '&&*end!='\0')
		{
			end++;
		}//end出来之后为空格
		resever(start, end-1);
		if (*end != '\0')
			end++;
		start = end;
	}
	printf("%s", a);
	return 0;
}