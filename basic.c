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
#define PS 2    //玩家数量
#define GAMETYPE  //游戏类型
 
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

block *map[MX+2][MY+2];
int flor[MX+2][MY+2];
block *iflor[MX+2][MY+2];
player *liv[MX+2][MY+2];
player p[OBJMAX];
int pn;  //玩家和ai数量
int fps,fpsf;
clock_t fpst,dpst,ppst,opst;
 
void playerinit()
{
	int i;
	pn=2;
	//p[0].id=0;p[0].sx=p[0].sy=1;
	p[0]=stp[0];
	for (i=1;i<=PS;i++)
	{
		p[i]=stp[1];
/*		p[i].id=1;p[i].fc=i-1;
		p[i].hp=p[i].fd=p[i].wt=p[i].og=100;
		p[i].tol=&sti[0];
		p[i].eqp=0;*/
		p[i].at=p[i].mt=p[i].ot=0;
		p[i].sx=p[i].sy=1;
		p[i].vx=p[i].vy=0;
		p[i].x=p[i].y=9+i;
		p[i].qut=0;
		p[i].own=&p[i];
//		p[i].spd=1;
		strcpy(p[i].msg[1],"~~");
		strcpy(p[i].msg[2],"~~");
	}
	strcpy(p[1].c,"玩家1");	strcpy(p[2].c,"玩家2");
}
 
void spawn(int id,double xx,double yy)  
{
	pn++;
	p[pn]=stp[id];
	p[pn].x=xx;
	p[pn].y=yy;
	p[pn].vx=p[pn].vy=0;
	p[pn].at=p[pn].mt=p[pn].ot=0;
	p[pn].sx=p[pn].sy=1;
	p[pn].qut=0;
	p[pn].own=&p[pn];
}

void addmsg(player *q,char *ss)
{
	strcpy(q->msg[2],q->msg[1]);
	strcpy(q->msg[1],ss);
}

void mapload()
{
	int i,j;
	for (i=1;i<=MX;i++)
	    for (j=1;j<=MY;j++)
	    {
	    	int t=rand()%6+1;
	    	flor[i][j]=t;
	        map[i][j]=&stb[1];
	        iflor[i][j]=&stb[1];
	        liv[i][j]=&p[0];
	    }
	    
	iflor[8][8]=iflor[7][8]=&stb[71];
	iflor[9][10]=&stb[72];
	iflor[7][10]=&stb[73];
	
	for (i=0;i<=MX+1;i++)
	{
		map[0][i]=map[MX+1][i]=map[i][0]=map[i][MY+1]=&stb[2];
		liv[0][i]=liv[MX+1][i]=liv[i][0]=liv[i][MY+1]=&p[0];	
	}
}

#include "input.h"
 
void draw(player *q,int xx,int yy)
{
	if (q->id>2) return;
	int i,j,k,t;
	gotoxy(yy,xx);
	if (q->hp<=-1958)
		printf("很遗憾。你挂了！");
	else
		printf("HP:%d OG:%d      ",q->hp,q->og);
	gotoxy(yy,xx+1);
	for (i=q->sx;i<=q->sx+10;i++)
	{
		for (j=q->sy;j<=q->sy+10;j++)
		{
			
			if (liv[i][j]->id>0)
			{
				if (iflor[i][j]->id>1)
					livprint(liv[i][j],7);
				else
					livprint(liv[i][j],flor[i][j]);
			}
			else
			{
				if (iflor[i][j]->id>1)
		        	print(iflor[i][j]->c,iflor[i][j]->fc,flor[i][j]);
				else
					print(map[i][j]->c,map[i][j]->fc,flor[i][j]);
			}
		}
		gotoxy(yy,xx+i-q->sx+2);
	}
	printf("%s %s ",q->c,q->tol->c);
	if (iflor[(int)q->x][(int)q->y]->id==1)
		print("空地",11,0);
	else
		print(sti[iflor[(int)q->x][(int)q->y]->id-70].c,11,0);
	gotoxy(yy,xx+13);
	print(q->msg[1],8,0);
	printf("      ");
	gotoxy(yy,xx+14);
	print(q->msg[2],9,0);
	printf("      ");
	gotoxy(yy,xx+15);
	printf("%d %d",inbufn,pn);
	printf(" fps:%d  %.2lf",fps,q->y);
}

int ifoutmap(player *q)
{
	if (q->x<1) return 1;if (q->x>MX+1) return 1;
	if (q->y<1) return 1;if (q->y>MY+1) return 1;
	return 0;	
}

