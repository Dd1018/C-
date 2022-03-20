#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
Itnboard(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i;
	int j;
	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++)
			board[i][j] = set;
}
int fun(char board[ROWS][COLS], int x, int y)
{
	return board[x - 1][y - 1] +
		board[x - 1][y] +
		board[x - 1][y + 1] +
		board[x][y - 1] +
		board[x][y + 1] +
		board[x + 1][y - 1] +
		board[x + 1][y] +
		board[x + 1][y + 1] - 8 * '0';

}

Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i;
	int j;
	printf("---------------- É¨À×ÓÎÏ·----------------------\n");
	for (i = 0; i <=row; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <=row ; i++)
	{
		printf("%d ", i);
		for (j = 1; j <=col ; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("---------------- É¨À×ÓÎÏ·----------------------\n");
}
Playmove(char board[ROWS][COLS],char mine[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int count=0;

	
	
	while (count< row*col- COT)
	{
		printf("ÇëÊäÈë×ø±ê:");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (board[x][y] == '1')
			{
				printf("Äã±»Õ¨ËÀÁË£º");
				break;
			}
			else
			{    

				int ch = fun(board, x, y);
				mine[x][y] = ch + '0';
				Displayboard(mine,row,col);
				count++;

			}
		}
		else
		{
			printf("ÊäÈë´íÎó£¬ÇëÖØÐÂÊäÈë");
		}
	}
	if (count == row * col - COT)
		printf("¹§Ï²Äã£¬ÅÅÀ×³É¹¦");


}
ComputerSet(char board[ROWS][COLS], int row, int col)
{
	int x;
	int y;
	int count = COT;
	while(count)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
	Displayboard(board, row, col);
}