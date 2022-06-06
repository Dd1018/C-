#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>				// ��������ͷ�ļ�
#pragma comment(lib,"Winmm.lib")	// ��������ͷ�ļ���

#define High 20			// ��Ϸ����ߴ�
#define Width 30
#define EnemyNum 5		// �л�����
#define BossNum 2		// Boss������

int flag;				// �ɻ�״̬ 
int color(int c);		// ����������ɫ
void explation();		// ��Ϸ��ʾ
void show();			// ��ʾ��Ϸ����
void endgame();			// ��Ϸ����
void startup();			// ���ݳ�ʼ��
void FileRead();		// ����

// ȫ�ֱ���
int position_x, position_y;				// �ɻ�λ��
struct enemy {
	int x;
	int y;
	int life;
}Boss[BossNum], enemy[EnemyNum];		// �л�λ��

int canvas[High][Width] = { 0 };			// ��ά����洢��Ϸ�����ж�Ӧ��Ԫ��
										// 0Ϊ�ո�1Ϊ�ɻ�8��2Ϊ�ӵ�o��3Ϊ�л�0 , 4ΪBoss�л�A
int score;								// �÷�
int number;								// ���ٵл���
int BulletWidth;						// �ӵ����
int EnemyMoveSpeed;						// �л��ƶ��ٶ�

// ����ƶ���(x,y)λ��
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

// ����������ɫ
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

// ���ع��
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// ��ʼ����
void welcometogame()
{
	int n, i, j = 1;
	system("cls");
	color(15);
	gotoxy(33, 1);
	printf("�ɻ���ս Plane War");
	color(56);
	for (i = 3; i <= 26; i++)       // ������±߿�
	{
		for (j = 6; j <= 80; j++)   // ������ұ߿�
		{
			gotoxy(j, i);
			if (i == 3 || i == 26)
				printf(" ");
			else if (j == 6 || j == 80)
				printf(" ");
		}
	}
	color(14);
	gotoxy(38, 6);
	printf("��������\n");
	gotoxy(19, 8);
	printf("�ո�:�����ӵ�  W:ǰ��  A:����  D:����  S:����\n");
	gotoxy(34, 11);
	printf("1.��ʼ��Ϸ(play)");
	gotoxy(34, 13);
	printf("2.��Ϸ����(rule)");
	gotoxy(34, 15);
	printf("3.��ȡ�浵(read)");
	gotoxy(34, 17);
	printf("4.�˳���Ϸ(quit)");
	color(15);
	gotoxy(22, 24);
	printf("��Ϸ�����ˣ���ո�");
	color(14);
	gotoxy(33, 20);
	printf("��ѡ�� 1 2 3 4: ");
	color(14);
	scanf("%d", &n);   // ����ѡ��
	switch (n)
	{
	case 1:
		flag = 1;
		system("cls");
		break;
	case 2:
		explation();   // ��Ϸ����
		break;
	case 3:
		system("cls"); // ����
		break;
	case 4:
		gotoxy(30, 28);
		exit(0);       // �˳���Ϸ
		break;
	default:
		color(9);
		gotoxy(33, 22);
		printf("������1-4֮�����");
		_getch();       // ���������
		system("cls");  // ����
		welcometogame();
	}
}

// ��Ϸ����
void explation()
{
	int i, j = 1;
	system("cls");
	color(15);
	gotoxy(30, 1);
	printf("��Ϸ���� Rules of game");
	color(56);
	for (i = 3; i <= 26; i++)       // ������±߿�
	{
		for (j = 6; j <= 80; j++)   // ������ұ߿�
		{
			gotoxy(j, i);
			if (i == 3 || i == 26)
				printf(" ");
			else if (j == 6 || j == 80)
				printf(" ");
		}
	}
	color(14);
	gotoxy(10, 6);
	printf("1. W,A,S,D �ֱ��ǿ��Ʒɻ����ƶ����ո����ӵ�");
	gotoxy(10, 9);
	printf("2. O����ͨ�л�����һ���ӵ�����A��Boss�л����������ӵ���");
	gotoxy(10, 12);
	printf("3. ������ͨ�л��ɻ��1�֣�����Boss�л��ɻ��2��");
	gotoxy(10, 15);
	printf("4. �л������±߽��1��");
	gotoxy(10, 18);
	printf("5. �ɻ������л���׹��");
	gotoxy(10, 21);
	printf("6. ��Z�浵����P��ͣ��Ϸ");
	color(15);
	gotoxy(25, 23);
	printf("/*****�������������ҳ��*****/");
	_getch();  // �����������������
	system("cls");
	welcometogame();
}