void backinmap(player *q)
{
	if (q->x+q->vx<1)
	{
		q->x=1; q->vx*=-EK;
	}
	if (q->x+q->vx>MX+1)
	{
		q->x=MX; q->vx*=-EK;
	}
	if (q->y+q->vy<1)
	{
		q->y=1; q->vy*=-EK;
	}
	if (q->y+q->vy>MY+1)
	{
		q->y=MY; q->vy*=-EK;
	}
}

void vlimit(player *q)
{
	if ((q->id<=20)&&(q->vx>VMAX)) q->vx=VMAX;
	if ((q->id<=20)&&(q->vx<-VMAX)) q->vx=-VMAX;
	if ((q->id<=20)&&(q->vy>VMAX)) q->vy=VMAX;
	if ((q->id<=20)&&(q->vy<-VMAX)) q->vy=-VMAX;
}

void maprefresh()
{
	int i,j,t;
	for (i=1;i<=MX;i++)
	    for (j=1;j<=MY;j++)
	    {
	    	if (liv[i][j]->id)
	    	{
	    		map[i][j]=&stb[1];
	    		liv[i][j]=&p[0];
	    	}
	    }
	for (i=1;i<=pn;i++)  //先刷新ai
	{
		if (p[i].id<=20) continue;
		if (map[(int)(p[i].x)][(int)(p[i].y)]->csh==0) continue;
		map[(int)(p[i].x)][(int)(p[i].y)]=&stb[p[i].id+20];
		liv[(int)(p[i].x)][(int)(p[i].y)]=&p[i];
	}
	for (i=1;i<=pn;i++)  //后刷新玩家
	{
		if (p[i].id>20) continue;
		map[(int)(p[i].x)][(int)(p[i].y)]=&stb[p[i].id+20];
		liv[(int)(p[i].x)][(int)(p[i].y)]=&p[i];
	}
	for (i=1;i<=pn;i++)
	{
		if (p[i].id>20) continue;
		if (((int)(p[i].x)-5>=1)&&((int)(p[i].x)+5<=MX))
			p[i].sx=(int)(p[i].x)-5;
		else if ((int)(p[i].x)-5<1)
			p[i].sx=1;
		else p[i].sx=MX-10;
		if (((int)(p[i].y)-5>=1)&&((int)(p[i].y)+5<=MY))
			p[i].sy=(int)(p[i].y)-5;
		else if ((int)(p[i].y)-5<1)
			p[i].sy=1;
		else p[i].sy=MY-10;
	}
}

#include "gamecore.h"

void physics()
{
	int i;
	for (i=1;i<=pn;i++)
	{
		if (p[i].id>20) continue;
		int tt=1;
		while ((p[i].vx/tt>PM)||(p[i].vy/tt>PM)) tt++;
		int j;
		p[i].vx/=tt; p[i].vy/=tt;
		for (j=1;j<=tt;j++)
		{
			backinmap(&p[i]);
			player *pp;
			pp=&p[i];
			if ((liv[(int)(pp->x+pp->vx)][(int)(pp->y+pp->vy)]!=pp)&&(map[(int)(pp->x+pp->vx)][(int)(pp->y+pp->vy)]->csh==0))
			{

				if ((p[i].id==4)&&(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]!=&p[i]))  //手雷特判
				{
					if (!liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->id) continue;
					if (!liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->hp)
						liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->own=p[i].own;
					liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->hp-=(int)(p[i].eqp*(getv(&p[i])/9.0));

					#ifdef WEAKMSG
					char ts[34];
					strcpy(ts,"你打了");
					strcat(ts,liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->c);
					addmsg(p[i].own,ts);
					strcpy(ts,p[i].own->c);
					strcat(ts,"打了你");
					addmsg(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)],ts);
					#endif
				}

				if ((liv[(int)(pp->x)][(int)(pp->y+pp->vy)]!=pp)&&(map[(int)(pp->x)][(int)(pp->y+pp->vy)]->csh==0)&&(liv[(int)(pp->x+pp->vx)][(int)(pp->y)]!=pp)&&(map[(int)(pp->x+pp->vx)][(int)(pp->y)]->csh==0))
				{
					liv[(int)(pp->x)][(int)(pp->y+pp->vy)]->vy+=tt*pp->vy*EK;
					liv[(int)(pp->x+pp->vx)][(int)(pp->y)]->vx+=tt*pp->vx*EK;
					pp->vx*=-EK; pp->vy*=-EK;  //??
				}
				else
				if ((liv[(int)(pp->x)][(int)(pp->y+pp->vy)]!=pp)&&(map[(int)(pp->x)][(int)(pp->y+pp->vy)]->csh==0))
				{
					liv[(int)(pp->x)][(int)(pp->y+pp->vy)]->vy+=tt*pp->vy*EK;
					pp->vy*=-EK;
				}
				else
				{
					liv[(int)(pp->x+pp->vx)][(int)(pp->y)]->vx+=tt*pp->vx*EK;
					pp->vx*=-EK;
				}
			}
			else
			{
				pp->x+=pp->vx; pp->y+=pp->vy;
			}
		}
		p[i].vx*=tt; p[i].vy*=tt;
		p[i].vx*=p[i].miu; p[i].vy*=p[i].miu;
	}
}

