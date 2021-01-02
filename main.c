#define WIN
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#ifndef WIN
#include "cconio.h"
#else
#include <conio.h>
#endif
#include <math.h>
#ifdef WIN
#include <windows.h>
#endif

int DDC=1;  //部分GBK字符是否双重显示
#include "stdinit.h"

int BIGKEYBOARD=1;  //是否是大键盘
//#define DEBUG //是否显示DEBUG

#define MX 100
#define MY 100
#define OBJMAX 6666  //地图对象数量上限
#define VMAX 90  //速度分量上限
#define GAMETYPE  //游戏类型
 
#define MENUT 380  //菜单操作基础时间，单位ms
#define MT 100  //基础移动冷却时间，单位ms
#define ANT 10  //子弹动态活动运动基础单位时间，单位ms
#define BNT 300  //冲击波动态活动运动基础单位时间，单位ms
int DT=2;  //绘制延迟，单位ms
#define PT 10  //物理计算单位时间，单位ms
#define OT 1000  //氧气判定单位时间，单位ms
#define BT 100  //击退延迟时间，单位ms
#define SWT 300  //切换道具延迟时间，单位ms
#define SGT 60  //剑气延迟时间，单位ms

#define BUB 1.3  //子弹击退常数(已失效)
#define BLB 3.2  //手雷冲击波击退常数(已失效)
#define PM 0.3  //物理引擎空间计算最小单位
#define EK 1  //弹性碰撞系数
 
#define MHP 1000  //玩家HP上限
#define MOG 1000  //玩家OG上限
#define OGDMG 10  //缺氧伤害
#define BOMBDMG 25  //手雷砸击伤害
#define RUNOG -100  //奔跑最低氧气值

#define GUIDE  //地图显示指引
#define WEAKMSG  //弱消息提醒开关
//#define SCREENSHAKE  //屏幕抖动效果开关
#define SHAKE 0.7  //屏幕抖动参数

block *map[MX+2][MY+2];
block drbuf[MX+2][MY+2];
int flor[MX+2][MY+2];
block *iflor[MX+2][MY+2];
item imap[MX+2][MY+2];
player *liv[MX+2][MY+2];
player p[OBJMAX];
int pn;  //玩家和ai数量
int PS;  //玩家数量
int ETD;  //敌人队友子弹伤害
int SPT[7]={0,5000,20000,20000,0,0,0};  //各关卡地图刷新单位时间，单位ms
int fps,fpsf;
clock_t fpst,dpst,ppst,opst,spst;
clock_t stayt; //游戏坚持时间(实际记录游戏开始时间)
FILE *fp;
int pre;  //挑战完成保存进度
char tips[10][75];  //提示信息
int tipn; //提示信息数

#include "base.h"

#include "input.h"

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
	print("   Alpha 1.0                                          ",5,6);
}

#include "test.h"

#include "basic.h"

