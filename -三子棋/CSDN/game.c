#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void Itnboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void Printboard(char board[ROW][COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
			
		}
		printf("\n");
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
			{
				printf("---|");
			}
			else
				printf("---");
		}
		printf("\n");
	}
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家请下棋：");
	
	while (1)
	{
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("该位置已有棋，请重下：\n");
		}
		else
			printf("坐标错误，请重新输入：\n");
	}

}
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x;
	int y;

	printf("电脑下棋\n");
	while (1)
	{
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int	IsFull(char board[ROW][COL], int row, int col)
{
	int i; int  j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < row; j++)
		{
			if (board[i][j] == ' ')
				return 1;
		}
	}
	return 0;


}
char Iswin(char board[ROW][COL], int row, int col)
{
	int i; int k;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][2] != ' ')
			return board[i][2];

	}
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
			return board[2][1];

	}
	for (i = 0; i < row; i++)
	{
		if (board[0][0] == board[2][2] && board[2][2] == board[1][1] && board[1][1] != ' ')
			return board[1][1];
	}
	for (i = 0; i < row; i++)
	{
		if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][2] != ' ')
			return board[0][2];
	}
	k = IsFull(board, ROW, COL);
	if (k == 1)
		return 'C';
	if(k==0)
		return 'Q';

}
