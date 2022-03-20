#pragma once
#define ROW 3
#define COL 3
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
void Itnboard(char board[ROW][COL], int row, int col);
void Printboard(char board[ROW][COL], int row, int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);
char Iswin(char board[ROW][COL], int row, int col);
int IsFull(char board[ROW][COL], int row, int col);