void gameend(int level)
{
    int i,sum=0;
    for (i=1;i<=16;i++)
    {
	    print("                                                      ",6,6);
        wait(60);
    }
    background();
	if (level==0)  //自由模式
	{
		gotoxy(3,1);
		print("                      结    束                        \n",7,6);
		print("  共存活了",14,6);
		printf("\e[0;37m\e[46m %.2lf\e[0m",((double)clock()-stayt)/CLOCKS_PER_SEC);
		print("s,Stayer!\n",14,6);
		for (i=1;i<=PS;i++)
		{
			print(p[i].c,14,6); printf("\n");
			print("  分数：",14,6);
			int j,t=0;
			t=(int)(((double)clock()-stayt)/CLOCKS_PER_SEC*1.5);
			for (j=1;j<=30;j++) t+=p[i].kill[j]*stp[j].score;
			sum+=t;
			printf("\e[0;37m\e[46m  %d\e[0m\n",t);
			printf("\n");
		}
		sum/=PS;
		print("      总分数：",14,6);
		printf("\e[0;37m\e[46m  %d\e[0m\n",sum);
		print("\n  按下ESC或者B键返回",14,6);
		while (1)
		{
			getinput();
			if (keyp("B")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
			#endif
		}
	}
	else if (level==1)  //挑战1
	{
		gotoxy(3,1);
		print("                      结    束                        \n",7,6);
		print("  共存活了",14,6);
		printf("\e[0;37m\e[46m %.2lf\e[0m",((double)clock()-stayt)/CLOCKS_PER_SEC);
		print("s,Stayer!\n",14,6);
		for (i=1;i<=PS;i++)
		{
			print(p[i].c,14,6); printf("\n");
			print("  分数：",14,6);
			int j,t=0;
			t=(int)(((double)clock()-stayt)/CLOCKS_PER_SEC*0.3);
			for (j=1;j<=30;j++) t+=p[i].kill[j]*stp[j].score;
			sum+=t;
			printf("\e[0;37m\e[46m  %d\e[0m\n",t);
			printf("\n");
		}
		sum/=PS;
		print("      总分数：",14,6);
		printf("\e[0;37m\e[46m  %d\e[0m\n",sum);
		print("      评级：",14,6);
		if (sum>=160)
		    print("王者归来!那个人又回来了!全服震惊!",2,6);
		else if (sum>=100)
		    print("一流的Stayer!令人惊艳的操作!",4,6);
		else if (sum>=70)
		    print("还算合格的初体验!成长令人期待!",14,6);
		else print("...不愧是您。再试亿次吧~",13,6);
		if (sum>=85)
		{
			pre=max(level+1,pre);
			FILE *sv;
			sv=fopen("challenge.sav","w");
			fprintf(sv,"%d",pre);
			fclose(sv);
			print("\n恭喜您通过了该挑战~~~",13,6);
		}
		else print("\n很遗憾您没有通过该挑战",13,6);
		print("\n\n  按下ESC或者B键返回",14,6);
		while (1)
		{
			getinput();
			if (keyp("B")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
			#endif
		}
	}
	else if (level==2)  //挑战2
	{
		gotoxy(3,1);
		print("                      结    束                        \n",7,6);
		print("  共存活了",14,6);
		printf("\e[0;37m\e[46m %.2lf\e[0m",((double)clock()-stayt)/CLOCKS_PER_SEC);
		print("s,Stayer!\n",14,6);
		for (i=1;i<=PS;i++)
		{
			print(p[i].c,14,6); printf("\n");
			print("  分数：",14,6);
			int j,t=0;
			t=(int)(((double)clock()-stayt)/CLOCKS_PER_SEC*0.3);
			for (j=1;j<=30;j++) t+=p[i].kill[j]*stp[j].score;
			sum+=t;
			printf("\e[0;37m\e[46m  %d\e[0m\n",t);
			printf("\n");
		}
		sum/=PS;
		print("      总分数：",14,6);
		printf("\e[0;37m\e[46m  %d\e[0m\n",sum);
		print("      评级：",14,6);
		if (sum>=600)
		    print("王者归来!那个人又回来了!全服震惊!",2,6);
		else if (sum>=320)
		    print("一流的Stayer!令人惊艳的操作!",4,6);
		else if (sum>=120)
		    print("还算合格的初体验!成长令人期待!",14,6);
		else print("...不愧是您。再试亿次吧~",13,6);
		if (sum>=150)
		{
			pre=max(level+1,pre);
			FILE *sv;
			sv=fopen("challenge.sav","w");
			fprintf(sv,"%d",pre);
			fclose(sv);
			print("\n恭喜您通过了该挑战~~~",13,6);
		}
		else print("\n很遗憾您没有通过该挑战",13,6);
		print("\n\n  按下ESC或者B键返回",14,6);
		while (1)
		{
			getinput();
			if (keyp("B")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
			#endif
		}
	}
	else if (level==3)  //挑战3
	{
		gotoxy(3,1);
		print("                      结    束                        \n",7,6);
		print("  共存活了",14,6);
		printf("\e[0;37m\e[46m %.2lf\e[0m",((double)clock()-stayt)/CLOCKS_PER_SEC);
		print("s,Stayer!\n",14,6);
		for (i=1;i<=PS;i++)
		{
			print(p[i].c,14,6); printf("\n");
			print("  分数：",14,6);
			int j,t=0;
			t=(int)(((double)clock()-stayt)/CLOCKS_PER_SEC*0.3);
			for (j=1;j<=30;j++) t+=p[i].kill[j]*stp[j].score;
			sum+=t;
			printf("\e[0;37m\e[46m  %d\e[0m\n",t);
			printf("\n");
		}
		sum/=PS;
		print("      总分数：",14,6);
		printf("\e[0;37m\e[46m  %d\e[0m\n",sum);
		print("      评级：",14,6);
		if (sum>=450)
		    print("王者归来!那个人又回来了!全服震惊!",2,6);
		else if (sum>=250)
		    print("一流的Stayer!令人惊艳的操作!",4,6);
		else if (sum>=130)
		    print("还算合格的初体验!成长令人期待!",14,6);
		else print("...不愧是您。再试亿次吧~",13,6);
		if (sum>=160)
		{
			pre=max(level+1,pre);
			FILE *sv;
			sv=fopen("challenge.sav","w");
			fprintf(sv,"%d",pre);
			fclose(sv);
			print("\n恭喜您通过了该挑战~~~",13,6);
		}
		else print("\n很遗憾您没有通过该挑战",13,6);
		print("\n\n  按下ESC或者B键返回",14,6);
		while (1)
		{
			getinput();
			if (keyp("B")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_ESCAPE)<0) {clrscr(); return;}
			#endif
		}
	}
}

void levelinfo(int level)
{
	wait(200);
	clrscr();
	background();
	if (level==1)  //挑战1
	{
		while (1)
		{
    		#ifndef WIN
    		wait(20);
    		inbufn=0;
	    	#endif
			gotoxy(3,1);
			print("                    小 试 牛 刀                  ",7,6);
			gotoxy(5,1);
			print("  作为刚刚出道的新Stayer",14,6);
			gotoxy(6,1);
			print("  你接下来将要在一个有限的空间里尽可能活得更久",14,6);
			gotoxy(7,1);
			print("  毕竟是小试牛刀所以没什么好说的啦",14,6);
			gotoxy(8,1);
			print("  证明自己的实力吧！New Stayer！",14,6);
			gotoxy(9,1);
			print("  提示:先四处跑跑去找把抢",14,6);
			gotoxy(13,1);
			print("  按下回车或者E键继续~",14,6);
			getinput();
			if (keyp("E")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_RETURN)<0) {clrscr(); return;}
			#endif
		}	
	}
	if (level==2)  //挑战2
	{
		while (1)
		{
    		#ifndef WIN
    		wait(20);
    		inbufn=0;
	    	#endif
			gotoxy(3,1);
			print("                    初 露 锋 芒                   ",7,6);
			gotoxy(5,1);
			print("  有了上一次的经验",14,6);
			gotoxy(6,1);
			print("  接下来你就要大干一场了",14,6);
			gotoxy(7,1);
			print("  找到并摧毁地图中的所有的敌人水晶吧~",14,6);
			gotoxy(8,1);
			print("  证明自己的实力吧！Naive Stayer！",14,6);
			gotoxy(9,1);
			print("  提示:看看界面下方的Tips吧~",14,6);
			gotoxy(13,1);
			print("  按下回车或者E键继续~",14,6);
			getinput();
			if (keyp("E")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_RETURN)<0) {clrscr(); return;}
			#endif
		}	
	}
	if (level==3)  //挑战3
	{
		while (1)
		{
    		#ifndef WIN
    		wait(20);
    		inbufn=0;
	    	#endif
			gotoxy(3,1);
			print("                    什 么 是 Stay                   ",7,6);
			gotoxy(5,1);
			print("  这一次。",14,6);
			gotoxy(6,1);
			print("  你不仅要保护好自己",14,6);
			gotoxy(7,1);
			print("  更要保护好地图上的神圣水晶",14,6);
			gotoxy(8,1);
			print("  开始保护别人是成熟的标志",14,6);
			gotoxy(9,1);
			print("  Growing up! Stayer！",14,6);
			gotoxy(10,1);
			print("  提示：这一挑战的敌人将不再放水~",14,6);
			gotoxy(13,1);
			print("  按下回车或者E键继续~",14,6);
			getinput();
			if (keyp("E")) {clrscr(); return;}
			#ifdef WIN
			if (GetKeyState(VK_RETURN)<0) {clrscr(); return;}
			#endif
		}	
	}
}

