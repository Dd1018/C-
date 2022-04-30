#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 3
#define COL 3
Setboard(char board[ROW][COL],int row,int col);
Printboard(char board[ROW][COL], int row, int col);
PlayerMove(char board[ROW][COL], int row, int col);
ComputerMove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);
char Computer_want_win(char board[ROW][COL], int row, int col);
ComputerMove3(char board[ROW][COL], int row, int col);
ComputerMove2(char board[ROW][COL], int row, int col);