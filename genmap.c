#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int i,j,k,t;
int a[11][11]={0};
FILE *fp;

int main()
{
	srand((unsigned int)time(NULL));
    for (i=1;i<=9;i++)
        for (j=1;j<=100;j++)
            a[i][j]=3;
    for (i=92;i<=100;i++)
        for (j=1;j<=100;j++)
            a[i][j]=3;
    for (i=10;i<=91;i++)
    {
        for (j=1;j<=9;j++)
            a[i][j]=3;
        for (j=92;j<=100;j++)
            a[i][j]=3;
    }

    for (i=10;i<=17;i++)
        for (j=10;j<=91;j++)
            a[i][j]=6;
    for (i=84;i<=91;i++)
        for (j=10;j<=91;j++)
            a[i][j]=6;
    for (i=18;i<=83;i++)
    {
        for (j=10;j<=17;j++)
            a[i][j]=6;
        for (j=84;j<=91;j++)
            a[i][j]=6;
    }

    for (i=18;i<=24;i++)
        for (j=19;j<=83;j++)
            a[i][j]=6;
    for (i=84;i<=91;i++)
        for (j=10;j<=91;j++)
            a[i][j]=6;
    for (i=18;i<=83;i++)
    {
        for (j=10;j<=17;j++)
            a[i][j]=6;
        for (j=84;j<=91;j++)
            a[i][j]=6;
    }
    fp=fopen("map.dat","w");
}