// ���ݳ�ʼ��
void startup()
{
	mciSendString("open D:\\plane\\game.mp3 alias bkmusic ", NULL, 0, NULL);	// �򿪱�������
	mciSendString("play bkmusic", NULL, 0, NULL); // ѭ������
	position_x = High / 2;
	position_y = Width / 2;
	canvas[position_x][position_y] = 3;
	canvas[position_x + 1][position_y - 1] = 3;
	canvas[position_x + 1][position_y] = 3;
	canvas[position_x + 1][position_y + 1] = 3;

	int k;
	for (k = 0; k < EnemyNum; k++)
	{
		enemy[k].x = rand() % 2;
		enemy[k].y = rand() % Width;
		canvas[enemy[k].x][enemy[k].y] = 3;
	}
	for (k = 0; k < BossNum; k++)
	{
		Boss[k].x = rand() % 2;
		Boss[k].y = rand() % Width;
		canvas[Boss[k].x][Boss[k].y] = 4;
		Boss[k].life = 2;
	}
	int score = 0;			// �ɼ�
	int number = 0;			// ���ٵл���
	BulletWidth = 0;
	EnemyMoveSpeed = 30;
	HideCursor();			// ���
}

// �浵����
void FileWrite()
{
	FILE* fp;							// �ļ�ָ��
	fp = fopen("D:\\game.data", "w");	// ���ļ� "w": writeд���ļ�
	int i, j;
	for (i = 0; i < EnemyNum; i++)
	{
		fwrite(&enemy[i], sizeof(struct enemy), 1, fp);
	}
	for (j = 0; j < BossNum; j++)
	{
		fwrite(&Boss[j], sizeof(struct enemy), 1, fp);
	}
	fwrite(&position_x, sizeof(int), 1, fp);
	fwrite(&position_y, sizeof(int), 1, fp);
	fwrite(&score, sizeof(int), 1, fp);
	fwrite(&number, sizeof(int), 1, fp);
	fwrite(&BulletWidth, sizeof(int), 1, fp);
	fwrite(&EnemyMoveSpeed, sizeof(int), 1, fp);
	fclose(fp);  // �ر��ļ�
	printf("\n����ɹ�\n");
}

// ��������
void FileRead()
{
	FILE* fp;							// �ļ�ָ��
	fp = fopen("D:\\game.data", "r");	// ���ļ� "r": read��ȡ�ļ�
	mciSendString("open D:\\plane\\game.mp3 alias bkmusic ", NULL, 0, NULL);	// �򿪱�������
	mciSendString("play bkmusic", NULL, 0, NULL); // ѭ������
	if (fp == NULL)
		startup();
	else
	{
		int i, j;
		for (i = 0; i < EnemyNum; i++)
		{
			fread(&enemy[i], sizeof(struct enemy), 1, fp);
		}
		for (j = 0; j < BossNum; j++)
		{
			fread(&Boss[j], sizeof(struct enemy), 1, fp);
		}
		fread(&position_x, sizeof(int), 1, fp);
		fread(&position_y, sizeof(int), 1, fp);
		fread(&score, sizeof(int), 1, fp);
		fread(&number, sizeof(int), 1, fp);
		fread(&BulletWidth, sizeof(int), 1, fp);
		fread(&EnemyMoveSpeed, sizeof(int), 1, fp);
	}
	fclose(fp);  // �ر��ļ�
	canvas[position_x][position_y] = 1;
	canvas[position_x + 1][position_y - 1] = 1;
	canvas[position_x + 1][position_y] = 1;
	canvas[position_x + 1][position_y + 1] = 1;

	int k;
	for (k = 0; k < EnemyNum; k++)
	{
		canvas[enemy[k].x][enemy[k].y] = 3;
	}
	for (k = 0; k < BossNum; k++)
	{
		canvas[Boss[k].x][Boss[k].y] = 4;
		Boss[k].life = 2;
	}

	HideCursor();
}

