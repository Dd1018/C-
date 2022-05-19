#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	char arr[100] = { 0 };
	gets(arr);
	int left = 0;
	int right = strlen(arr) - 1;
	char tmp;
	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;
		left++;
		right--;
	}
	printf("%s", arr);
	return 0;
}