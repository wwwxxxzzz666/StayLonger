#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

void gotoxy(int x,int y)
{
	printf("\033[%d;%dH",x,y);
}

void clrscr()
{
	printf("\33[2J");
}

int main()
{
		
}