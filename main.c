#define WIN
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#ifdef WIN
#include <windows.h>
#endif

#include "stdinit.h"

#include "base.h"

#include "test.h"

#define MX 100
#define MY 100
#define OBJMAX 6666  //地图对象数量上限
#define VMAX 90  //速度分量上限
#define GAMETYPE  //游戏类型

#define MENUT 380  //菜单操作基础时间，单位ms
#define MT 100  //基础移动冷却时间，单位ms
#define ANT 10  //子弹动态活动运动基础单位时间，单位ms
#define BNT 300  //冲击波动态活动运动基础单位时间，单位ms
#define DT 1  //绘制延迟，单位ms
#define PT 10  //物理计算单位时间，单位ms
#define OT 1000  //氧气判定单位时间，单位ms

#define BUB 1.3  //子弹击退常数
#define BLB 3.2  //冲击波击退常数
#define PM 0.6  //物理引擎空间计算最小单位
#define EK 1  //弹性碰撞系数

#define MHP 1000  //玩家HP上限
#define MOG 1000  //玩家OG上限
#define OGDMG 10  //缺氧伤害
#define RUNOG -100  //奔跑最低氧气值

#define WEAKMSG  //弱消息提醒开关
//#define SCREENSHAKE  //屏幕抖动效果开关
#define SHAKE 0.7  //屏幕抖动参数

block *map[MX+2][MY+2];
int flor[MX+2][MY+2];
block *iflor[MX+2][MY+2];
item imap[MX+2][MY+2];
player *liv[MX+2][MY+2];
player p[OBJMAX];
int pn;  //玩家和ai数量
int PS;  //玩家数量
int fps,fpsf;
clock_t fpst,dpst,ppst,opst;
clock_t stayt; //游戏坚持时间
FILE *fp;

#include "basic.h"

void background()
{
	gotoxy(1,1);
	print("                                                      ",6,6);
	gotoxy(2,1);
	print("                     Stay Longer                      ",15,6);
	gotoxy(3,1);
	print("                                                      ",6,6);
	gotoxy(4,1);
	print("                                                      ",6,6);
	gotoxy(5,1);
	print("                                                      ",6,6);
	gotoxy(6,1);
	print("                                                      ",6,6);
	gotoxy(7,1);
	print("                                                      ",6,6);
	gotoxy(8,1);
	print("                                                      ",6,6);
	gotoxy(9,1);
	print("                                                      ",6,6);
	gotoxy(10,1);
	print("                                                      ",6,6);
	gotoxy(11,1);
	print("                                                      ",6,6);
	gotoxy(12,1);
	print("                                                      ",6,6);
	gotoxy(13,1);
	print("                                                      ",6,6);
	gotoxy(14,1);
	print("                                                      ",6,6);
	gotoxy(15,1);
	print("                                                      ",6,6);
	gotoxy(16,1);
	print("   Alpha 0.7                                          ",5,6);
}

void gameend()
{
    int i;
    for (i=1;i<=16;i++)
    {
	    print("                                                      ",6,6);
        wait(60);
    }
    background();
    gotoxy(3,1);
    print("                      结    束                        \n",7,6);
	print("  共存活了",14,6);
	printf("\e[0;37m\e[46m %.2lf\e[0m",(clock()-stayt)/1000.0);
	print("s,Stayer!\n",14,6);
    for (i=1;i<=PS;i++)
    {
        print(p[i].c,14,6); printf("\n");
        print("  分数：",14,6);
        int j,t=0;
        t=(int)(((clock()-stayt)/1000.0)*1.5);
        for (j=1;j<=20;j++) t+=p[i].kill[j]*stp[j].score;
        printf("\e[0;37m\e[46m  %d\e[0m\n",t);
        printf("\n");
    }
	    print("\n  按下ESC或者B键返回",14,6);
	while (1)
	{
		getinput();
		if (keyp("b")) {clrscr(); return;}
		#ifdef WIN
		if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
		#endif
	}
}

void freelevel()
{
	wait(200);
	clrscr();
	clock_t st=clock();
	int zz=1;
	char sel[5][75];
	strcpy(sel[0],"                                                      ");
	strcpy(sel[1],"                      单人模式                        ");
	strcpy(sel[2],"                      多人模式                        ");
	strcpy(sel[3],"                      返    回                        ");
	strcpy(sel[4],"                                                      ");
	int z=1;
	background();
	while (1)
	{
		if ((MENUT*CLOCKS_PER_SEC/1000)+st<=clock())
		{
			zz=1; st=clock();
		}
		gotoxy(3,1);
		print("                      自由模式                        ",7,6);
		gotoxy(9,1);
		print(sel[z-1],12,6);
		gotoxy(10,1);
		printf("\e[4m");
		print(sel[z],13,6);
		gotoxy(11,1);
		print(sel[z+1],12,6);
		getinput();
		if (zz&&keyp("w")&&(z>1)) zz=0,z--;
		if (zz&&keyp("s")&&(z<3)) zz=0,z++;
		if (keyp("b")) {clrscr(); return;}
		if (keyp("e"))
		{
			if (z==1)
			{
				PS=1; stiinit(); stbinit(); stpinit(); mapload(); playerinit(1); gamescreen(1);
				gameend();
			}
			else if (z==2)
			{
				PS=2; stiinit(); stbinit(); stpinit(); mapload(); playerinit(2); gamescreen(2);
				gameend();
			}
			else if (z==3)
			{
				return;
			}
		}
		#ifdef WIN
		if ((GetKeyState(VK_RETURN)<0)||(GetKeyState(VK_SPACE)<0))
		{
			if (z==1)
			{
				stiinit(); stbinit(); stpinit(); mapload(); playerinit(1); gamescreen(1);
			}
			else if (z==2)
			{
				stiinit(); stbinit(); stpinit(); mapload(); playerinit(2); gamescreen(2);
			}
			else if (z==3)
			{
				return;
			}
		}
	    if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
		#endif
	}
}

