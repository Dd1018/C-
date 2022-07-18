#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include<stddef.h>
//struct S
//{
//	char a;
//	int b;
//	int c;
//};
//#define OFFSETOF(type,name) (int)&(((type*)0)->name)
//
//int main()
//{
//	printf("%d ", OFFSETOF(struct S, a));
//	printf("%d ", OFFSETOF(struct S, b));
//	printf("%d ", OFFSETOF(struct S, c));
//	return 0;
//}
#define SWAP(i) ((0xaaaaaaaa&i)>>1)|((0x55555555&i)<<1)
int main()
{
	int a = 0;
	scanf("%d", &a);
	printf("%d",SWAP(a));
	return 0;

}
