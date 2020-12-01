#include <stdio.h>
#define NONE         "\033[m"
#define RED          "\033[0;32;31m"
#define LIGHT_RED    "\033[1;31m"
#define GREEN        "\033[0;32;32m"
#define LIGHT_GREEN  "\033[1;32m"
#define BLUE         "\033[0;32;34m"
#define LIGHT_BLUE   "\033[1;34m"
#define DARY_GRAY    "\033[1;30m"
#define CYAN         "\033[0;36m"
#define LIGHT_CYAN   "\033[1;36m"
#define PURPLE       "\033[0;35m"
#define LIGHT_PURPLE "\033[1;35m"
#define BROWN        "\033[0;33m"
#define YELLOW       "\033[1;33m"
#define LIGHT_GRAY   "\033[0;37m"
#define WHITE        "\033[1;37m"

int main()
{
    printf( "\033[1;31;40m 输出红色字符 \033[0m" );
    printf(CYAN"current function is %s " GREEN " file line is %d/n" NONE,"ssfsfs",2);

    fprintf(stderr, RED "current function is %s " BLUE " file line is %d/n" NONE,
            __FUNCTION__, __LINE__ );
    getch();getch();
    return 0;
}