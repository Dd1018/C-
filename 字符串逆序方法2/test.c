#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int mystrlen(char *a)
{
	int count = 0;
	while (*a != '\0')
	{
		a++;
		count++;
	}
	return count;
}
reverse_string(char a[], int left, int right)
{
	char tmp;
if(left < right)
	{
		tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		reverse_string(a, left+1, right - 1);
	}
}
int main()
{
	char a[] = "abc";
	int left = 0;
	int len = mystrlen(a) - 1;
	reverse_string(a, left, len);
	printf("%s", a);
	return 0;
}
//void reverse(char arr[], int left, int right)
//{
//	char tmp = arr[left];
//	arr[left] = arr[right];
//	arr[right] = tmp;
//	if(left<right)
//		reverse(arr, left+1, right-1);
//}
//
//int main()
//{
//	char arr[] = "abcdefg";//[a b c d e f \0]
//	int left = 0;
//	int right = mystrlen(arr)-1;
//	reverse(arr, left, right);
//
//	printf("%s\n", arr);
//
//	return 0;
//}