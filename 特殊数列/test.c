#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 0;
	int a[20] = { 1,1,2,3 }; //对数组的前四项赋值
	for (int i = 4; i < 20; i++) //该数列的前20项进行赋值
		a[i] = a[i - 1] + a[i - 2];//从第三项开始，后项都等于它的前三项之和
	for (int j = 0; j < 20; j++) {//输出该数组
		printf("%d\t", a[j]);
		n++;
		if (n % 5 == 0)//判断换行，每五个一行
			printf("\n");
	}
	return 0;
}