#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define Easy_count 10
void Itnboard(char board[ROWS][COLS], int rows, int cols,char c);
void Displayboard(char board[ROWS][COLS], int row, int col);
void Setboard(char board[ROWS][COLS], int row, int col);
void Player(char board[ROWS][COLS], char show[ROWS][COLS], int row, int col);
void Openboard(char show[ROWS][COLS], char board[ROWS][COLS], int row, int col);