// ��ʾ����
void show()
{
	color(112);
	gotoxy(0, 0); // ����ƶ���ԭ��λ�ã������ػ�����
	int i, j;
	for (i = 0; i < High; i++)
	{
		for (j = 0; j < Width; j++)
		{
			if ((j == Width - 1) || (i == High - 1) || (j == 0) || (i == 0))
				printf("#");             // ��ӡ�߽�#
			else if (canvas[i][j] == 1)
				printf("8");             // ����ɻ�8
			else if (canvas[i][j] == 2)
				printf("o");             // ����ӵ�o
			else if (canvas[i][j] == 3)
				printf("O");             // ����л�O
			else if (canvas[i][j] == 4)
				printf("A");             // ���Boss�л�A
			else
				printf(" ");
		}
		printf("\n");
	}
	color(14);
	printf("\n");
	printf("��Ϸ�÷�: %d\n", score);
	printf("���ٵл�: %d\n\n", number);
	Sleep(20);
}

// ���û������޹صĸ���
void updateWithoutInput()
{
	int i, j, k;
	for (i = 0; i < High; i++)
	{
		for (j = 0; j < Width; j++)
		{
			if (canvas[i][j] == 2)
			{
				for (k = 0; k < EnemyNum; k++)
				{
					if ((i == enemy[k].x) && (j == enemy[k].y))			// �ӵ����ел�
					{
						mciSendString("close gemusic", NULL, 0, NULL);		// �Ȱ�ǰ��һ�ε����ֹر�
						mciSendString("open D:\\plane\\gotEnemy.mp3 alias gemusic ", NULL, 0, NULL);	// ������
						mciSendString("play gemusic", NULL, 0, NULL);		// ������һ��
						score++;										// ������1
						number++;										// ���ٵл�����1
						if (number % 6 == 0 && EnemyMoveSpeed > 3)		// �ﵽһ�����ֺ󣬵л����
							EnemyMoveSpeed--;
						if (number % 12 == 0)                           // �ﵽһ�����ֺ��ӵ�������
							BulletWidth++;
						canvas[enemy[k].x][enemy[k].y] = 0;				// ��Ӱ����
						enemy[k].x = rand() % 2;						// �����µĵл�
						enemy[k].y = rand() % Width;
						canvas[enemy[k].x][enemy[k].y] = 3;
						canvas[i][j] = 0;								// �ӵ���ʧ
					}
				}
				for (k = 0; k < BossNum; k++)
				{
					if ((i == Boss[k].x) && (j == Boss[k].y))	// �ӵ�����Boss�л�
					{
						mciSendString("close gemusic", NULL, 0, NULL);		// �Ȱ�ǰ��һ�ε����ֹر�
						mciSendString("open D:\\plane\\gotEnemy.mp3 alias gemusic ", NULL, 0, NULL);	// ������
						mciSendString("play gemusic", NULL, 0, NULL);		// ������һ��	
						Boss[k].life--;								// Boss�л�����ֵ��1
						if (Boss[k].life == 0)
						{
							canvas[Boss[k].x][Boss[k].y] = 0;	// ��Ӱ����
							Boss[k].x = rand() % 2;					// ������Boss�л�
							Boss[k].y = rand() % Width;
							canvas[Boss[k].x][Boss[k].y] = 4;
							canvas[i][j] = 0;							// �ӵ���ʧ
							Boss[k].life = 2;
							score++; score++;							// ������2
							number++;									// ���ٵл�����1
						}
					}
				}
				// �ӵ������ƶ�
				canvas[i][j] = 0;
				if (i > 0)
					canvas[i - 1][j] = 2;
			}
		}
	}
	static int speed = 0;
	if (speed < EnemyMoveSpeed)
		speed++;
	for (k = 0; k < EnemyNum; k++)
	{
		// �л�ײ���һ�
		if ((position_x == enemy[k].x) && (position_y == enemy[k].y) || (position_x + 1 == enemy[k].x) && (position_y - 1 == enemy[k].y) || (position_x + 1 == enemy[k].x) && (position_y + 1 == enemy[k].y) || (position_x + 2 == enemy[k].x) && (position_y + 1 == enemy[k].y) || (position_x + 2 == enemy[k].x) && (position_y - 1 == enemy[k].y))
		{
			mciSendString("close bkmusic", NULL, 0, NULL);		// �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open D:\\plane\\explode.mp3 alias exmusic", NULL, 0, NULL);		// ������
			mciSendString("play exmusic", NULL, 0, NULL);		// ������һ��
			color(11);
			printf("\n��Ϸ����!\n");
			Sleep(3000);
			system("pause");
			exit(0);
		}

		// �л��ܳ���ʾ��Ļ
		if (enemy[k].x > High)
		{
			canvas[enemy[k].x][enemy[k].y] = 0;
			enemy[k].x = rand() % 2; // �����µĵл�
			enemy[k].y = rand() % Width;
			canvas[enemy[k].x][enemy[k].y] = 3;
			score--; // ����
		}

		if (speed == EnemyMoveSpeed)
		{
			// �л�����
			for (k = 0; k < EnemyNum; k++)
			{
				canvas[enemy[k].x][enemy[k].y] = 0;
				enemy[k].x++;
				speed = 0;
				canvas[enemy[k].x][enemy[k].y] = 3;
			}

			// Boss�л�����
			for (k = 0; k < BossNum; k++)
			{
				canvas[Boss[k].x][Boss[k].y] = 0;
				Boss[k].x++;
				speed = 0;
				canvas[Boss[k].x][Boss[k].y] = 4;
			}
		}
	}

	for (k = 0; k < BossNum; k++)
	{
		// Boss�л�ײ���һ�
		if ((position_x == Boss[k].x) && (position_y == Boss[k].y) || (position_x + 1 == Boss[k].x) && (position_y - 1 == Boss[k].y) || (position_x + 1 == Boss[k].x) && (position_y + 1 == Boss[k].y) || (position_x + 2 == Boss[k].x) && (position_y + 1 == Boss[k].y) || (position_x + 2 == Boss[k].x) && (position_y - 1 == Boss[k].y))
		{
			mciSendString("close exmusic", NULL, 0, NULL);		// �Ȱ�ǰ��һ�ε����ֹر�
			mciSendString("open D:\\plane\\explode.mp3 alias exmusic", NULL, 0, NULL);		// ������
			mciSendString("play exmusic", NULL, 0, NULL);		// ������һ��
			color(11);
			printf("\n��Ϸ����!\n");
			Sleep(3000);
			system("pause");
			exit(0);
		}

		// Boss�л��ܳ���ʾ��Ļ
		if (Boss[k].x > High)
		{
			canvas[Boss[k].x][Boss[k].y] = 0;
			Boss[k].x = rand() % 2; // �����µ�Boss�л�
			Boss[k].y = rand() % Width;
			canvas[Boss[k].x][Boss[k].y] = 4;
			score--; // ����
		}
	}
}

