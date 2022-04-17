#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
int main()
{
	char a[] = { "hello  world!!!!!" };
	char b[] = { "#################" };
	int right = sizeof(a) / sizeof(a[0]) - 2;
	int left = 0;
	while (left <= right)
	{
		b[left] = a[left];
		b[right] = a[right];
		printf("%s\n", b);
		Sleep(1000);
		system("cls");
		left++;
		right--;
	}
	return 0;
}