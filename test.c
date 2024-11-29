#include "game.h"

int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请输入>: ");
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                game();
                break;
            case 0:
                break;
            default:
                printf("输入错误，请重新输入\n");
        }
    }
    while(input);
    return 0;
}