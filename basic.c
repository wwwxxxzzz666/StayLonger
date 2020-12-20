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
#define PS 2    //玩家数量
 
#define MT 100  //基础移动冷却时间，单位ms
#define ANT 10  //子弹等动态活动运动基础单位时间，单位ms
#define DT 1  //绘制延迟，单位ms
#define PT 10  //物理计算单位时间，单位ms

#define MIU 0.33  //阻力常数
#define EK 1

block *map[MX+2][MY+2];
int flor[MX+2][MY+2];
block *iflor[MX+2][MY+2];
player *liv[MX+2][MY+2];
player p[666];
int pn;  //玩家和ai数量
int fps,fpsf;
clock_t fpst,dpst,ppst;
 
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
		p[i].at=p[i].mt=p[i].dt=0;
		p[i].sx=p[i].sy=1;
		p[i].vx=p[i].vy=0;
		p[i].x=p[i].y=9+i;
//		p[i].spd=1;
	}
}
 
void spawn(int id)
{
	pn++;
	p[pn]=stp[id];
	p[pn].x=rand()%60+21;
	p[pn].y=rand()%60+21;
	p[pn].vx=p[pn].vy=0;
	p[pn].at=p[pn].mt=p[pn].dt=0;
	p[pn].sx=p[pn].sy=1;
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
	if (q->hp==-1958) printf("很遗憾。你挂了！"); else printf("HP:%d      ",q->hp);
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

/*		    if ((iflor[i][j]->id>1)&&(liv[i][j]->id>0))
		        print(map[i][j]->c,map[i][j]->fc,7);
		    else
			if (iflor[i][j]->id>1)
		        print(iflor[i][j]->c,iflor[i][j]->fc,flor[i][j]);
			else
				print(map[i][j]->c,map[i][j]->fc,flor[i][j]);*/
		}
		gotoxy(yy,xx+i-q->sx+2);
	}
	printf("%s",q->tol->c);
	printf("%d %d",inbufn,pn);
	printf(" fps:%d  %.2lf",fps,q->y);
}

int ifoutmap(player *q)
{
	if (q->x<1) return 1;if (q->x>MX) return 1;
	if (q->y<1) return 1;if (q->y>MY) return 1;
	return 0;	
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
		if (p[i].id<=2) continue;
		if (map[(int)(p[i].x)][(int)(p[i].y)]->csh==0) continue;
		map[(int)(p[i].x)][(int)(p[i].y)]=&stb[p[i].id+20];
		liv[(int)(p[i].x)][(int)(p[i].y)]=&p[i];
	}
	for (i=1;i<=pn;i++)  //后刷新玩家
	{
		if (p[i].id>2) continue;
		map[(int)(p[i].x)][(int)(p[i].y)]=&stb[p[i].id+20];
		liv[(int)(p[i].x)][(int)(p[i].y)]=&p[i];
	}
	for (i=1;i<=pn;i++)
	{
		if (p[i].id>2) continue;
		if (((int)(p[i].x)-5>=1)&&((int)(p[i].x)+5<=MX)) p[i].sx=(int)(p[i].x)-5;
		if (((int)(p[i].y)-5>=1)&&((int)(p[i].y)+5<=MY)) p[i].sy=(int)(p[i].y)-5;
	}
}
 
int sgnx(player *p1,player *p2)  //p2相对p1的x方位sgn
{
	if ((int)(p1->x)==(int)(p2->x)) return 0;
	if ((int)(p1->x)>(int)(p2->x)) return -1;
	return 1;
}
 
int sgny(player *p1,player *p2)  //p2相对p1的y方位sgn
{
	if ((int)(p1->y)==(int)(p2->y)) return 0;
	if ((int)(p1->y)>(int)(p2->y)) return -1;
	return 1;
}
 
int qdisx(player *p1,player *p2)  //切比雪夫x方位距离
{
	return abs((int)(p1->x)-(int)(p2->x));
}
 
int qdisy(player *p1,player *p2)  //切比雪夫y方位距离
{
	return abs((int)(p1->y)-(int)(p2->y));
}
 
int qdism(player *p1,player *p2)  //切比雪夫距离投影分离量最小值
{
	return min(qdisx(p1,p2),qdisy(p1,p2));
}

void movev(player *q,int xx,int yy)
{
	if ((MT*CLOCKS_PER_SEC/1000)+q->mt>clock()) return;
	q->mt=clock();
	q->vx+=xx; q->vy+=yy;
}

void move(player *q,int xx,int yy)
{
	if ((MT*CLOCKS_PER_SEC/1000)+q->mt>clock()) return;
	q->mt=clock();
	q->vx+=xx*q->spd; q->vy+=yy*q->spd;
}

