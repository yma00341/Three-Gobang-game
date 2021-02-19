#define _CRT_SECURE_NO_WARNINGS 1

#include "Sanziqi.h"

void test();
void menu();
void game();

int main()
{
	test();
	return 0;
}

void menu()
{
	printf("*************************************\n");
	printf("******  1.play           0.exit *****\n");
	printf("*************************************\n");
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择");
			system("cls");
		}
	} while (input);
}

void game()
{
	char ret = 0;
	//棋盘定义
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	//下棋
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		system("cls");
		Displayboard(board, ROW, COL);
		//判断玩家是否胜利
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputerMove(board, ROW, COL);
		system("cls");
		Displayboard(board, ROW, COL);
		//判断电脑是否胜利
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("玩家胜利!\n");
		Sleep(500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("电脑胜利!\n");
		Sleep(500);
		system("cls");

	}
	else
	{
		printf("平局!\n");
		Sleep(500);
		system("cls");
	}
}