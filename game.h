#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 3
#define COL 3
//菜单
void menu();

//游戏主体
void game();

//初始化棋盘
void INTARR(char arr[ROW][COL], int row ,int col);

//打印棋盘
void PRINTFARR(char arr[ROW][COL], int row, int col);

//玩家下棋
void PERSONARR(char arr[ROW][COL], int row, int col);

//电脑下棋
void  MACHINEARR(char arr[ROW][COL], int row, int col);

//判断输赢
char  ISWIN(char arr[ROW][COL], int row, int col);
