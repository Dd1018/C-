#pragma once
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define ROW 9
#define COL 9
#define COT 10
#define COLS COL+2
#define ROWS ROW+2
Itnboard(char board[ROWS][COLS], int rows, int cols, char set);
Displayboard(char board[ROWS][COLS], int row, int col);
ComputerSet(char board[ROWS][COLS], int row, int col);
Playmove(char board[ROWS][COLS],char mine[ROWS][COLS], int row, int col);//ÕÊº“≈≈¿◊