void levelentry(int level)
{
	wait(200);
	clrscr();
	clock_t st=clock();
	int zz=1;
	char lev[6][75];
	strcpy(lev[0],"                      自由模式                        ");
	strcpy(lev[1],"                      挑 战 1                         ");
	strcpy(lev[2],"                      挑 战 2                         ");
	strcpy(lev[3],"                      挑 战 3                         ");
	strcpy(lev[4],"                      挑 战 4                         ");
	strcpy(lev[5],"                      挑 战 5                         ");
	char sel[5][75];
	strcpy(sel[0],"                                                      ");
	strcpy(sel[1],"                      独狼模式                        ");
	strcpy(sel[2],"                      基友乱战                        ");
	strcpy(sel[3],"                      返    回                        ");
	strcpy(sel[4],"                                                      ");
	int z=1;
	background();
	while (1)
	{
		#ifndef WIN
		wait(20);
		inbufn=0;
		#endif
		if ((MENUT*CLOCKS_PER_SEC/1000)+st<=clock())
		{
			zz=1; st=clock();
		}
		gotoxy(3,1);
		print(lev[level],7,6);
		gotoxy(9,1);
		print(sel[z-1],12,6);
		gotoxy(10,1);
		printf("\e[4m");
		print(sel[z],13,6);
		gotoxy(11,1);
		print(sel[z+1],12,6);
		getinput();
		if (zz&&keyp("W")&&(z>1)) zz=0,z--;
		if (zz&&keyp("S")&&(z<3)) zz=0,z++;
		if (keyp("B")) {wait(200); clrscr(); return;}
		if (keyp("E"))
		{
			if (z==1)
			{
				PS=1; stiinit(); stbinit(); stpinit(); mapload(level); playerinit(1,level); gamescreen(1,level);
				gameend(level); wait(200); clrscr(); return;
			}
			else if (z==2)
			{
				PS=2; stiinit(); stbinit(); stpinit(); mapload(level); playerinit(2,level); gamescreen(2,level);
				gameend(level); wait(200); clrscr(); return;
			}
			else if (z==3)
			{
				wait(200); clrscr(); return;
			}
		}
		#ifdef WIN
		if ((GetKeyState(VK_RETURN)<0)||(GetKeyState(VK_SPACE)<0))
		{
			if (z==1)
			{
				PS=1; stiinit(); stbinit(); stpinit(); mapload(level); playerinit(1,level); gamescreen(1,level);
				gameend(level); wait(200); clrscr(); return;
			}
			else if (z==2)
			{
				PS=2; stiinit(); stbinit(); stpinit(); mapload(level); playerinit(2,level); gamescreen(2,level);
				gameend(level); wait(200); clrscr(); return;
			}
			else if (z==3)
			{
				wait(200); clrscr(); return;
			}
		}
	    if (GetKeyState(VK_ESCAPE)<0) {wait(200); clrscr(); return;}
		#endif
	}
}
 
