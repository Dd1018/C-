#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include"game.h"
void menu()
{
	printf("******************\n");
	printf("*****1.play*******\n");
	printf("*****0.exit*******\n");
	printf("******************\n");
}
void game()
{
	int x = 0;
	srand((unsigned)time(NULL));
	char board[ROW][COL] = { 0 };
	menu();
	
	Itnboard(board, ROW, COL);
	Printboard(board, ROW, COL);
	char ch;
	while(1)
	{
		PlayerMove(board, ROW, COL);
		Printboard(board, ROW, COL);
		 ch=Iswin(board, ROW, COL);
		if (ch != 'C')
			break;
		ComputerMove(board, ROW, COL);
		Printboard(board, ROW, COL);
		ch = Iswin(board, ROW, COL);
		if (ch != 'C')
			break;
	}
	if (ch == '*')
		printf("���Ӯ");
	if (ch == 'Q')
		printf("ƽ��");
	if (ch == '#')
		printf("����Ӯ");



}
int main()
{
	
	menu();
	printf("���û�����ѡ��");
	int x;
	do {
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("������Ϸ");
			game();
			break;
		case 0:
			printf("�˳���Ϸ");
			break;
		default:
			printf("����������");
			break;
		}
	} while (x);
	return 0;
}