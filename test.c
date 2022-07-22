#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
//void Find(int* arr, int sz, int* p1, int* p2)
//{
//	int i= 0;
//	int p = 0;
// 	for (i = 0; i < sz; i++)
//	{
//		p = p ^ arr[i];
//	} //将整个数组进行异或，数组内相同的元素异或为0，这里得到的结果是俩个不同元素异或的结果，不同元素5 6异或结果为3
//	int pos = 0;
//	for (pos = 0; pos< 32; pos++)
//	{
//		if (((p >> pos) & 1) == 1)
//		{
//			break;
//		}
//	}//找到二进制下，最低位为1的位置
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			*p1 ^= arr[i];
//		}//通过最刚才找到的位置把所有元素的那个位，按照0和1分开，分开之后进行异或，异或相同的元素为0，剩下的就是不同的元素
//		else
//		{
//			*p2 ^= arr[i];
//		}
//	}
//	printf("%d %d", *p1, *p2);
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
//	int dog1 = 0;
//	int dog2 = 0;
//	int sz = sizeof(arr)/sizeof(arr[0]);
//	Find(arr,sz,&dog1,&dog2);
//}
//#include<ctype.h>
//enum Status
//{
//	VALID,
//INVALID
//}sta=INVALID;
//int my_atoi(const char* arr)
//{
//	if (*arr== '\0')
//		return 0;
//	while (isspace(*arr))
//	{
//		arr++;
//	}//跳过空白字符
//	int flag = 1;
//	if (*arr== '+')
//	{
//		flag = 1;
//		arr++;
//	}
//	else if (*arr == '-')
//	{
//		flag = -1;
//		arr++;
//	}
//	int ret = 0;
//	while (*arr)
//	{
//		ret = ret * 10 + *arr - '0';
//		arr++;
//	}
//	sta = VALID;
//	return flag * ret;
//}
int main()
{
	/*char arr[20] = "-123456";
	int ret = my_atoi(arr);
	if (sta == INVALID)
	{
		printf("非法返回:%d\n", ret);
	}
	else if (sta == VALID)
	{
		printf("合法转换:%d\n", ret);
	}*/
	/*int count = 0;
	int x = -1;
	while (x)
	{
		count++;
		x = x >> 1;
	}
	printf("%d", count);*/
	/*int a;
	int b;
	a = a < a + 1;*/
		int a = 1, b = 2, m = 0, n = 0, k;
		k = (n = b < a) && (m = a);
		printf("%d,%d\n", k, m);
	
	return 0;
}