void oxygen()  //氧气和其他生物事件判定
{
	int i;
	for (i=1;i<=pn;i++)  //??
	{
		if (p[i].id==1)  //玩家
		{
			p[i].og+=15+rand()%11;
			if (p[i].og>MOG) p[i].og=MOG;
			if ((p[i].og<=0)&&(!p[i].qut))
			{
				char ts[34];
				strcpy(ts,"你需要氧气！");
				addmsg(&p[i],ts);
				p[i].own=&p[i];
				p[i].hp-=OGDMG;
			}
		}
		if (p[i].id==4)  //手雷
		{
			p[i].hp--;
		}
	}
}

void playerlogic()
{
	int i;
	for (i=1;i<=pn;i++)
	{
		if (p[i].id<=20) backinmap(&p[i]);
		vlimit(&p[i]);

		if ((p[i].hp<=0)&&(p[i].id==1))  //玩家死亡
		{
			p[i].hp=-1958;

			if (!p[i].qut)
			{
				p[i].qut=1;
				char ts[34];
				strcpy(ts,p[i].own->c);
				strcat(ts,"击杀了你！");
				addmsg(&p[i],ts);
				strcpy(ts,"你击杀了");
				strcat(ts,p[i].c);
				strcat(ts,"！");
				addmsg(p[i].own,ts);
				strcpy(ts,p[i].own->c);
				strcat(ts,"击杀了");
				strcat(ts,p[i].c);
				strcat(ts,"！");
				int j;
				for (j=1;j<=pn;j++)
					if ((p[j].id==1)&&(j!=i)&&(&p[j]!=p[i].own)) addmsg(&p[j],ts);
			}

			continue;
		}
		if ((p[i].hp<=0)&&(p[i].id==4))  //手雷死亡
		{
			p[i].qut=1;
			spawn(22,p[i].x-1,p[i].y);
			p[pn].vx=-1; p[pn].vy=0;
			spawn(22,p[i].x,p[i].y-1);
			p[pn].vx=0; p[pn].vy=-1;
			spawn(22,p[i].x+1,p[i].y);
			p[pn].vx=1; p[pn].vy=0;
			spawn(22,p[i].x,p[i].y+1);
			p[pn].vx=0; p[pn].vy=1;

			spawn(22,p[i].x-1,p[i].y-1);
			p[pn].vx=-1; p[pn].vy=-1;
			spawn(22,p[i].x-1,p[i].y+1);
			p[pn].vx=-1; p[pn].vy=1;
			spawn(22,p[i].x+1,p[i].y-1);
			p[pn].vx=1; p[pn].vy=-1;
			spawn(22,p[i].x+1,p[i].y+1);
			p[pn].vx=1; p[pn].vy=1;
			p[i]=p[pn]; p[pn].id=404; pn--;  //?

#ifdef WEAKMSG
				char ts[34];
				strcpy(ts,"一颗手雷爆炸了");
				int j;
				for (j=1;j<=pn;j++)
					if (p[j].id==1) addmsg(&p[j],ts);

#endif

			continue;
		}
		if (p[i].hp<=0)  //其他死亡
		{

			if ((p[i].id<=20)&&(!p[i].qut))
			{
				p[i].qut=1;
				char ts[34];
				strcpy(ts,p[i].own->c);
				strcat(ts,"击杀了你！");
				addmsg(&p[i],ts);
				strcpy(ts,"你击杀了");
				strcat(ts,p[i].c);
				strcat(ts,"！");
				addmsg(p[i].own,ts);
			}

			p[i]=p[pn]; p[pn].id=404; pn--;
			continue;
		}

		if (p[i].id==1)  //玩家
		{

		}

		if (p[i].id==2)  //敌人
		{
			ai2(&p[i]);
		}
		if (p[i].id==21)  //子弹
		{
			if (ifoutmap(&p[i]))
			{
				p[i].hp=0;
				continue;
			}
			if (map[(int)p[i].x][(int)p[i].y]->csh==0)
			{
				p[i].hp=0;
				if (!liv[(int)p[i].x][(int)p[i].y]->id) continue;
				if (!liv[(int)p[i].x][(int)p[i].y]->qut)
					liv[(int)p[i].x][(int)p[i].y]->own=p[i].own;
				liv[(int)p[i].x][(int)p[i].y]->hp-=p[i].eqp;
				liv[(int)p[i].x][(int)p[i].y]->vy+=BUB*p[i].sy;
				liv[(int)p[i].x][(int)p[i].y]->vx+=BUB*p[i].sx;

#ifdef WEAKMSG
				char ts[34];
				strcpy(ts,"你打了");
				strcat(ts,liv[(int)p[i].x][(int)p[i].y]->c);
				addmsg(p[i].own,ts);
				strcpy(ts,p[i].own->c);
				strcat(ts,"打了你");
				addmsg(liv[(int)p[i].x][(int)p[i].y],ts);
#endif

				continue;
			}
			if ((ANT*CLOCKS_PER_SEC/1000)+p[i].mt>clock()) continue;
			p[i].mt=clock();
			p[i].x+=p[i].spd*p[i].sx; p[i].y+=p[i].spd*p[i].sy;
		}
		if (p[i].id==4)  //手雷
		{
			if (ifoutmap(&p[i]))
			{
				p[i].hp=0;
				continue;
			}
			continue;
		}
		if (p[i].id==22)  //冲击波???
		{
			if (ifoutmap(&p[i]))
			{
				p[i].hp=0;
				continue;
			}
			if (map[(int)p[i].x][(int)p[i].y]->csh==0)
			{
				p[i].hp=0;
				if (!liv[(int)p[i].x][(int)p[i].y]->id) continue;
				if (!liv[(int)p[i].x][(int)p[i].y]->qut)
					liv[(int)p[i].x][(int)p[i].y]->own=p[i].own;
				liv[(int)p[i].x][(int)p[i].y]->hp-=p[i].eqp;
				liv[(int)p[i].x][(int)p[i].y]->vy+=BLB*p[i].vy;
				liv[(int)p[i].x][(int)p[i].y]->vx+=BLB*p[i].vx;

#ifdef WEAKMSG
				char ts[34];
				strcpy(ts,"你打了");
				strcat(ts,liv[(int)p[i].x][(int)p[i].y]->c);
				addmsg(p[i].own,ts);
				strcpy(ts,p[i].own->c);
				strcat(ts,"打了你");
				addmsg(liv[(int)p[i].x][(int)p[i].y],ts);
#endif

				continue;
			}
			if ((BNT*CLOCKS_PER_SEC/1000)+p[i].mt>clock()) continue;
			p[i].mt=clock();
			p[i].hp--;
			spawn(22,p[i].x+p[i].vx,p[i].y+p[i].vy);  //冲击波基础扩散
			p[pn].hp=p[i].hp;
			p[pn].vx=p[i].vx; p[pn].vy=p[i].vy;
			if ((p[i].vy!=0)&&(liv[(int)(p[i].x-1)][(int)p[i].y]->id!=22)&&(liv[(int)(p[i].x-1)][(int)(p[i].y+p[i].vy)]->id!=2))  //冲击波扩展扩散
			{
				spawn(22,p[i].x-1,p[i].y+p[i].vy);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy;			
			}
			if ((p[i].vy!=0)&&(liv[(int)(p[i].x+1)][(int)p[i].y]->id!=22)&&(liv[(int)(p[i].x-1)][(int)(p[i].y+p[i].vy)]->id!=2))
			{
				spawn(22,p[i].x+1,p[i].y+p[i].vy);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy;			
			}
			if ((p[i].vx!=0)&&(liv[(int)p[i].x][(int)(p[i].y-1)]->id!=22)&&(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y-1)]->id!=2))
			{
				spawn(22,p[i].x+p[i].vx,p[i].y-1);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy;			
			}
			if ((p[i].vx!=0)&&(liv[(int)p[i].x][(int)(p[i].y+1)]->id!=22)&&(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+1)]->id!=2))
			{
				spawn(22,p[i].x+p[i].vx,p[i].y+1);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy;			
			}
		}
	}
}
 
