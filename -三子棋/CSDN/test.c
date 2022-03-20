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
		printf("玩家赢");
	if (ch == 'Q')
		printf("平局");
	if (ch == '#')
		printf("电脑赢");



}
int main()
{
	
	menu();
	printf("请用户进行选择：");
	int x;
	do {
		scanf("%d", &x);
		switch (x)
		{
		case 1:
			printf("进入游戏");
			game();
			break;
		case 0:
			printf("退出游戏");
			break;
		default:
			printf("请重新输入");
			break;
		}
	} while (x);
	return 0;
}