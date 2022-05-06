#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void Itnboard(char board[ROWS][COLS], int rows, int cols,char c)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j <cols; j++)
		{
			board[i][j] = c;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void Setboard(char board[ROWS][COLS], int row, int col)
{
	int count = Easy_count;
	while (count)
	{
		int x = rand() % row+1;
		int y = rand() % col+1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int sum(char board[ROWS][COLS], int x, int y)
{

	return (board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0');
}
void Player(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	int count = 0;
	while (1)
	{
		printf("请排雷：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (board[x][y] == '0')
			{
				Openboard(show, board, x, y);
				Displayboard(show, ROW, COL);
			}
			else if (board[x][y] == '1')
			{
				printf("你死了\n");
				break;
			}
		}
		else
		{
			printf("请重新输入");
		}
		int i, j;
		for (i = 1; i <= row; i++)
		{
			for (j = 1; j <= col; j++)
			{
				if (show[i][j] == '*')
				{
					count++;
				}
			}
		}
		if (count == Easy_count)
		{
			printf("成功\n");
			break;
		}
	}
}
void Openboard(char show[ROWS][COLS], char board[ROWS][COLS], int row, int col)
{

	if (row >= 1 && row <= ROW && col >= 1 && col <= COL)
	{
		int count=sum(board, row, col);
		if (count != 0)
		{
			show[row][col] = count + '0';
		}
		else if (show[row][col] != '_')
		{
			show[row][col] = '_';
			int i = 0, j = 0;
			for (i = row - 1; i <= row + 1; i++)
			{
				for (j = col - 1; j <= col + 1; j++)
				{
					
					Openboard(show, board, i,j);
				}
			}
		}
		else
		{
			return;
		}
	}
}
