#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("********  1.play  **********\n");
	printf("********  0.exit  **********\n");
	printf("****************************\n");
}
void game()
{
	char board[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	Itnboard(board, ROWS, COLS,'0');  //��ʼ������
	Itnboard(show, ROWS, COLS, '*');
	Setboard(board, ROW, COL);   
	Displayboard(board, ROW, COL);
	Player(board, show, ROW, COL);            //�������
}
int main()
{

	int input=1;
  srand((unsigned int)time(NULL));
	do{
		menu();
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		game();
		break;
	case 0:
		break;
	default:
		printf("����������������룺\n ");
	}
	} while (input);
}