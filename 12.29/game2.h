#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define COUNT 10
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2//º¯ÊýÉùÃ÷
void Init_board(char board[ROWS][COLS], int rows, int cols,char set);
void DisplayBoard(char board[ROWS][COLS], int row, int col);
void Set_mine(char mine[ROWS][COLS], int row, int col);
void CheckBoard(char mine[ROWS][COLS],char show[ROWS][COLS], int row, int col);
int get_around_mine(char mine[ROWS][COLS], int x, int y);