// ���û������йصĸ���
void updateWithInput()
{
	char input;
	if (_kbhit()) // �ж��Ƿ�������
	{
		input = _getch(); // �����û��Ĳ�ͬ�������ƶ�����������س�
		if (input == 'a' && position_y > 1 || input == 'A')
		{
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_y--; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		}
		else if (input == 'd' && position_y < Width - 2 || input == 'D')
		{
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_y++; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		}
		else if (input == 'w' && position_x > 1 || input == 'W')
		{
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_x--; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		}
		else if (input == 's' && position_x < High - 3 || input == 'S')
		{
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_x++; // λ������
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		}
		else if (input == ' ') // �����ӵ�
		{
			int left = position_y - BulletWidth;
			int right = position_y + BulletWidth;
			if (left < 0)
				left = 0;
			if (right > Width - 1)
				right = Width - 1;
			int k;
			for (k = left; k <= right; k++)		// ��������
				canvas[position_x - 1][k] = 2;	// �����ӵ��ĳ�ʼλ���ڷɻ������Ϸ�
		}
		else if (input == 'P' || input == 'p')	// ��P��ͣ��Ϸ
			system("pause");
		else if (input == 'Z' || input == 'z')	// ��Z�浵
		{
			FileWrite();
			system("pause");
			exit(0);
		}
	}
}


int main()
{
	welcometogame();
	if (flag == 1)
		startup();				// ���ݳ�ʼ��
	else
		FileRead();				// ���ݳ�ʼ��

	while (1)					// ��Ϸѭ��ִ��
	{
		show();					// ��ʾ����
		updateWithoutInput();	// ���û������޹صĸ���
		updateWithInput();		// ���û������йصĸ���
	}
	return 0;
}