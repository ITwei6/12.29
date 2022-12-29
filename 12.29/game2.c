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
	printf("--------ɨ��--------\n");//��������
	int i, j;//��ӡ�к�
	for (i = 0;i <=col;i++)
	{
		printf("%d ", i);
	}
	printf("\n");//����
	for (i = 1;i <=row;i++)
	{
		printf("%d ", i);//��ӡ�кţ�ÿ�п�ͷ��
		for (j = 1;j <= col;j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------ɨ��--------\n");
}
void Set_mine(char mine[ROWS][COLS], int row, int col)
{
	//������������꣬�ٲ����ף�
	int count = COUNT;
	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;
		//�ж��Ƿ�������;
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
	//��ô�Ų��أ�ͨ����mine���̣������£�x��y�Ų飬���ף�ը����������ͳ����Χ�����׵ĸ����������show���̡�;3
	int x, y;
	int win = 0;
	while (win<row*col-COUNT)
	{
		printf("������Ҫ�Ų�����꣺\n");
		//�ж�����Ϸ���
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (show[x][y] != '*')
			{
				printf("��Ǹ���������ѱ��Ų�\n");
				continue;
			}
			if (mine[x][y] == '1')
			{
				printf("��Ǹ�㱻ը����\n");
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
			printf("����Ƿ����������룺\n");
		}
     }
	if (win == row * col - COUNT)
	{
		printf("��ϲ�����׳ɹ�\n");
	}
	
}