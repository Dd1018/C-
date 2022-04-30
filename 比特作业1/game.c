#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
Setboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
Printboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else if (j == col - 1)
				printf(" %c ", board[i][j]);
	  }
		printf("\n___|___|___\n");
	}
}
PlayerMove(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("请玩家输入坐标：\n");
	while (1)
	{
		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= COL && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
				printf("此处以有棋，请重新下棋:\n");
		}
		else
			printf("坐标错误，请重新输入");
	}
}
char IsFull(char board[ROW][COL], int row, int col)
{
	int i, j;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
					return 'C';
			}
		}
   return 'Q';
}
char Computerread(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == '*' && board[i][2] == ' ')          //如果某行前俩个是玩家下的，我们对其进行拦截
		{
			board[i][2] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][1] == board[i][2] && board[i][1] == '*' && board[i][0] == ' ')          //如果某行后俩个是玩家下的，我们对其进行拦截
		{
			board[i][0] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][2] && board[i][2] == '*' && board[i][1] == ' ')          //如果某行第一个和最后一个是玩家下的，我们对其进行拦截
		{
			board[i][1] = '#';
			return '#';
		}
	}                                                                                       //行出现的判断结束，接下来对列进行判断
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == '*' && board[2][i] == ' ')          //如果某行后俩个是玩家下的，我们对其进行拦截
		{
			board[2][i] = '#';
			return '#';
		}
	}                                                                                      //如果某列的前两行是玩家下的，并第三个没有棋子，我们进行拦截
     for (i = 0; i < row; i++)
   {
		 if (board[1][i] == board[2][i] && board[1][i] == '*' && board[0][i] == ' ')          //如果某列后俩个是玩家下的，我们对其进行拦截
		 {
			 board[0][i] = '#';
			 return '#';
		 }
   }
      for (i = 0; i < row; i++)
   {
		  if (board[0][i] == board[2][i] && board[2][i] == '*' && board[1][i] == ' ')          //如果某列第一个和最后一个是玩家下的，我们对其进行拦截
		  {
			  board[1][i] = '#';
			  return '#';
		  }
    }                                                                                                                  //列判断结束，接下来对主对角线进行判断
		  if (board[0][0] == board[1][1] && board[1][1] == '*' && board[2][2] == ' ')          
		  {
			  board[2][2] = '#'; 
			  return '#';       
		  }                                                                                        // 主对角线前俩个元素判断完毕
		  if (board[0][0] == board[2][2] && board[2][2] == '*' && board[1][1] == ' ')
		  {
			  board[1][1] = '#';
			  return '#';               
		  }                                                                                   //主对角线第一个和最后一个元素判断完毕
		  if (board[2][2] == board[1][1] && board[1][1] == '*' && board[0][0] == ' ')
		  {
			  board[0][0] = '#';
			  return '#';
		  }                                                                                       //主对角线后俩个元素判断完毕
		  if (board[2][0] == board[1][1] && board[1][1] == '*' && board[0][2] == ' ')
		  {
			  board[0][2] = '#';
			  return '#';
		  }                                                                                     //次对角线，从左到右前俩个元素进行判断
		  if (board[0][2] == board[1][1] && board[1][1] == '*' && board[2][0] == ' ')
		  {
			  board[2][0] = '#';
			  return '#';
		  }                                                                                     //次对角线，从左到右，后俩个元素进行判断
		  if (board[0][2] == board[2][0] && board[0][2] == '*' && board[1][1] == ' ')
		  {
			  board[1][1] = '#';
			  return '#';
		  }
	  return '*';
}
char Computer_want_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == '#' && board[i][2] == ' ')
		{
			board[i][2] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][1] == board[i][2] && board[i][1] == '#' && board[i][0] == ' ')          //如果某行后俩个是玩家下的，我们对其进行拦截
		{
			board[i][0] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][2] && board[i][2] == '#' && board[i][1] == ' ')          //如果某行第一个和最后一个是玩家下的，我们对其进行拦截
		{
			board[i][1] = '#';
			return '#';
		}
	}                                                                                       //行出现的判断结束，接下来对列进行判断
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == '#' && board[2][i] == ' ')          //如果某行后俩个是玩家下的，我们对其进行拦截
		{
			board[2][i] = '#';
			return '#';
		}
	}                                                                                      //如果某列的前两行是玩家下的，并第三个没有棋子，我们进行拦截
	for (i = 0; i < row; i++)
	{
		if (board[1][i] == board[2][i] && board[1][i] == '#' && board[0][i] == ' ')          //如果某列后俩个是玩家下的，我们对其进行拦截
		{
			board[0][i] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[2][i] && board[2][i] == '#' && board[1][i] == ' ')          //如果某列第一个和最后一个是玩家下的，我们对其进行拦截
		{
			board[1][i] = '#';
			return '#';
		}
	}                                                                                                                  //列判断结束，接下来对主对角线进行判断
	if (board[0][0] == board[1][1] && board[1][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		return '#';
	}                                                                                        // 主对角线前俩个元素判断完毕
	if (board[0][0] == board[2][2] && board[2][2] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return '#';
	}                                                                                   //主对角线第一个和最后一个元素判断完毕
	if (board[2][2] == board[1][1] && board[1][1] == '#' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		return '#';
	}                                                                                       //主对角线后俩个元素判断完毕
	if (board[2][0] == board[1][1] && board[1][1] == '#' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		return '#';
	}                                                                                     //次对角线，从左到右前俩个元素进行判断
	if (board[0][2]==board[1][1] && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		return '#';
	}                                                                                     //次对角线，从左到右，后俩个元素进行判断
	if (board[0][2] == board[2][0] && board[0][2] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return '#';
	}
	return '*';
}
ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
			while (1)
			{
				int x = rand() % 3;
				int y = rand() % 3;
				if (board[x][y] == ' ')
				{
					board[x][y] = '#';
					break;
				}
			}
}
ComputerMove2(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
	char ch=Computer_want_win(board, row, col);
	if (ch != '#')
	{
			while (1)
			{
				int x = rand() % 3;
				int y = rand() % 3;
				if (board[x][y] == ' ')
				{
					board[x][y] = '#';
					break;
				}
			}
		}
}
ComputerMove3(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：\n");
	char ch=Computer_want_win(board, row, col);   //下棋前准备，即对当前局势分析一下,并做出相应的对策
	if (ch != '#')                         
	{
		char t = Computerread(board, row, col);
		if (t != '#')
		{
			while (1)
			{
				int x = rand() % 3;
				int y = rand() % 3;
				if (board[x][y] == ' ')
				{
					board[x][y] = '#';
					break;
				}
			}
		}
	}
}
char Iswin(char board[ROW][COL], int row, int col)

{
	int i, j;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][2] == board[i][1] && board[i][1] != ' ')
			return board[i][0];
	}
	for (j = 0; j < row; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[2][j] != ' ')
			return board[2][j];
	}
	for (i = 0; i < row; i++)
	{
		if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[0][0] != ' ')
			return board[1][1];
	}
	for (i = 0; i < row; i++)
	{
			if (board[1][1] == board[0][2] && board[0][2] == board[2][0] && board[2][0] != ' ')
				return board[2][0];
	}
	char ret = IsFull(board, row, col);
	if (ret == 'C')
	{
		return 'C';
	}
	else
	{
		return 'Q';
	}
}