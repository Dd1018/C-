#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int find(int a[3][3], int x,int col,int row)
{
	int i = 0, j = col;
	while (j>=0&&i<=row)
	{
		if (x == a[i][j])
			return 1;
		else if (x > a[i][j])
			i++;
		else if (x < a[i][j])
			j--;
	}
	return 0;
}
int main()
{
	int a[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int row = 2, col = 2;
	int x = 0;
	scanf("%d", &x);
	if (find(a, x,col,row))
		printf("找到了");
	else
		printf("没找到");
	return 0;
}