void controldbg()
{
	if (keyp("w")&&(p[0].sx>1)) p[0].sx-=1;
	if (keyp("a")&&(p[0].sy>1)) p[0].sy-=1;
	if (keyp("s")&&(p[0].sx<MX-10)) p[0].sx+=1;
	if (keyp("d")&&(p[0].sy<MY-10)) p[0].sy+=1;
}
 
clock_t st=0;
 
void control1(player *q)
{
	if (q->qut==1) return;

	int z=0;  //???
	if ((MT*CLOCKS_PER_SEC/1000)+st<=clock())
	{
		z=1; st=clock();
	}

#ifdef WIN
	if ((keyp("w"))&&(GetKeyState(VK_SHIFT)<0)&&(q->og>RUNOG)) move(q,-3,0),q->og-=2+rand()%6;
	if ((keyp("a"))&&(GetKeyState(VK_SHIFT)<0)&&(q->og>RUNOG)) move(q,0,-3),q->og-=2+rand()%6;
	if ((keyp("s"))&&(GetKeyState(VK_SHIFT)<0)&&(q->og>RUNOG)) move(q,3,0),q->og-=2+rand()%6;
	if ((keyp("d"))&&(GetKeyState(VK_SHIFT)<0)&&(q->og>RUNOG)) move(q,0,3),q->og-=2+rand()%6;
#endif

	if (keyp("w")&&(keyp("a"))) move(q,-sqrt(2)/2,-sqrt(2)/2);
	if (keyp("w")&&(keyp("d"))) move(q,-sqrt(2)/2,sqrt(2)/2);
	if (keyp("s")&&(keyp("a"))) move(q,sqrt(2)/2,-sqrt(2)/2);
	if (keyp("s")&&(keyp("d"))) move(q,sqrt(2)/2,sqrt(2)/2);
	if (keyp("w")) move(q,-1,0);
	if (keyp("a")) move(q,0,-1);
	if (keyp("s")) move(q,1,0);
	if (keyp("d")) move(q,0,1);
	if (keyp("q")&&q->tol->id&&(iflor[(int)(q->x)][(int)(q->y)]->id==1))
	{
		iflor[(int)(q->x)][(int)(q->y)]=&stb[q->tol->id+70];
		q->tol=&sti[0];
	}
	if (keyp("e")&&(q->tol->id==0)&&(iflor[(int)(q->x)][(int)(q->y)]->id>70))
	{
		q->tol=&sti[iflor[(int)(q->x)][(int)(q->y)]->id-70];
		iflor[(int)(q->x)][(int)(q->y)]=&stb[1];
	}
	if (keyp("t")) attack(q,-1,0);
	if (keyp("f")) attack(q,0,-1);
	if (keyp("g")) attack(q,1,0);
	if (keyp("h")) attack(q,0,1);
	if (z&&keyp("c")) spawn(2,rand()%60+21,rand()%60+21);
}
 
