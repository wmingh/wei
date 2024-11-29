#include "game.h"



void game()
{
    char ret = 0;
    char arr [ROW][COL]={0};
    INTARR(arr,ROW,COL);
    PRINTFARR(arr,ROW,COL);
    while(1)
    {
        PERSONARR(arr,ROW,COL);
        ret = ISWIN(arr,ROW,COL);
        if(ret !='C')
        {
            break;
        }
        PRINTFARR(arr,ROW,COL);
        MACHINEARR(arr,ROW,COL);
        ret = ISWIN(arr,ROW,COL);
        if(ret !='C')
        {
            break;
        }
        PRINTFARR(arr,ROW,COL);
    }
    if(ret=='#')
    {
        printf("玩家赢\n");
    }
    else if (ret =='*')
    {
        printf("电脑赢\n");
    }
    else
    {
        printf("平局\n");
    }
}

void menu()
{
    printf("*************************\n");
    printf("*************************\n");
    printf("*********1.开始游戏 *******\n");
    printf("*********0.结束游戏 *******\n");
    printf("*************************\n");
    printf("*************************\n");
}
void INTARR( char arr[ROW][COL],int row, int col)
{
    int m = 0;
    for(m = 0;m<row;m++)
    {
        int n = 0;
        for(n = 0;n<col;n++)
        {
            arr[m][n]=' ';
        }
    }
}
void PRINTFARR( char arr[ROW][COL],int row, int col)
{
    for(int m = 0; m<row ; m++)
    {
        for(int n = 0;n<col;n++)
        {
            printf(" %c ",arr[m][n]);
            if(n<col-1)
                printf("|");
        }
        printf("\n");
        if(m<row-1)
        {
            for(int n = 0;n<col;n++)
            {
                printf("---");
            if(n<col-1)
                printf("|");
            }
        printf("\n");
        }
    }
}
void PERSONARR( char arr[ROW][COL],int row, int col)
{
    int x = 0, y = 0;
    printf("玩家下棋:>\n");
    while(1) {
        printf("请输入坐标:>");
        scanf("%d %d",&x,&y);
        if(x >= 1 && x <= row && y >= 1 && y <= col)
        {
            if(arr[x-1][y-1]==' ')
            {
                arr[x-1][y-1]='#';
                break;
            }
            else
            {
                printf("坐标已被占用，请选择其他坐标\n");
            }
        }
        else
        {
            printf("输入错误，请重新输入:>\n");
        }
    }
}
void  MACHINEARR(char arr[ROW][COL], int row, int col)
{
    printf("电脑下棋：>\n");
    int x = 0, y = 0;
    while(1)
    {
        x = rand()%row;
        y = rand()%col;
        if(arr[x][y]==' ')
        {
            arr[x][y]='*';
            break;
        }
    }
}
int Isfull(char arr[ROW][COL], int row, int col)
{
    for(int m = 0;m<row;m++)
    {
        for(int n = 0;n<col;n++)
        {
            if(arr[m][n]==' ')
                return 0;
        }
    }
    return 1;
}



char ISWIN(char arr[ROW][COL], int row, int col)
{
    for(int m = 0;m<row;m++)
    {
        if(arr[m][0] == arr[m][1] && arr[m][1] == arr[m][2] && arr[m][1] !=' ')
        return arr[m][1];
    }
    for(int n = 0;n<col;n++)
    {
        if(arr[0][n] == arr[1][n] && arr[1][n] && arr[2][n] && arr[1][n] !=' ')
        return arr[1][n];
    }
    if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1]!=' ')
        return arr[1][1];
    if(arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1]!=' ')
        return arr[1][1];

    if(Isfull(arr,row,col))
    {
        return 'Q';
    }
    return 'C';
}