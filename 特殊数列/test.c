#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int n = 0;
	int a[20] = { 1,1,2,3 }; //�������ǰ���ֵ
	for (int i = 4; i < 20; i++) //�����е�ǰ20����и�ֵ
		a[i] = a[i - 1] + a[i - 2];//�ӵ����ʼ�������������ǰ����֮��
	for (int j = 0; j < 20; j++) {//���������
		printf("%d\t", a[j]);
		n++;
		if (n % 5 == 0)//�жϻ��У�ÿ���һ��
			printf("\n");
	}
	return 0;
}