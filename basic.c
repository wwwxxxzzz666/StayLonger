#define WIN;
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#ifdef WIN
#include <windows.h>
#endif

#ifdef WIN
void gotoxy(int x,int y)
{
	COORD p;//定义结构体变量p
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//获取当前函数句柄
	p.X=x;p.Y=y;//将光标的目标移动位置传递给结构体
	SetConsoleCursorPosition(handle,p);//移动光标
}

void clrscr()
{
	system("cls");
}

#else

void gotoxy(int x,int y)
{
	printf("\033[%d;%dH",2*x+1,y);
}

void clrscr()
{
	printf("\33[2J");
}

#endif

int main()
{
	printf("你好");
    gotoxy(4,2);
    printf("很好，加油！");
    getch(); getch();
    clrscr();
    getch();
    return 0;
}