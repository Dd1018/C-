#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//void fun(int a)
//{
//	printf("%p %p\n",&a,&fun);
//	if (a == 0)
//		return;
//	else
//		fun(--a);
//}
//int main()
//{
//	int a = 10;
//	fun(a);
//	return 0;
//}
static int ret = 0;
int merga_sore(int* arr, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;

    merga_sore(arr, l, mid); merga_sore(arr, mid + 1, r);
    int i = l;
    int tmp[100];
    int k = 0;
    int j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[k++] = arr[i++];
        else
        {
            tmp[k++] = arr[j++];
            ret += (mid - i + 1);
        }
    }
    while (i <= mid)
        tmp[k++] = arr[i++];
    while (j <= r)
        tmp[k++] = arr[j++];
    for (i = l, j = 0; i <= r; i++, j++)
    {
        arr[i] = tmp[j];
    }
    return ret;
}
int main()
{
    int arr[100];
    int n;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);
    int c = merga_sore(arr, 0, n - 1);
    printf("%d", c);
    return 0;
}