void about()
{	
	clrscr();
	background();
	while (1)
	{
		gotoxy(3,1);
		print("                      关    于                        ",7,6);
		gotoxy(5,1);
		print("      本游戏为USTC2020计算机程序设计A课程大作业项目",14,6);
		gotoxy(6,1);
		print("  目前仅推出控制台字符画面版本，代码完全开源",14,6);
		gotoxy(7,1);
		print("  github：https://github.com/wwwxxxzzz666/StayLonger",14,6);
		gotoxy(8,1);
		print("  制作团队：",14,6);
		gotoxy(9,1);
		print("    wwwxxxzzz666：程序代码实现、游戏设计、内容设计等",14,6);
		gotoxy(10,1);
		print("    lukejia0417：内容设计、地图设计",14,6);
		gotoxy(11,1);
		print("    i-sor：菜单帮助说明设计等",14,6);
		gotoxy(12,1);
		print("      由于人力物力精力十分匮乏，制作实属不易QAQ。",11,6);
		gotoxy(13,1);
		print("  游戏底层包括各类物理引擎等完全自主制作。难免有所不足",11,6);
		gotoxy(14,1);
		print("  请反映问题给我们，并多多给我们包容、支持和鼓励QAQ",11,6);
		gotoxy(15,1);
		print("      敬上我们诚挚的谢意",9,6);
		getinput();
		if (keyp("b")) {clrscr(); return;}
		#ifdef WIN
	    if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
		#endif
	}
}

void help()
{
	clrscr();
	background();
	while (1)
	{
		gotoxy(3,1);
		print("                      帮    助                        ",7,6);
		gotoxy(5,1);
		print("操作说明：",14,6);
		gotoxy(6,1);
		print("玩家1：",14,6);
		gotoxy(7,1);
		print("移动：wasd；疾跑：shift；捡起：e；丢下：q；攻击：tfgh",14,6);
		gotoxy(8,1);
		print("玩家2：",14,6);
		gotoxy(9,1);
		print("移动：ijkl",14,6);
		gotoxy(10,1);
		print("界面说明：",14,6);
		gotoxy(11,1);
		print("界面头行显示人物血量和氧气值",14,6);
		gotoxy(12,1);
		print("地图下方为 人物名称 装备:弹药数 地块说明，再下方为消息",11,6);
		gotoxy(13,1);
		print("图标说明：",11,6);
		gotoxy(14,1);
		print("玩家:デ 敌人:バ 护卫:ㄐ",11,6);
		gotoxy(15,1);
		print("游戏基本规则：活下去！同时尽可能完成相应的任务。",9,6);
		getinput();
		if (keyp("b")) {clrscr(); return;}
		#ifdef WIN
	    if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
		#endif
	}
}

void menu()
{
	clrscr();
	clock_t st=clock();
	int zz=1;
	char tips[10][75];  //提示信息
	int tipn=2; //提示信息数
	strcpy(tips[0],"      Tips:自由模式没有敌人？按c和方向键试试~");
	strcpy(tips[1],"      Tips:嫌子弹不够？为什么不找开枪的人要呢~");
	char sel[7][75];
	strcpy(sel[0],"                                                      ");
	strcpy(sel[1],"                      挑    战                        ");
	strcpy(sel[2],"                      自由模式                        ");
	strcpy(sel[3],"                      教    程                        ");
	strcpy(sel[4],"                      关    于                        ");
	strcpy(sel[5],"                      退    出                        ");
	strcpy(sel[6],"                                                      ");
	int z=1;  //光标序号
	background();
	gotoxy(15,1);
	print(tips[rand()%tipn],6,6);
	while (1)
	{
		if ((MENUT*CLOCKS_PER_SEC/1000)+st<=clock())
		{
			zz=1; st=clock();
		}
		gotoxy(9,1);
		print(sel[z-1],12,6);
		gotoxy(10,1);
		printf("\e[4m");
		print(sel[z],13,6);
		gotoxy(11,1);
		print(sel[z+1],12,6);
		getinput();
		if (zz&&keyp("w")&&(z>1)) zz=0,z--;
		if (zz&&keyp("s")&&(z<5)) zz=0,z++;
		if (keyp("e"))
		{
			if (z==1)
			{

			}
			else if (z==2)
			{
				freelevel(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==3)
			{
				help(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==4)
			{
				about(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==5)
			{
				return;
			}
		}
		#ifdef WIN
		if ((GetKeyState(VK_RETURN)<0)||(GetKeyState(VK_SPACE)<0))
		{
			if (z==1)
			{

			}
			else if (z==2)
			{
				freelevel(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==3)
			{
				help(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==4)
			{
				about(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==5)
			{
				return;
			}
		}
		#endif
	}
}

void main()
{
#ifdef WIN
	system("cls"); HideCursor(); system("mode con cols=54 lines=16"); SetConsoleTitle("Stay Longer");
#endif
	printf("\e[?25l");
	srand((unsigned int)time(NULL));
	menu();
	//test();
	//level1();
}