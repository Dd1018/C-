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
	Itnboard(mine, ROWS, COLS, '*'); //��ʼ������
	Displayboard(mine, ROW, COL);//��ӡ����
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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("ɨ����Ϸ:\n");
			game();
			break;
		case 0:
			printf("�˳��˵�");
			break;
		default:
			printf("�����������������:");
		}
	}
}