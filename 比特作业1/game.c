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
	printf("������������꣺\n");
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
				printf("�˴������壬����������:\n");
		}
		else
			printf("�����������������");
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
		if (board[i][0] == board[i][1] && board[i][1] == '*' && board[i][2] == ' ')          //���ĳ��ǰ����������µģ����Ƕ����������
		{
			board[i][2] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][1] == board[i][2] && board[i][1] == '*' && board[i][0] == ' ')          //���ĳ�к�����������µģ����Ƕ����������
		{
			board[i][0] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][2] && board[i][2] == '*' && board[i][1] == ' ')          //���ĳ�е�һ�������һ��������µģ����Ƕ����������
		{
			board[i][1] = '#';
			return '#';
		}
	}                                                                                       //�г��ֵ��жϽ��������������н����ж�
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == '*' && board[2][i] == ' ')          //���ĳ�к�����������µģ����Ƕ����������
		{
			board[2][i] = '#';
			return '#';
		}
	}                                                                                      //���ĳ�е�ǰ����������µģ���������û�����ӣ����ǽ�������
     for (i = 0; i < row; i++)
   {
		 if (board[1][i] == board[2][i] && board[1][i] == '*' && board[0][i] == ' ')          //���ĳ�к�����������µģ����Ƕ����������
		 {
			 board[0][i] = '#';
			 return '#';
		 }
   }
      for (i = 0; i < row; i++)
   {
		  if (board[0][i] == board[2][i] && board[2][i] == '*' && board[1][i] == ' ')          //���ĳ�е�һ�������һ��������µģ����Ƕ����������
		  {
			  board[1][i] = '#';
			  return '#';
		  }
    }                                                                                                                  //���жϽ����������������Խ��߽����ж�
		  if (board[0][0] == board[1][1] && board[1][1] == '*' && board[2][2] == ' ')          
		  {
			  board[2][2] = '#'; 
			  return '#';       
		  }                                                                                        // ���Խ���ǰ����Ԫ���ж����
		  if (board[0][0] == board[2][2] && board[2][2] == '*' && board[1][1] == ' ')
		  {
			  board[1][1] = '#';
			  return '#';               
		  }                                                                                   //���Խ��ߵ�һ�������һ��Ԫ���ж����
		  if (board[2][2] == board[1][1] && board[1][1] == '*' && board[0][0] == ' ')
		  {
			  board[0][0] = '#';
			  return '#';
		  }                                                                                       //���Խ��ߺ�����Ԫ���ж����
		  if (board[2][0] == board[1][1] && board[1][1] == '*' && board[0][2] == ' ')
		  {
			  board[0][2] = '#';
			  return '#';
		  }                                                                                     //�ζԽ��ߣ�������ǰ����Ԫ�ؽ����ж�
		  if (board[0][2] == board[1][1] && board[1][1] == '*' && board[2][0] == ' ')
		  {
			  board[2][0] = '#';
			  return '#';
		  }                                                                                     //�ζԽ��ߣ������ң�������Ԫ�ؽ����ж�
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
		if (board[i][1] == board[i][2] && board[i][1] == '#' && board[i][0] == ' ')          //���ĳ�к�����������µģ����Ƕ����������
		{
			board[i][0] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][2] && board[i][2] == '#' && board[i][1] == ' ')          //���ĳ�е�һ�������һ��������µģ����Ƕ����������
		{
			board[i][1] = '#';
			return '#';
		}
	}                                                                                       //�г��ֵ��жϽ��������������н����ж�
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == '#' && board[2][i] == ' ')          //���ĳ�к�����������µģ����Ƕ����������
		{
			board[2][i] = '#';
			return '#';
		}
	}                                                                                      //���ĳ�е�ǰ����������µģ���������û�����ӣ����ǽ�������
	for (i = 0; i < row; i++)
	{
		if (board[1][i] == board[2][i] && board[1][i] == '#' && board[0][i] == ' ')          //���ĳ�к�����������µģ����Ƕ����������
		{
			board[0][i] = '#';
			return '#';
		}
	}
	for (i = 0; i < row; i++)
	{
		if (board[0][i] == board[2][i] && board[2][i] == '#' && board[1][i] == ' ')          //���ĳ�е�һ�������һ��������µģ����Ƕ����������
		{
			board[1][i] = '#';
			return '#';
		}
	}                                                                                                                  //���жϽ����������������Խ��߽����ж�
	if (board[0][0] == board[1][1] && board[1][1] == '#' && board[2][2] == ' ')
	{
		board[2][2] = '#';
		return '#';
	}                                                                                        // ���Խ���ǰ����Ԫ���ж����
	if (board[0][0] == board[2][2] && board[2][2] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return '#';
	}                                                                                   //���Խ��ߵ�һ�������һ��Ԫ���ж����
	if (board[2][2] == board[1][1] && board[1][1] == '#' && board[0][0] == ' ')
	{
		board[0][0] = '#';
		return '#';
	}                                                                                       //���Խ��ߺ�����Ԫ���ж����
	if (board[2][0] == board[1][1] && board[1][1] == '#' && board[0][2] == ' ')
	{
		board[0][2] = '#';
		return '#';
	}                                                                                     //�ζԽ��ߣ�������ǰ����Ԫ�ؽ����ж�
	if (board[0][2]==board[1][1] && board[1][1] == '#' && board[2][0] == ' ')
	{
		board[2][0] = '#';
		return '#';
	}                                                                                     //�ζԽ��ߣ������ң�������Ԫ�ؽ����ж�
	if (board[0][2] == board[2][0] && board[0][2] == '#' && board[1][1] == ' ')
	{
		board[1][1] = '#';
		return '#';
	}
	return '*';
}
ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("�������壺\n");
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
	printf("�������壺\n");
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
	printf("�������壺\n");
	char ch=Computer_want_win(board, row, col);   //����ǰ׼�������Ե�ǰ���Ʒ���һ��,��������Ӧ�ĶԲ�
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