#include "game2.h"
void Init_board(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i, j;
	for (i = 0;i < rows;i++)
	{
		for (j = 0;j < cols;j++)
		{
			board[i][j] = set;
		}
	}
}
void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	printf("--------扫雷--------\n");//修整修整
	int i, j;//打印列号
	for (i = 0;i <=col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");//换行
	for (i = 1;i <=row;i++)
	{
		printf("%d ", i);//打印行号，每行开头。
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------扫雷--------\n");
}
void Set_mine(char mine[ROWS][COLS], int row, int col)
{
	//先生成随机坐标，再布置雷；
	int count = COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		//判断是否有雷了;
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}
int get_around_mine(char mine[ROWS][COLS], int x, int y)
{
	return  mine[x - 1][y]+mine[x - 1][y - 1]+mine[x - 1][y + 1]+mine[x][y - 1]+mine[x][y + 1]
		+mine[x + 1][y]+mine[x + 1][y - 1]+mine[x + 1][y + 1]-8*'0';

}
void CheckBoard(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	//怎么排查呢，通过对mine棋盘，坐标下，x，y排查，是雷，炸死，不是雷统计周围坐标雷的格个数，传给show棋盘。;3
	int x, y;
	int win = 0;
	while (win<row*col-COUNT)
	{
		printf("请输入要排查的坐标：\n");
		//判断坐标合法性
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("抱歉，该坐标已被排查\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("抱歉你被炸死了\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int n= get_around_mine(mine, x, y);
				show[x][y] = n + '0';
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("坐标非法，重新输入：\n");
		}
     }
	if (win == row * col - COUNT)
	{
		printf("恭喜你排雷成功\n");
	}
	
}