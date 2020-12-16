void test()
{
	printf("\e[31m你好\e[0m");
    gotoxy(5,2);
    printf("很好，加油！");
    getch(); getch();
    clrscr();
    getch();
}