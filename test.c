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
//	} //������������������������ͬ��Ԫ�����Ϊ0������õ��Ľ����������ͬԪ�����Ľ������ͬԪ��5 6�����Ϊ3
//	int pos = 0;
//	for (pos = 0; pos< 32; pos++)
//	{
//		if (((p >> pos) & 1) == 1)
//		{
//			break;
//		}
//	}//�ҵ��������£����λΪ1��λ��
//	for (i = 0; i < sz; i++)
//	{
//		if (((arr[i] >> pos) & 1) == 1)
//		{
//			*p1 ^= arr[i];
//		}//ͨ����ղ��ҵ���λ�ð�����Ԫ�ص��Ǹ�λ������0��1�ֿ����ֿ�֮�������������ͬ��Ԫ��Ϊ0��ʣ�µľ��ǲ�ͬ��Ԫ��
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
//	}//�����հ��ַ�
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
		printf("�Ƿ�����:%d\n", ret);
	}
	else if (sta == VALID)
	{
		printf("�Ϸ�ת��:%d\n", ret);
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