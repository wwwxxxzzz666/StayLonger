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
	COORD p;//����ṹ�����p
	HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);//��ȡ��ǰ�������
	p.X=x;p.Y=y;//������Ŀ���ƶ�λ�ô��ݸ��ṹ��
	SetConsoleCursorPosition(handle,p);//�ƶ����
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
	printf("���");
    gotoxy(4,2);
    printf("�ܺã����ͣ�");
    getch(); getch();
    clrscr();
    getch();
    return 0;
}