void challenge()
{
	wait(200);
	clrscr();
	clock_t st=clock();
	int zz=1;
	char sel[6][75];
	strcpy(sel[0],"                                                      ");
	strcpy(sel[1],"                      挑 战 1                         ");
	strcpy(sel[2],"                      挑 战 2                         ");
	strcpy(sel[3],"                      挑 战 3                         ");
	strcpy(sel[4],"                      返    回                        ");
	strcpy(sel[5],"                                                      ");
	int z=1;
	FILE *sv;  //读取挑战完成进度
	if ((sv=fopen("challenge.sav","r"))!=NULL)
	{
		fscanf(sv,"%d",&pre);
		fclose(sv);
	}
	else
	{
		pre=1;
		sv=fopen("challenge.sav","w");
		fprintf(sv,"%d",pre);
		fclose(sv);
	}
	background();
	while (1)
	{
		#ifndef WIN
		wait(20);
		inbufn=0;
		#endif
		if ((MENUT*CLOCKS_PER_SEC/1000)+st<=clock())
		{
			zz=1; st=clock();
		}
		gotoxy(3,1);
		print("                      挑    战                        ",7,6);
		gotoxy(9,1);
		if (z-1<=pre)
			print(sel[z-1],12,6);
		else
			print(sel[z-1],7,6);
		gotoxy(10,1);
		printf("\e[4m");
		if ((z<=pre)||(z>3))
			print(sel[z],13,6);
		else
			print(sel[z],14,6);
		gotoxy(11,1);
		if ((z+1<=pre)||(z+1>3))
			print(sel[z+1],12,6);
		else
			print(sel[z+1],7,6);
		getinput();
		if (zz&&keyp("W")&&(z>1)) zz=0,z--;
		if (zz&&keyp("S")&&(z<4)) zz=0,z++;
		if (keyp("B")) {wait(200); clrscr(); return;}
		if (keyp("E")&&((z>3)||(z<=pre)))
		{
			if (z!=4)
			{
				levelinfo(z); levelentry(z); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==4)
			{
				wait(200); clrscr(); return;
			}
		}
		#ifdef WIN
		if (((GetKeyState(VK_RETURN)<0)||(GetKeyState(VK_SPACE)<0))&&((z>3)||(z<=pre)))
		{
			if (z!=4)
			{
				levelinfo(z); levelentry(z); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==4)
			{
				wait(200); clrscr(); return;
			}
		}
	    if (GetKeyState(VK_ESCAPE)<0) {wait(200); clrscr(); return;}
		#endif
	}
}
 
