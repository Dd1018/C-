#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("**********************************\n");
	printf("***********1.play*****************\n");
	printf("***********0.exit*****************\n");
	printf("**********************************\n");
}
void game()
{
	char board[ROWS][COLS] = { 0 };
	char mine[ROWS][COLS] = { 0 };
	Itnboard(board, ROWS, COLS, '0');
	Itnboard(mine, ROWS, COLS, '*'); //初始化棋盘
	Displayboard(mine, ROW, COL);//打印棋盘
	ComputerSet(board,ROW,COL);
	Playmove(board,mine, ROW, COL);
}
int main()
{
	srand((unsigned int)time(NULL));
	int input;
	while (1)
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("扫雷游戏:\n");
			game();
			break;
		case 0:
			printf("退出菜单");
			break;
		default:
			printf("输入错误请重新输入:");
		}
	}
}