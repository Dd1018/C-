#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<mmsystem.h>				// 导入声音头文件
#pragma comment(lib,"Winmm.lib")	// 导入声音头文件库

#define High 20			// 游戏画面尺寸
#define Width 30
#define EnemyNum 5		// 敌机个数
#define BossNum 2		// Boss机个数

int flag;				// 飞机状态 
int color(int c);		// 更改文字颜色
void explation();		// 游戏提示
void show();			// 显示游戏界面
void endgame();			// 游戏结束
void startup();			// 数据初始化
void FileRead();		// 读档

// 全局变量
int position_x, position_y;				// 飞机位置
struct enemy {
	int x;
	int y;
	int life;
}Boss[BossNum], enemy[EnemyNum];		// 敌机位置

int canvas[High][Width] = { 0 };			// 二维数组存储游戏画布中对应的元素
										// 0为空格，1为飞机8，2为子弹o，3为敌机0 , 4为Boss敌机A
int score;								// 得分
int number;								// 销毁敌机数
int BulletWidth;						// 子弹宽度
int EnemyMoveSpeed;						// 敌机移动速度

// 光标移动到(x,y)位置
void gotoxy(int x, int y)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

// 更改文字颜色
int color(int c)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0;
}

// 隐藏光标
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor_info = { 1,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

// 开始界面
void welcometogame()
{
	int n, i, j = 1;
	system("cls");
	color(15);
	gotoxy(33, 1);
	printf("飞机大战 Plane War");
	color(56);
	for (i = 3; i <= 26; i++)       // 输出上下边框
	{
		for (j = 6; j <= 80; j++)   // 输出左右边框
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
	printf("基本操作\n");
	gotoxy(19, 8);
	printf("空格:发射子弹  W:前进  A:左移  D:右移  S:后退\n");
	gotoxy(34, 11);
	printf("1.开始游戏(play)");
	gotoxy(34, 13);
	printf("2.游戏规则(rule)");
	gotoxy(34, 15);
	printf("3.读取存档(read)");
	gotoxy(34, 17);
	printf("4.退出游戏(quit)");
	color(15);
	gotoxy(22, 24);
	printf("游戏制作人：杨刚刚");
	color(14);
	gotoxy(33, 20);
	printf("请选择 1 2 3 4: ");
	color(14);
	scanf("%d", &n);   // 输入选项
	switch (n)
	{
	case 1:
		flag = 1;
		system("cls");
		break;
	case 2:
		explation();   // 游戏规则
		break;
	case 3:
		system("cls"); // 读档
		break;
	case 4:
		gotoxy(30, 28);
		exit(0);       // 退出游戏
		break;
	default:
		color(9);
		gotoxy(33, 22);
		printf("请输入1-4之间的数");
		_getch();       // 输入任意键
		system("cls");  // 清屏
		welcometogame();
	}
}

// 游戏规则
void explation()
{
	int i, j = 1;
	system("cls");
	color(15);
	gotoxy(30, 1);
	printf("游戏规则 Rules of game");
	color(56);
	for (i = 3; i <= 26; i++)       // 输出上下边框
	{
		for (j = 6; j <= 80; j++)   // 输出左右边框
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
	printf("1. W,A,S,D 分别是控制飞机的移动，空格发射子弹");
	gotoxy(10, 9);
	printf("2. O是普通敌机（需一发子弹），A是Boss敌机（需两发子弹）");
	gotoxy(10, 12);
	printf("3. 击败普通敌机可获得1分，击败Boss敌机可获得2分");
	gotoxy(10, 15);
	printf("4. 敌机进入下边界减1分");
	gotoxy(10, 18);
	printf("5. 飞机碰到敌机会坠落");
	gotoxy(10, 21);
	printf("6. 按Z存档，按P暂停游戏");
	color(15);
	gotoxy(25, 23);
	printf("/*****按任意键返回主页面*****/");
	_getch();  // 按任意键返回主界面
	system("cls");
	welcometogame();
}

// 数据初始化
void startup()
{
	mciSendString("open D:\\plane\\game.mp3 alias bkmusic ", NULL, 0, NULL);	// 打开背景音乐
	mciSendString("play bkmusic", NULL, 0, NULL); // 循环播放
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
	int score = 0;			// 成绩
	int number = 0;			// 销毁敌机数
	BulletWidth = 0;
	EnemyMoveSpeed = 30;
	HideCursor();			// 光标
}

// 存档代码
void FileWrite()
{
	FILE* fp;							// 文件指针
	fp = fopen("D:\\game.data", "w");	// 打开文件 "w": write写入文件
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
	fclose(fp);  // 关闭文件
	printf("\n保存成功\n");
}

// 读档代码
void FileRead()
{
	FILE* fp;							// 文件指针
	fp = fopen("D:\\game.data", "r");	// 打开文件 "r": read读取文件
	mciSendString("open D:\\plane\\game.mp3 alias bkmusic ", NULL, 0, NULL);	// 打开背景音乐
	mciSendString("play bkmusic", NULL, 0, NULL); // 循环播放
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
	fclose(fp);  // 关闭文件
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

// 显示画面
void show()
{
	color(112);
	gotoxy(0, 0); // 光标移动到原点位置，以下重画清屏
	int i, j;
	for (i = 0; i < High; i++)
	{
		for (j = 0; j < Width; j++)
		{
			if ((j == Width - 1) || (i == High - 1) || (j == 0) || (i == 0))
				printf("#");             // 打印边界#
			else if (canvas[i][j] == 1)
				printf("8");             // 输出飞机8
			else if (canvas[i][j] == 2)
				printf("o");             // 输出子弹o
			else if (canvas[i][j] == 3)
				printf("O");             // 输出敌机O
			else if (canvas[i][j] == 4)
				printf("A");             // 输出Boss敌机A
			else
				printf(" ");
		}
		printf("\n");
	}
	color(14);
	printf("\n");
	printf("游戏得分: %d\n", score);
	printf("销毁敌机: %d\n\n", number);
	Sleep(20);
}

// 与用户输入无关的更新
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
					if ((i == enemy[k].x) && (j == enemy[k].y))			// 子弹击中敌机
					{
						mciSendString("close gemusic", NULL, 0, NULL);		// 先把前面一次的音乐关闭
						mciSendString("open D:\\plane\\gotEnemy.mp3 alias gemusic ", NULL, 0, NULL);	// 打开音乐
						mciSendString("play gemusic", NULL, 0, NULL);		// 仅播放一次
						score++;										// 分数加1
						number++;										// 销毁敌机数加1
						if (number % 6 == 0 && EnemyMoveSpeed > 3)		// 达到一定积分后，敌机变快
							EnemyMoveSpeed--;
						if (number % 12 == 0)                           // 达到一定积分后，子弹变厉害
							BulletWidth++;
						canvas[enemy[k].x][enemy[k].y] = 0;				// 残影问题
						enemy[k].x = rand() % 2;						// 产生新的敌机
						enemy[k].y = rand() % Width;
						canvas[enemy[k].x][enemy[k].y] = 3;
						canvas[i][j] = 0;								// 子弹消失
					}
				}
				for (k = 0; k < BossNum; k++)
				{
					if ((i == Boss[k].x) && (j == Boss[k].y))	// 子弹击中Boss敌机
					{
						mciSendString("close gemusic", NULL, 0, NULL);		// 先把前面一次的音乐关闭
						mciSendString("open D:\\plane\\gotEnemy.mp3 alias gemusic ", NULL, 0, NULL);	// 打开音乐
						mciSendString("play gemusic", NULL, 0, NULL);		// 仅播放一次	
						Boss[k].life--;								// Boss敌机生命值减1
						if (Boss[k].life == 0)
						{
							canvas[Boss[k].x][Boss[k].y] = 0;	// 残影问题
							Boss[k].x = rand() % 2;					// 产生新Boss敌机
							Boss[k].y = rand() % Width;
							canvas[Boss[k].x][Boss[k].y] = 4;
							canvas[i][j] = 0;							// 子弹消失
							Boss[k].life = 2;
							score++; score++;							// 分数加2
							number++;									// 销毁敌机数加1
						}
					}
				}
				// 子弹向上移动
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
		// 敌机撞到我机
		if ((position_x == enemy[k].x) && (position_y == enemy[k].y) || (position_x + 1 == enemy[k].x) && (position_y - 1 == enemy[k].y) || (position_x + 1 == enemy[k].x) && (position_y + 1 == enemy[k].y) || (position_x + 2 == enemy[k].x) && (position_y + 1 == enemy[k].y) || (position_x + 2 == enemy[k].x) && (position_y - 1 == enemy[k].y))
		{
			mciSendString("close bkmusic", NULL, 0, NULL);		// 先把前面一次的音乐关闭
			mciSendString("open D:\\plane\\explode.mp3 alias exmusic", NULL, 0, NULL);		// 打开音乐
			mciSendString("play exmusic", NULL, 0, NULL);		// 仅播放一次
			color(11);
			printf("\n游戏结束!\n");
			Sleep(3000);
			system("pause");
			exit(0);
		}

		// 敌机跑出显示屏幕
		if (enemy[k].x > High)
		{
			canvas[enemy[k].x][enemy[k].y] = 0;
			enemy[k].x = rand() % 2; // 产生新的敌机
			enemy[k].y = rand() % Width;
			canvas[enemy[k].x][enemy[k].y] = 3;
			score--; // 减分
		}

		if (speed == EnemyMoveSpeed)
		{
			// 敌机下落
			for (k = 0; k < EnemyNum; k++)
			{
				canvas[enemy[k].x][enemy[k].y] = 0;
				enemy[k].x++;
				speed = 0;
				canvas[enemy[k].x][enemy[k].y] = 3;
			}

			// Boss敌机下落
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
		// Boss敌机撞到我机
		if ((position_x == Boss[k].x) && (position_y == Boss[k].y) || (position_x + 1 == Boss[k].x) && (position_y - 1 == Boss[k].y) || (position_x + 1 == Boss[k].x) && (position_y + 1 == Boss[k].y) || (position_x + 2 == Boss[k].x) && (position_y + 1 == Boss[k].y) || (position_x + 2 == Boss[k].x) && (position_y - 1 == Boss[k].y))
		{
			mciSendString("close exmusic", NULL, 0, NULL);		// 先把前面一次的音乐关闭
			mciSendString("open D:\\plane\\explode.mp3 alias exmusic", NULL, 0, NULL);		// 打开音乐
			mciSendString("play exmusic", NULL, 0, NULL);		// 仅播放一次
			color(11);
			printf("\n游戏结束!\n");
			Sleep(3000);
			system("pause");
			exit(0);
		}

		// Boss敌机跑出显示屏幕
		if (Boss[k].x > High)
		{
			canvas[Boss[k].x][Boss[k].y] = 0;
			Boss[k].x = rand() % 2; // 产生新的Boss敌机
			Boss[k].y = rand() % Width;
			canvas[Boss[k].x][Boss[k].y] = 4;
			score--; // 减分
		}
	}
}

// 与用户输入有关的更新
void updateWithInput()
{
	char input;
	if (_kbhit()) // 判断是否有输入
	{
		input = _getch(); // 根据用户的不同输入来移动，不必输入回车
		if (input == 'a' && position_y > 1 || input == 'A')
		{
			canvas[position_x][position_y] = 0;
			canvas[position_x + 1][position_y - 1] = 0;
			canvas[position_x + 1][position_y] = 0;
			canvas[position_x + 1][position_y + 1] = 0;
			position_y--; // 位置左移
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
			position_y++; // 位置右移
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
			position_x--; // 位置上移
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
			position_x++; // 位置下移
			canvas[position_x][position_y] = 1;
			canvas[position_x + 1][position_y - 1] = 1;
			canvas[position_x + 1][position_y] = 1;
			canvas[position_x + 1][position_y + 1] = 1;
		}
		else if (input == ' ') // 发射子弹
		{
			int left = position_y - BulletWidth;
			int right = position_y + BulletWidth;
			if (left < 0)
				left = 0;
			if (right > Width - 1)
				right = Width - 1;
			int k;
			for (k = left; k <= right; k++)		// 发射闪弹
				canvas[position_x - 1][k] = 2;	// 发射子弹的初始位置在飞机的正上方
		}
		else if (input == 'P' || input == 'p')	// 按P暂停游戏
			system("pause");
		else if (input == 'Z' || input == 'z')	// 按Z存档
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
		startup();				// 数据初始化
	else
		FileRead();				// 数据初始化

	while (1)					// 游戏循环执行
	{
		show();					// 显示画面
		updateWithoutInput();	// 与用户输入无关的更新
		updateWithInput();		// 与用户输入有关的更新
	}
	return 0;
}