void about()
{	
	clrscr();
	background();
	while (1)
	{
		#ifndef WIN
		wait(20);
		inbufn=0;
		#endif
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
		if (keyp("B")) {clrscr(); return;}
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
		#ifndef WIN
		wait(20);
		inbufn=0;
		#endif
		gotoxy(3,1);
		print("                      帮    助                        ",7,6);
		gotoxy(5,1);
		print("操作说明：",14,6);
		gotoxy(6,1);
		print("玩家1：",14,6);
		gotoxy(7,1);
		print("移动:WASD 疾跑:X 捡起&丢下:R 攻击:TFGH",14,6);
		gotoxy(8,1);
		if (BIGKEYBOARD)
		{
			print("玩家2：(其中数字为小键盘)",14,6);
			gotoxy(9,1);
			print("移动：↑←↓→ 疾跑：1 捡起&丢下:7 攻击:8456",14,6);
		}
		else
		{
			print("玩家2：",14,6);
			gotoxy(9,1);
			print("移动：↑←↓→ 疾跑：RCTRL 捡起&丢下:[ 攻击:pl;'",14,6);
		}
		gotoxy(10,1);
		print("界面说明：",14,6);
		gotoxy(11,1);
		print("界面头行显示人物血量和氧气值",14,6);
		gotoxy(12,1);
		print("地图下方为 人物名称 装备:弹药数 地块说明，再下方为消息",11,6);
		gotoxy(13,1);
		print("图标说明：",11,6);
		gotoxy(14,1);
		print("玩家:デ 敌人:バ 护卫:ㄐ 箱子:ロ 黑暗水晶:※",11,6);
		gotoxy(15,1);
		print("游戏基本规则：活下去！同时尽可能完成相应的任务。",9,6);
		getinput();
		if (keyp("B")) {clrscr(); return;}
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
		#ifndef WIN
		wait(20);
		inbufn=0;
		#endif
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
		if (zz&&keyp("W")&&(z>1)) zz=0,z--;
		if (zz&&keyp("S")&&(z<5)) zz=0,z++;
		if (keyp("E"))
		{
			if (z==1)
			{
				challenge(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==2)
			{
				levelentry(0); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
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
				challenge(); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
			}
			else if (z==2)
			{
				levelentry(0); background(); gotoxy(15,1); print(tips[rand()%tipn],6,6); wait(200);
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
 
void tipsinit()
{
	tipn=6; //提示信息数
	strcpy(tips[0],"      Tips:自由模式没有敌人？按c和方向键试试~");
	strcpy(tips[1],"      Tips:嫌子弹不够？为什么不找开枪的人要呢~");
	strcpy(tips[2],"      Tips:挑战模式没有武器？往左上角跑跑~");
	strcpy(tips[3],"      Tips:想要更炫酷的道具？关注一下箱子吧~");
	strcpy(tips[4],"      Tips:温馨提示:不要在黑暗水晶附近聚集敌人~");
	strcpy(tips[5],"      Tips:据说有一把刀能够轻松乱杀一切~");
}

void main()
{
#ifdef WIN
	system("cls"); HideCursor(); system("mode con cols=54 lines=16"); SetConsoleTitle("Stay Longer");
#endif
	if ((fp=fopen("setttings.ini","r"))!=NULL)
	{
		fscanf(fp,"%d\n%d\n%d",&BIGKEYBOARD,&DDC,&DT);
		fclose(fp);
	}
	else
	{
		fp=fopen("setttings.ini","w");
		fprintf(fp,"%d      //是否使用数字键盘\n%d      //部分GBK字符是否双重显示\n%d      //绘制延迟，单位ms",BIGKEYBOARD,DDC,DT);
		fclose(fp);
	}
	printf("\e[?25l");
	srand((unsigned int)time(NULL));
	tipsinit();
	menu();
//	test();
}