void physics()
{
	int i;
	for (i=1;i<=pn;i++)
	{
		if (p[i].id>2) continue;
		player *pp;
		pp=&p[i];
		if ((liv[(int)(pp->x+pp->vx)][(int)(pp->y+pp->vy)]!=pp)&&(map[(int)(pp->x+pp->vx)][(int)(pp->y+pp->vy)]->csh==0))
		{
			if ((liv[(int)(pp->x)][(int)(pp->y+pp->vy)]!=pp)&&(map[(int)(pp->x)][(int)(pp->y+pp->vy)]->csh==0)&&(liv[(int)(pp->x+pp->vx)][(int)(pp->y)]!=pp)&&(map[(int)(pp->x+pp->vx)][(int)(pp->y)]->csh==0))
			{
				liv[(int)(pp->x)][(int)(pp->y+pp->vy)]->vy+=pp->vy*EK;
				liv[(int)(pp->x+pp->vx)][(int)(pp->y)]->vx+=pp->vx*EK;
				pp->vx*=-EK; pp->vy*=-EK;  //??
			}
			else
			if ((liv[(int)(pp->x)][(int)(pp->y+pp->vy)]!=pp)&&(map[(int)(pp->x)][(int)(pp->y+pp->vy)]->csh==0))
			{
				liv[(int)(pp->x)][(int)(pp->y+pp->vy)]->vy+=pp->vy*EK;
				pp->vy*=-EK;
			}
			else
			{
				liv[(int)(pp->x+pp->vx)][(int)(pp->y)]->vx+=pp->vx*EK;
				pp->vx*=-EK;
			}
			pp->vx*=MIU; pp->vy*=MIU;
		}
		else
		{
			pp->x+=pp->vx; pp->y+=pp->vy;
			pp->vx*=MIU; pp->vy*=MIU;
		}
	}
}
 
void attack(player *pp,int xx,int yy)
{
	if ((pp->tol->ft*CLOCKS_PER_SEC/1000)+pp->at>clock()) return;
	if (((int)(pp->x)+xx<1)||((int)(pp->x)+xx>MX)) return;
	if (((int)(pp->y)+yy<1)||((int)(pp->y)+yy>MY)) return;
	pp->at=clock();
	if (pp->tol->id==0)  //双手
	{
		liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->hp-=pp->tol->dmg; //!!!
	}
	if (pp->tol->id==1)  //小枪
	{
		pn++;
		p[pn]=stp[21];p[pn].sx=xx;p[pn].sy=yy;p[pn].eqp+=pp->tol->dmg;
		p[pn].x=pp->x+xx;p[pn].y=pp->y+yy;
	}
}
 
void ai2(player *q)
{
	player *tar;
	tar=&p[0];  //??
	int dmin=1<<7;
	int i,j;
	
	for (i=1;i<=pn;i++)  //找目标
	{
		if ((q==&p[i])||(p[i].id>1)) continue;
		if (qdism(q,&p[i])<dmin)
		{
			dmin=qdism(q,&p[i]);
			tar=&p[i];
		}
	}

	if (tar==&p[0]) return;

	if (qdism(q,tar)==0)  //行为
	{
		attack(q,sgnx(q,tar),sgny(q,tar));
		int t=rand()%3-1;
		int tt=rand()%3-1;
		if (qdisx(q,tar)==0)
		{
			move(q,t,sgny(q,tar)+tt);
		}
		else
		{
			move(q,sgnx(q,tar)+tt,t);
		}
	}
	else
	{
		if (qdisx(q,tar)<=qdisy(q,tar))
		{
			move(q,sgnx(q,tar),0);
		}
		else
		{
			move(q,0,sgny(q,tar));
		}
	}
	
}
 
void playerlogic()
{
	int i;
	for (i=1;i<=pn;i++)
	{
		if ((p[i].hp<=0)&&(p[i].id==1))
		{
			p[i].hp=-1958; continue;
		}
		if (p[i].hp<=0)
		{
			p[i]=p[pn]; p[pn].id=404; pn--; continue;
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
				liv[(int)p[i].x][(int)p[i].y]->hp-=p[i].eqp;
				p[i].hp=0;
				continue;
			}
			if ((ANT*CLOCKS_PER_SEC/1000)+p[i].mt>clock()) continue;
			p[i].mt=clock();
			p[i].x+=p[i].spd*p[i].sx; p[i].y+=p[i].spd*p[i].sy;
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
	if (q->hp==-1958) return;

	int z=0;  //???
	if ((MT*CLOCKS_PER_SEC/1000)+st<=clock())
	{
		z=1; st=clock();
	}
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
	if (z&&keyp("c")) spawn(2);
}
 
void control2(player *q)
{
	if (q->hp==-1958) return;
	if (keyp("i")) move(q,-1,0);
	if (keyp("j")) move(q,0,-1);
	if (keyp("k")) move(q,1,0);
	if (keyp("l")) move(q,0,1);
}
 
void gamescreen()
{
	inbufn=0; ppst=dpst=fpst=clock(); fpsf=fps=0;
	while (1)
	{
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
		
		playerlogic();
			
		maprefresh();
		
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