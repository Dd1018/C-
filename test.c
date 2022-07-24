#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
fun(char *arr,int left, int right)
{
    char tmp;
    while (left < right)
    {
        tmp = arr[left];
        arr[left]= arr[right];
        arr[right] = tmp;
       left++;
        right--;
    }
}
int main()
{
    char arr[10000];
    int i = 0;
    int j = 0;
    gets(arr);
    fun(arr, 0, strlen(arr) - 1);
        while (1)
        {
            while (arr[i] == ' '||arr[i]=='\0')
            {
                i--;
                fun(arr,j, i);
                j = i + 2;
                i++;
                break;
            }
            if (arr[i] != '\0')
                i++;
            else
                break;
        }
    printf("%s", arr);
    return 0;
}