#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("******************************\n");
	printf("*******     1.play     *******\n");
	printf("*******     0.exit     *******\n");
	printf("******************************\n");
}

void game() 
{
	char ret = 0;//游戏状态

	//存储数据 —— 二维数组
	char board[ROW][COL];

	//初始化棋盘 —— 初始化空格
	InitBoard(board, ROW, COL);

	//棋盘打印 —— 本质是打印数组的内容
	DisplayBoard(board, ROW, COL);

	//玩家走
	//电脑走
	while (1) 
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;

		//电脑下棋
		printf("电脑走:>\n");
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
			break;
	}
	printf("%c\n", ret);
	if (ret == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢了\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}

int main() 
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&input);
		switch (input)
		{ 
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("无效的选择，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}