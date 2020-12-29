void test()
{
	printf("\e[31m你好\e[0m");
    gotoxy(2,5);
    printf("很好，加油！");
    char ss[]="w";
    puts(ss);
    printf("%d&&%c&&&%c",strlen(ss),ss[0],ss[1]);
#ifdef WIN
    while (1)
    {
        printf("%d\n",GetKeyState(ss[0]-32));
    }
#endif
    getch(); getch();
    clrscr();
    getch();
}