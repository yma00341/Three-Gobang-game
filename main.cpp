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
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input){
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��");
			system("cls");
		}
	} while (input);
}

void game()
{
	char ret = 0;
	//���̶���
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	Displayboard(board, ROW, COL);
	//����
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		system("cls");
		Displayboard(board, ROW, COL);
		//�ж�����Ƿ�ʤ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		ComputerMove(board, ROW, COL);
		system("cls");
		Displayboard(board, ROW, COL);
		//�жϵ����Ƿ�ʤ��
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
	{
		printf("���ʤ��!\n");
		Sleep(500);
		system("cls");
	}
	else if (ret == '#')
	{
		printf("����ʤ��!\n");
		Sleep(500);
		system("cls");

	}
	else
	{
		printf("ƽ��!\n");
		Sleep(500);
		system("cls");
	}
}