void control2(player *q)
{
	if (q->qut==1) return;
	if (keyp("i")) move(q,-1,0);
	if (keyp("j")) move(q,0,-1);
	if (keyp("k")) move(q,1,0);
	if (keyp("l")) move(q,0,1);
}
 
void gamescreen()
{
	inbufn=0; opst=ppst=dpst=fpst=clock(); fpsf=fps=0;
	while (1)
	{

		playerlogic();
			
		maprefresh();

		if (fpst+1000*CLOCKS_PER_SEC/1000<=clock())
		{
			fps=fpsf; fpsf=0; fpst=clock();
			inbufn=0;
		}
		
		if (ppst+PT*CLOCKS_PER_SEC/1000<=clock())
		{
			ppst=clock();
			physics();
		}

		if (opst+OT*CLOCKS_PER_SEC/1000<=clock())
		{
			opst=clock();
			oxygen();
		}

		if (dpst+DT*CLOCKS_PER_SEC/1000<=clock())
		{
			dpst=clock(); fpsf++;
			
			
			draw(&p[1],1,1);
/*			if (pn>=3)
			{
				draw(&p[3],1,23);
			}*/
			draw(&p[2],1,23);
	
		}
		getinput();
		
//		controldbg();
		control1(&p[1]);
		control2(&p[2]);
		
		inputdbg();
		gotoxy(1,1);
	}
}
 
void main()
{
#ifdef WIN
	system("cls"); HideCursor();
#endif
	srand((unsigned int)time(NULL));
//	test();
	stiinit(); stbinit(); stpinit(); mapload(); playerinit(); gamescreen();
}