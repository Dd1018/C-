#define _CRT_SECURE_NO_WARNINGS
#include "game.h"
void menu()
{
	printf("*******************************\n");
	printf("***********1.play**************\n");
	printf("***********0.exit**************\n");
	printf("*******************************\n");
}
void menu1()
{
	printf("��ѡ��ģʽ\n");
	printf("****************************************\n");
	printf("***********1.����԰ˮƽ*****************\n");
	printf("***********2.����԰��ҵˮƽ*************\n");
	printf("***********3.������ˮƽ*****************\n");
	printf("****************************************\n");
}
void game()
{
	menu1();
	int a;
	scanf("%d", &a);
	char ch;
		char board[ROW][COL] = { 0 };
		Setboard(board, ROW, COL);
		Printboard(board, ROW, COL);
		if (a == 2)
		{
			while (1)
			{
				PlayerMove(board, ROW, COL);
				Printboard(board, ROW, COL);
				ch = Iswin(board, ROW, COL);
				if (ch != 'C')
					break;
				ComputerMove2(board, ROW, COL);
				Printboard(board, ROW, COL);
				ch = Iswin(board, ROW, COL);
				if (ch != 'C')
					break;
			}
			if (ch == '*')
				printf("���Ӯ\n");
			if (ch == '#')
				printf("����Ӯ\n");
			if (ch == 'Q')
				printf("ƽ��");
		}
		if (a == 3)
		{
			while (1)
			{
				PlayerMove(board, ROW, COL);
				Printboard(board, ROW, COL);
				ch = Iswin(board, ROW, COL);
				if (ch != 'C')
					break;
				ComputerMove3(board, ROW, COL);
				Printboard(board, ROW, COL);
				ch = Iswin(board, ROW, COL);
				if (ch != 'C')
					break;
			}
			if (ch == '*')
				printf("���Ӯ\n");
			if (ch == '#')
				printf("����Ӯ\n");
			if (ch == 'Q')
				printf("ƽ��");
		}
		if (a == 1)
		{
			while (1)
			{
				PlayerMove(board, ROW, COL);
				Printboard(board, ROW, COL);
				ch = Iswin(board, ROW, COL);
				if (ch != 'C')
					break;
				ComputerMove(board, ROW, COL);
				Printboard(board, ROW, COL);
				ch = Iswin(board, ROW, COL);
				if (ch != 'C')
					break;
			}
			if (ch == '*')
				printf("���Ӯ\n");
			if (ch == '#')
				printf("����Ӯ\n");
			if (ch == 'Q')
				printf("ƽ��");
		}
}
int main()
{
	int input;
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default :
			printf("�����������������\n");
		}

	} while (input);
	return 0;
}