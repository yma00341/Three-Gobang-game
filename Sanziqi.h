#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


#define ROW 3
#define COL 3

void InitBoard(char board[ROW][COL], int row, int col);
void Displayboard(char board[ROW][COL],int row ,int col);
void PlayerMove(char board[ROW][COL], int row, int col);
void ComputerMove(char board[ROW][COL], int row, int col);

//IsWin需要告诉我们四种游戏状态
//玩家赢 '*'，电脑赢 '#'，平局 'Q'，游戏继续 'C'
int IsFull(char board[ROW][COL], int row, int col);
char IsWin(char board[ROW][COL], int row, int col);