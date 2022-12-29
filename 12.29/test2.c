#include "game2.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//1.初始化棋盘
	Init_board(mine, ROWS, COLS,'0');
	Init_board(show, ROWS, COLS,'*');
	//2.打印棋盘，实际上只打印出show棋盘；
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//3.布置雷
	Set_mine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//4.排雷
	CheckBoard(mine, show, ROW, COL);
}
void menu()
{
	printf("************************\n");
	printf("******   1.play   ******\n");
	printf("******   0.exit   ******\n");
	printf("************************\n");
}
void test()
{
	int intput;
	srand(time(NULL));
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &intput);
		switch(intput)
		{
			case 1: game();break;
			case 0:printf("退出游戏\n");break;
			default:printf("输入错误，重新输入\n");break;
		}

	} while (intput);
}
int main()
{
	test();

	return 0;
}