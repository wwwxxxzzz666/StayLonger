#include <stdio.h>
int main(int argc,char **argv)
{
    printf("\033[31m有意思\n\033[0m");
    printf("\033[2;7;1m真奇怪\n\033[2;7;0m");
    printf("\033[2;5H\033[41;36m好家伙\n\033[0m");
    getch();getch();
    return 0;
}