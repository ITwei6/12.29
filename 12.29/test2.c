#include "game2.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//1.��ʼ������
	Init_board(mine, ROWS, COLS,'0');
	Init_board(show, ROWS, COLS,'*');
	//2.��ӡ���̣�ʵ����ֻ��ӡ��show���̣�
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//3.������
	Set_mine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	//4.����
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
		printf("��ѡ��:\n");
		scanf("%d", &intput);
		switch(intput)
		{
			case 1: game();break;
			case 0:printf("�˳���Ϸ\n");break;
			default:printf("���������������\n");break;
		}

	} while (intput);
}
int main()
{
	test();

	return 0;
}