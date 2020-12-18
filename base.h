void wait(int ms)
{
	clock_t endwait;
	endwait = clock() + ms * CLOCKS_PER_SEC / 1000;//CLOCKS_PER_SEC宏定义1000,标准时间差
	while(clock()<endwait);
}
 
#ifndef WIN
int max(int a,int b)
{
	return ((a>b)?a:b);
}
 
int min(int a,int b)
{
	return ((a<b)?a:b);
}
#endif
 
#ifdef WIN
/*void gotoxy(int x,int y)
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
*/
 
void HideCursor()
{
	CONSOLE_CURSOR_INFO cursor;    
	cursor.bVisible = FALSE;    
	cursor.dwSize = sizeof(cursor);    
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);    
	SetConsoleCursorInfo(handle, &cursor);
}
 
void modeset(int w,int h) {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD size = {w, h};
	SetConsoleScreenBufferSize(hOut,size);
	SMALL_RECT rc = {1,1, w, h};
	SetConsoleWindowInfo(hOut,1,&rc);
	system("cls");
	return;
}
 
void gotoxy(int x,int y)
{
	printf("\033[%d;%dH",y,x);
}
 
void clrscr()
{
	printf("\33[2J");
}
 
char *col[16]={
"\033[m",         //NONE 0
"\033[0;32;31m",  //RED 1
"\033[1;31m",     //LIGHT_RED 2
"\033[0;32;32m",  //GREEN 3
"\033[1;32m",     //LIGHT_GREEN 4
"\033[0;32;34m",  //BLUE 5
"\033[1;34m",     //LIGHT_BLUE 6
"\033[1;30m",     //GRAY 7
"\033[0;36m",     //CYAN 8
"\033[1;36m",     //LIGHT_CYAN 9
"\033[0;35m",     //PURPLE 10
"\033[1;35m",     //LIGHT_PURPLE 11
"\033[0;33m",     //BROWN 12
"\033[1;33m",     //YELLOW 13
"\033[0;37m",     //LIGHT_GRAY 14
"\033[1;37m"};    //WHITE 15
    #define NONE "\033[m"
     
    #define RED "\033[0;32;31m"
     
    #define LIGHT_RED "\033[1;31m"
     
    #define GREEN "\033[0;32;32m"
     
    #define LIGHT_GREEN "\033[1;32m"
     
    #define BLUE "\033[0;32;34m"
     
    #define LIGHT_BLUE "\033[1;34m"
     
    #define DARY_GRAY "\033[1;30m"
     
    #define CYAN "\033[0;36m"
     
    #define LIGHT_CYAN "\033[1;36m"
     
    #define PURPLE "\033[0;35m"
     
    #define LIGHT_PURPLE "\033[1;35m"
     
    #define BROWN "\033[0;33m"
     
    #define YELLOW "\033[1;33m"
     
    #define LIGHT_GRAY "\033[0;37m"
     
    #define WHITE "\033[1;37m"
 
void print(char *ss,int fc,int bc)
{
	printf("%s\e[4%dm%2s\e[0m",col[fc],bc,ss);
}
 
#else
/*
void gotoxy(int x,int y)
{
	printf("\033[%d;%dH",x,y);
}
 
void clrscr()
{
	printf("\33[2J");
}
*/
char *col[16]={
"\033[m",         //NONE 0
"\033[0;32;31m",  //RED 1
"\033[1;31m",     //LIGHT_RED 2
"\033[0;32;32m",  //GREEN 3
"\033[1;32m",     //LIGHT_GREEN 4
"\033[0;32;34m",  //BLUE 5
"\033[1;34m",     //LIGHT_BLUE 6
"\033[1;30m",     //GRAY 7
"\033[0;36m",     //CYAN 8
"\033[1;36m",     //LIGHT_CYAN 9
"\033[0;35m",     //PURPLE 10
"\033[1;35m",     //LIGHT_PURPLE 11
"\033[0;33m",     //BROWN 12
"\033[1;33m",     //YELLOW 13
"\033[0;37m",     //LIGHT_GRAY 14
"\033[1;37m"};    //WHITE 15
    #define NONE "\033[m"
     
    #define RED "\033[0;32;31m"
     
    #define LIGHT_RED "\033[1;31m"
     
    #define GREEN "\033[0;32;32m"
     
    #define LIGHT_GREEN "\033[1;32m"
     
    #define BLUE "\033[0;32;34m"
     
    #define LIGHT_BLUE "\033[1;34m"
     
    #define DARY_GRAY "\033[1;30m"
     
    #define CYAN "\033[0;36m"
     
    #define LIGHT_CYAN "\033[1;36m"
     
    #define PURPLE "\033[0;35m"
     
    #define LIGHT_PURPLE "\033[1;35m"
     
    #define BROWN "\033[0;33m"
     
    #define YELLOW "\033[1;33m"
     
    #define LIGHT_GRAY "\033[0;37m"
     
    #define WHITE "\033[1;37m"
 
void print(char *ss,int fc,int bc)
{
	printf("%s\e[4%dm%2s\e[0m",col[fc],bc,ss);
}
 
#endif