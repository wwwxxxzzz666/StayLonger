void spawn(int id,double xx,double yy)
{
	pn++;
	p[pn]=stp[id];
	p[pn].x=xx;
	p[pn].y=yy;
	p[pn].vx=p[pn].vy=0;
	p[pn].at=p[pn].mt=p[pn].ot=p[pn].bt=p[pn].swt=0;
	p[pn].sx=p[pn].sy=1;
	p[pn].qut=0;
	p[pn].own=&p[pn];
}

void playerinit(int playern,int level)
{
	if (level==0)  //自由模式
	{
		int i;
		ETD=1;
		pn=playern;
		//p[0].id=0;p[0].sx=p[0].sy=1;
		p[0]=stp[0];
		for (i=1;i<=playern;i++)
		{
			p[i]=stp[1];
	/*		p[i].id=1;p[i].fc=i-1;
			p[i].hp=p[i].fd=p[i].wt=p[i].og=100;
			p[i].tol=&sti[0];
			p[i].eqp=0;*/
			p[i].at=p[i].mt=p[i].ot=p[i].bt=p[pn].swt=0;
			p[i].sx=p[i].sy=1;
			p[i].vx=p[i].vy=0;
			p[i].x=p[i].y=9+i;
			p[i].qut=0;
			p[i].own=&p[i];
	//		p[i].spd=1;
			strcpy(p[i].msg[1],"~~");
			strcpy(p[i].msg[2],"~~");
			int j;
			for (j=0;j<=20;j++)
			{
				p[i].kill[j]=0;
			}
		}
		strcpy(p[1].c,"玩家1");
		if (playern==2) strcpy(p[2].c,"玩家2");
		spawn(5,15,15);
		spawn(23,20,20);
		spawn(24,25,25);
	}
	else if (level==1)  //挑战1
	{
		int i;
		ETD=1;
		pn=playern;
		//p[0].id=0;p[0].sx=p[0].sy=1;
		p[0]=stp[0];
		for (i=1;i<=playern;i++)
		{
			p[i]=stp[1];
			p[i].at=p[i].mt=p[i].ot=p[i].bt=p[pn].swt=0;
			p[i].sx=p[i].sy=1;
			p[i].vx=p[i].vy=0;
			p[i].qut=0;
			p[i].own=&p[i];
			strcpy(p[i].msg[1],"~~");
			strcpy(p[i].msg[2],"~~");
			int j;
			for (j=0;j<=20;j++)
			{
				p[i].kill[j]=0;
			}
		}
		p[1].x=p[1].y=49;
		strcpy(p[1].c,"玩家1");
		if (playern==2)
		{
			p[2].x=p[2].y=51;
			strcpy(p[2].c,"玩家2");
		}
	}
	else if (level==2)  //挑战2
	{
		int i;
		ETD=1;
		pn=playern;
		//p[0].id=0;p[0].sx=p[0].sy=1;
		p[0]=stp[0];
		for (i=1;i<=playern;i++)
		{
			p[i]=stp[1];
			p[i].at=p[i].mt=p[i].ot=p[i].bt=p[pn].swt=0;
			p[i].sx=p[i].sy=1;
			p[i].vx=p[i].vy=0;
			p[i].qut=0;
			p[i].own=&p[i];
			strcpy(p[i].msg[1],"~~");
			strcpy(p[i].msg[2],"~~");
			int j;
			for (j=0;j<=20;j++)
			{
				p[i].kill[j]=0;
			}
		}
		p[1].x=p[1].y=49;
		strcpy(p[1].c,"玩家1");
		if (playern==2)
		{
			p[2].x=p[2].y=51;
			strcpy(p[2].c,"玩家2");
		}
		spawn(24,rand()%60+21,rand()%60+21);
		spawn(24,rand()%60+21,rand()%60+21);
		spawn(24,rand()%60+21,rand()%60+21);
		spawn(5,rand()%60+21,20);
		spawn(5,rand()%60+21,20);
		spawn(5,rand()%60+21,20);
		spawn(5,20,rand()%60+21);
		spawn(5,20,rand()%60+21);
		spawn(5,20,rand()%60+21);
		spawn(5,rand()%60+21,80);
		spawn(5,rand()%60+21,80);
		spawn(5,rand()%60+21,80);
		spawn(5,80,rand()%60+21);
		spawn(5,80,rand()%60+21);
		spawn(5,80,rand()%60+21);
	}
}
 
void mapload(int level)
{
	int i,j;
	if (level==0)  //自由模式
	{
		for (i=1;i<=MX;i++)
			for (j=1;j<=MY;j++)
			{
				int t=rand()%6+1;
				flor[i][j]=t;
				map[i][j]=&stb[1];
				iflor[i][j]=&stb[1];
				liv[i][j]=&p[0];
			}
		FILE *mf;
		if ((mf=fopen("map.dat","r"))!=NULL)
		{
			for (i=1;i<=MX;i++)
				for (j=1;j<=MY;j++)
					fscanf(mf,"%d",&flor[i][j]);
			fclose(mf);
		}
		iflor[8][8]=iflor[7][8]=&stb[71];
		imap[8][8]=imap[7][8]=sti[1];
		iflor[9][10]=&stb[72];
		imap[9][10]=sti[2];
		iflor[7][10]=&stb[73];
		imap[7][10]=sti[3];
		iflor[5][10]=&stb[74];
		imap[5][10]=sti[4];
		iflor[5][7]=&stb[75];
		imap[5][7]=sti[5];
		iflor[12][10]=&stb[76];
		imap[12][10]=sti[6];
	}
	else if (level==1)  //挑战1
	{
		for (i=1;i<=MX;i++)
			for (j=1;j<=MY;j++)
			{
				int t=rand()%6+1;
				flor[i][j]=t;
				map[i][j]=&stb[1];
				iflor[i][j]=&stb[1];
				liv[i][j]=&p[0];
			}
			
		iflor[30][30]=iflor[70][70]=&stb[71];
		imap[30][30]=imap[70][80]=sti[1];
	}
	else if (level==2)  //挑战2
	{
		for (i=1;i<=MX;i++)
			for (j=1;j<=MY;j++)
			{
				int t=rand()%6+1;
				flor[i][j]=t;
				map[i][j]=&stb[1];
				iflor[i][j]=&stb[1];
				liv[i][j]=&p[0];
			}
			
		iflor[30][30]=iflor[70][70]=&stb[71];
		imap[30][30]=imap[70][80]=sti[1];
	}
	for (i=0;i<=MX+1;i++)
	{
		map[0][i]=map[MX+1][i]=map[i][0]=map[i][MY+1]=&stb[2];
		liv[0][i]=liv[MX+1][i]=liv[i][0]=liv[i][MY+1]=&p[0];	
	}
}
 
int endcheck()
{
    int i;
    for (i=1;i<=PS;i++)
    {
        if (p[i].qut==0) return 0;
    }
    return 1;
}

void pause(int *exitflag)
{
	clock_t tt=clock();
	background();
	wait(200);
	gotoxy(3,1);
	print("                      暂    停                        \n",7,6);
	print(" 已经共存活了",14,6);
	printf("\e[0;37m\e[46m %.2lf\e[0m",((double)clock()-stayt)/CLOCKS_PER_SEC);
	print("s,Stayer!\n",14,6);
	print("\n  按下ESC或者B键返回游戏\n",14,6);
	print("  按下回车或者E键退出游戏",14,6);
	while (1)
	{

		getinput();
		if (keyp("b")) {wait(200); clrscr(); stayt+=(clock()-tt); return;}
		if (keyp("e")) {stayt+=(clock()-tt); *exitflag=1; return;}
		#ifdef WIN
		if (GetKeyState(VK_ESCAPE)<0) {wait(200); clrscr(); stayt+=(clock()-tt); return;}
		if (GetKeyState(VK_RETURN)<0) {stayt+=(clock()-tt); *exitflag=1; return;}
		#endif
	}
}

void addmsg(player *q,char *ss)
{
	strcpy(q->msg[2],q->msg[1]);
	strcpy(q->msg[1],ss);
}

void drawguide(player *q,int xx,int yy)
{
	int i;
	for (i=1;i<=pn;i++)
	{
		if ((q==&p[i])||(p[i].id==4)||(p[i].id==21)||(p[i].id==22)||(p[i].id==23)||(p[i].id==25)) continue;
		if (((int)p[i].x>=q->sx)&&((int)p[i].x<=q->sx+10)&&((int)p[i].y>=q->sy)&&((int)p[i].y<=q->sy+10)) continue;
		if (((int)p[i].x>=q->sx)&&((int)p[i].x<=q->sx+10)&&((int)p[i].y<q->sy))
		{
			gotoxy(xx+(int)p[i].x-q->sx+1,yy);
			print("←",stb[p[i].id+20].fc,flor[(int)p[i].x][q->sy]);
		}
		if (((int)p[i].x>=q->sx)&&((int)p[i].x<=q->sx+10)&&((int)p[i].y>q->sy+10))
		{
			gotoxy(xx+(int)p[i].x-q->sx+1,yy+20);
			print("→",stb[p[i].id+20].fc,flor[(int)p[i].x][q->sy+10]);
		}
		if (((int)p[i].y>=q->sy)&&((int)p[i].y<=q->sy+10)&&((int)p[i].x<q->sx))
		{
			gotoxy(xx+1,yy+((int)p[i].y-q->sy)*2);
			print("↑",stb[p[i].id+20].fc,flor[q->sx][(int)p[i].y]);
		}
		if (((int)p[i].y>=q->sy)&&((int)p[i].y<=q->sy+10)&&((int)p[i].x>q->sx+10))
		{
			gotoxy(xx+11,yy+((int)p[i].y-q->sy)*2);
			print("↓",stb[p[i].id+20].fc,flor[q->sx+10][(int)p[i].y]);
		}
		if (((int)p[i].x<q->sx)&&((int)p[i].y<q->sy))
		{
			gotoxy(xx+1,yy);
			print("↖",stb[p[i].id+20].fc,flor[q->sx][q->sy]);
		}
		if (((int)p[i].x<q->sx)&&((int)p[i].y>q->sy+10))
		{
			gotoxy(xx+1,yy+20);
			print("↗",stb[p[i].id+20].fc,flor[q->sx][q->sy+10]);
		}
		if (((int)p[i].x>q->sx+10)&&((int)p[i].y<q->sy))
		{
			gotoxy(xx+11,yy);
			print("↙",stb[p[i].id+20].fc,flor[q->sx+10][q->sy]);
		}
		if (((int)p[i].x>q->sx+10)&&((int)p[i].y>q->sy+10))
		{
			gotoxy(xx+11,yy+20);
			print("↘",stb[p[i].id+20].fc,flor[q->sx+10][q->sy+10]);
		}
	}
}

void draw(player *q,int xx,int yy)
{
	if (q->id>2) return;
	int i,j,k,t;
	gotoxy(xx,yy);
	if (q->hp<=-1958)
		printf("很遗憾。你挂了！");
	else
		printf("HP:%d OG:%d      ",q->hp,q->og);
	gotoxy(xx+1,yy);
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
		gotoxy(xx+i-q->sx+2,yy);
	}
	#ifdef GUIDE
	drawguide(q,xx,yy);
	#endif
	gotoxy(xx+12,yy);
	printf("%s %s:%d ",q->c,q->tol.c,q->tol.ava);
	if (iflor[(int)q->x][(int)q->y]->id==1)
		print("空地",11,0);
	else
		print(sti[iflor[(int)q->x][(int)q->y]->id-70].c,11,0);
	print("  ",11,0);
	gotoxy(xx+13,yy);
	print(q->msg[1],8,0);
	printf("        ");
	gotoxy(xx+14,yy);
	print(q->msg[2],9,0);
	printf("        ");
	gotoxy(xx+15,yy);
	printf("%d %d",inbufn,pn);
	printf(" fps:%d  %.2lf",fps,q->x);
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
 
		#ifdef SCREENSHAKE
		p[i].x-=SHAKE*p[i].vx; p[i].y-=SHAKE*p[i].vy;
		#endif
 
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
 
		#ifdef SCREENSHAKE
		p[i].x+=SHAKE*p[i].vx; p[i].y+=SHAKE*p[i].vy;
		#endif
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
					liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->hp-=(int)(BOMBDMG*(getv(&p[i])/9.0));
					p[i].hp-=(int)(BOMBDMG*(getv(&p[i])/2.0));
 
					#ifdef WEAKMSG
					if ((int)(p[i].eqp*(getv(&p[i])/9.0))>1)
					{
						char ts[34];
						strcpy(ts,"你打了");
						strcat(ts,liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)]->c);
						addmsg(p[i].own,ts);
						strcpy(ts,p[i].own->c);
						strcat(ts,"打了你");
						addmsg(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+p[i].vy)],ts);
					}
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
		if (abs(p[i].vx)>5*p[i].miu)
			p[i].vx-=sgn(p[i].vx)*3.0*p[i].miu;
		else
			p[i].vx*=p[i].miu;
		if (abs(p[i].vy)>5*p[i].miu)
			p[i].vy-=sgn(p[i].vy)*3.0*p[i].miu;
		else
			p[i].vy*=p[i].miu;
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
		if (p[i].id==24)  //敌人水晶
		{
			p[i].hp+=rand()%2;
			int j;
			for (j=1;j<=pn;j++)
			{
				if ((p[j].team==0)&&(dis(&p[i],&p[j])<=3)) p[j].hp+=5;
			}
		}
	}
}
 
void mapspawn(int level)  //地图自动大刷新
{
	if (level==1)  //挑战1
	{
		int i;
		for (i=1;i<=(((double)clock()-stayt)/CLOCKS_PER_SEC)/10;i++)
		{
			spawn(2,rand()%60+21,rand()%60+21);
			p[pn].tol.ft=1000;
		}
	}
	if (level==2)  //挑战2
	{
		int i,j;
		int tn=0;int t=0;
		for (j=1;j<=pn;j++)
		{
			if (p[j].id==24) tn++;
			if (p[j].id==2) t++;
		}
		for (i=1;i<=3-tn+1-t;i++)
		{
			spawn(2,rand()%60+21,rand()%60+21);
			p[pn].tol.ft=1000;
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

		if ((p[i].id!=4)&&(p[i].id!=21)&&(p[i].id!=22)&&((p[i].bx!=0)||(p[i].by!=0))&&(p[i].bt+BT*CLOCKS_PER_SEC/1000<=clock()))  //击退延迟计算
		{
			p[i].vx+=p[i].bx; p[i].vy+=p[i].by;
			p[i].bx=p[i].by=0;
		}

		if ((p[i].hp<=0)&&(p[i].id==1))  //玩家死亡
		{
			if (p[i].tol.id&&(iflor[(int)(p[i].x)][(int)(p[i].y)]->id==1)) drop(&p[i]);
			p[i].hp=-1958;
 
			if (!p[i].qut)
			{
				p[i].qut=1;
				p[i].own->kill[p[i].id]++;
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
			p[pn].vx=-1; p[pn].vy=0; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x,p[i].y-1);
			p[pn].vx=0; p[pn].vy=-1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x+1,p[i].y);
			p[pn].vx=1; p[pn].vy=0; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x,p[i].y+1);
			p[pn].vx=0; p[pn].vy=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
 
			spawn(22,p[i].x-1,p[i].y-1);
			p[pn].vx=-1; p[pn].vy=-1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x-1,p[i].y+1);
			p[pn].vx=-1; p[pn].vy=1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x+1,p[i].y-1);
			p[pn].vx=1; p[pn].vy=-1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x+1,p[i].y+1);
			p[pn].vx=1; p[pn].vy=1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
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

		if ((p[i].hp<=0)&&(p[i].id==5))  //箱子死亡
		{
			p[i].qut=1;
			spawn(22,p[i].x-1,p[i].y);
			p[pn].vx=-1; p[pn].vy=0; p[pn].own=p[i].own; p[pn].hp=2; p[pn].blow=p[i].blow; p[pn].eqp=0;
			spawn(22,p[i].x,p[i].y-1);
			p[pn].vx=0; p[pn].vy=-1; p[pn].own=p[i].own; p[pn].hp=2; p[pn].blow=p[i].blow; p[pn].eqp=0;
			spawn(22,p[i].x+1,p[i].y);
			p[pn].vx=1; p[pn].vy=0; p[pn].own=p[i].own; p[pn].hp=2; p[pn].blow=p[i].blow; p[pn].eqp=0;
			spawn(22,p[i].x,p[i].y+1);
			p[pn].vx=0; p[pn].vy=1; p[pn].own=p[i].own; p[pn].hp=2; p[pn].blow=p[i].blow; p[pn].eqp=0;
 
			spawn(22,p[i].x-1,p[i].y-1);
			p[pn].vx=-1; p[pn].vy=-1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=0;
			spawn(22,p[i].x-1,p[i].y+1);
			p[pn].vx=-1; p[pn].vy=1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=0;
			spawn(22,p[i].x+1,p[i].y-1);
			p[pn].vx=1; p[pn].vy=-1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=0;
			spawn(22,p[i].x+1,p[i].y+1);
			p[pn].vx=1; p[pn].vy=1; p[pn].hp=1; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=0;
			int t=rand()%200;
			if (t>=190)
			{
				iflor[(int)p[i].x][(int)p[i].y]=&stb[76];
				imap[(int)p[i].x][(int)p[i].y]=sti[6];
			}
			else if (t>=180)
			{
				iflor[(int)p[i].x][(int)p[i].y]=&stb[75];
				imap[(int)p[i].x][(int)p[i].y]=sti[5];
			}
			else if (t>=150)
			{
				iflor[(int)p[i].x][(int)p[i].y]=&stb[74];
				imap[(int)p[i].x][(int)p[i].y]=sti[4];
			}
			else if (t>=90)
			{
				iflor[(int)p[i].x][(int)p[i].y]=&stb[73];
				imap[(int)p[i].x][(int)p[i].y]=sti[3];
			}
			else if (t>=70)
			{
				iflor[(int)p[i].x][(int)p[i].y]=&stb[72];
				imap[(int)p[i].x][(int)p[i].y]=sti[2];
			}
			else
			{
				iflor[(int)p[i].x][(int)p[i].y]=&stb[71];
				imap[(int)p[i].x][(int)p[i].y]=sti[1];
			}

			p[i]=p[pn]; p[pn].id=404; pn--;  //?
			continue;
		}

		if ((p[i].hp<=0)&&(p[i].id==24))  //敌方水晶死亡
		{
			p[i].qut=1;
			spawn(22,p[i].x-1,p[i].y);
			p[pn].vx=-1; p[pn].vy=0; p[pn].hp=4; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x,p[i].y-1);
			p[pn].vx=0; p[pn].vy=-1; p[pn].hp=4; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x+1,p[i].y);
			p[pn].vx=1; p[pn].vy=0; p[pn].hp=4; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x,p[i].y+1);
			p[pn].vx=0; p[pn].vy=1; p[pn].hp=4; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
 
			spawn(22,p[i].x-1,p[i].y-1);
			p[pn].vx=-1; p[pn].vy=-1; p[pn].hp=2; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x-1,p[i].y+1);
			p[pn].vx=-1; p[pn].vy=1; p[pn].hp=2; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x+1,p[i].y-1);
			p[pn].vx=1; p[pn].vy=-1; p[pn].hp=2; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
			spawn(22,p[i].x+1,p[i].y+1);
			p[pn].vx=1; p[pn].vy=1; p[pn].hp=2; p[pn].own=&stp[24]; p[pn].blow=p[i].blow; p[pn].eqp+=p[i].eqp;
 
			char ts[34];
			strcpy(ts,p[i].own->c);
			strcat(ts,"摧毁了敌方水晶!");
			int j;
			for (j=1;j<=pn;j++)
				if (p[j].id==1) addmsg(&p[j],ts);

			p[i]=p[pn]; p[pn].id=404; pn--;  //?
			continue;
		}

		if (p[i].hp<=0)  //其他死亡
		{
			if (p[i].tol.id&&(iflor[(int)(p[i].x)][(int)(p[i].y)]->id==1))
			{
				p[i].tol.ft=sti[p[i].tol.id].ft;  //cd恢复
				drop(&p[i]);
			}
			
			if ((p[i].id<=20)&&(!p[i].qut))
			{
				p[i].qut=1;
				p[i].own->kill[p[i].id]++;
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
 
		if (p[i].id==3)  //护卫
		{
			ai3(&p[i]);
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
				if ((p[i].own==0)&&(liv[(int)p[i].x][(int)p[i].y]->team==0)&&(ETD==0)) continue;
				if (!liv[(int)p[i].x][(int)p[i].y]->qut)
					liv[(int)p[i].x][(int)p[i].y]->own=p[i].own;
				liv[(int)p[i].x][(int)p[i].y]->hp-=p[i].eqp;
				liv[(int)p[i].x][(int)p[i].y]->by+=p[i].blow*p[i].sy;
				liv[(int)p[i].x][(int)p[i].y]->bx+=p[i].blow*p[i].sx;
				liv[(int)p[i].x][(int)p[i].y]->bt=clock();
 
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
  
		if (p[i].id==22)  //冲击波???
		{
			if (ifoutmap(&p[i]))
			{
				p[i].hp=0;
				continue;
			}
			if (map[(int)p[i].x][(int)p[i].y]->csh==0)
			{
				int t=p[i].hp;
				p[i].hp=0;
				if (!liv[(int)p[i].x][(int)p[i].y]->id) continue;
				if (!liv[(int)p[i].x][(int)p[i].y]->qut)
					liv[(int)p[i].x][(int)p[i].y]->own=p[i].own;
				liv[(int)p[i].x][(int)p[i].y]->hp-=p[i].eqp*t;
				liv[(int)p[i].x][(int)p[i].y]->by+=p[i].blow*p[i].vy;
				liv[(int)p[i].x][(int)p[i].y]->bx+=p[i].blow*p[i].vx;
				liv[(int)p[i].x][(int)p[i].y]->bt=clock();
 
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
			if (p[i].hp==0) continue;
			spawn(22,p[i].x+p[i].vx,p[i].y+p[i].vy);  //冲击波基础扩散
			p[pn].hp=p[i].hp;
			p[pn].vx=p[i].vx; p[pn].vy=p[i].vy; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=p[i].eqp;
			if ((p[i].vy!=0)&&(liv[(int)(p[i].x-1)][(int)p[i].y]->id!=22)&&(liv[(int)(p[i].x-1)][(int)(p[i].y+p[i].vy)]->id!=2))  //冲击波扩展扩散
			{
				spawn(22,p[i].x-1,p[i].y+p[i].vy);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=p[i].eqp;
			}
			if ((p[i].vy!=0)&&(liv[(int)(p[i].x+1)][(int)p[i].y]->id!=22)&&(liv[(int)(p[i].x-1)][(int)(p[i].y+p[i].vy)]->id!=2))
			{
				spawn(22,p[i].x+1,p[i].y+p[i].vy);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=p[i].eqp;
			}
			if ((p[i].vx!=0)&&(liv[(int)p[i].x][(int)(p[i].y-1)]->id!=22)&&(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y-1)]->id!=2))
			{
				spawn(22,p[i].x+p[i].vx,p[i].y-1);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=p[i].eqp;
			}
			if ((p[i].vx!=0)&&(liv[(int)p[i].x][(int)(p[i].y+1)]->id!=22)&&(liv[(int)(p[i].x+p[i].vx)][(int)(p[i].y+1)]->id!=2))
			{
				spawn(22,p[i].x+p[i].vx,p[i].y+1);
				p[pn].hp=p[i].hp;
				p[pn].vx=p[i].vx; p[pn].vy=p[i].vy; p[pn].own=p[i].own; p[pn].blow=p[i].blow; p[pn].eqp=p[i].eqp;
			}
			p[i].hp=1;
			p[i].eqp=0;
			p[i].blow=0;
		}

		if (p[i].id==24)  //敌人水晶
		{
			if (ifoutmap(&p[i]))
			{
				p[i].hp=0;
				continue;
			}
			continue;
		}

		if (p[i].id==25)  //剑气
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
				liv[(int)p[i].x][(int)p[i].y]->by+=p[i].blow*p[i].vy;
				liv[(int)p[i].x][(int)p[i].y]->bx+=p[i].blow*p[i].vx;
				liv[(int)p[i].x][(int)p[i].y]->bt=clock();
 
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
			if ((SGT*CLOCKS_PER_SEC/1000)+p[i].mt>clock()) continue;
			p[i].mt=clock();
			p[i].hp--;
			p[i].x+=p[i].vx; p[i].y+=p[i].vy;
		}
	}
}
 
void controldbg()
{
	if (keyp("i")&&(p[0].sx>1)) p[0].sx-=1;
	if (keyp("j")&&(p[0].sy>1)) p[0].sy-=1;
	if (keyp("k")&&(p[0].sx<MX-10)) p[0].sx+=1;
	if (keyp("l")&&(p[0].sy<MY-10)) p[0].sy+=1;
}
 
clock_t st=0;
int z=0;  //???
  
void control1(player *q,int *exitflag)
{
	if (q->qut==1) return;
 
	if ((MT*CLOCKS_PER_SEC/1000)+st<=clock())
	{
		z=1; st=clock();
	}
 
#ifdef WIN
	if ((keyp("w"))&&(GetKeyState(VK_LSHIFT)<0)&&(q->og>RUNOG)) move(q,-3,0,1);
	if ((keyp("a"))&&(GetKeyState(VK_LSHIFT)<0)&&(q->og>RUNOG)) move(q,0,-3,1);
	if ((keyp("s"))&&(GetKeyState(VK_LSHIFT)<0)&&(q->og>RUNOG)) move(q,3,0,1);
	if ((keyp("d"))&&(GetKeyState(VK_LSHIFT)<0)&&(q->og>RUNOG)) move(q,0,3,1);
#endif
 
	if (keyp("w")&&(keyp("a"))) move(q,-sqrt(2)/2,-sqrt(2)/2,0);
	if (keyp("w")&&(keyp("d"))) move(q,-sqrt(2)/2,sqrt(2)/2,0);
	if (keyp("s")&&(keyp("a"))) move(q,sqrt(2)/2,-sqrt(2)/2,0);
	if (keyp("s")&&(keyp("d"))) move(q,sqrt(2)/2,sqrt(2)/2,0);
	if (keyp("w")) move(q,-1,0,0);
	if (keyp("a")) move(q,0,-1,0);
	if (keyp("s")) move(q,1,0,0);
	if (keyp("d")) move(q,0,1,0);
/*	if (keyp("y")&&q->tol.id&&(iflor[(int)(q->x)][(int)(q->y)]->id==1))
	{
		drop(q);
	}
	if (keyp("r")&&(q->tol.id==0)&&(iflor[(int)(q->x)][(int)(q->y)]->id>70))
	{
		pickup(q);
	}*/
	if (keyp("r")&&((q->tol.id!=0)||(iflor[(int)(q->x)][(int)(q->y)]->id>70)))
	{
		pick(q);
	}
	if (keyp("t")) attack(q,-1,0);
	if (keyp("f")) attack(q,0,-1);
	if (keyp("g")) attack(q,1,0);
	if (keyp("h")) attack(q,0,1);
	#ifndef WIN
	if (z&&keyp("1")) spawn(2,rand()%60+21,rand()%60+21),z=0;
	if (z&&keyp("2")) spawn(3,rand()%60+21,rand()%60+21),z=0;
    if (keyp("E")) pause(exitflag);
	#endif
    #ifdef WIN
	if (z&&keyp("c")&&(GetKeyState(VK_UP)<0)) spawn(2,rand()%60+21,rand()%60+21),z=0;
	if (z&&keyp("c")&&(GetKeyState(VK_LEFT)<0)) spawn(3,rand()%60+21,rand()%60+21),z=0;
    if (GetKeyState(VK_ESCAPE)<0) pause(exitflag);
    #endif
}

#ifdef BIGKEYBOARD
void control2(player *q,int *exitflag)
{
/*	if (q->qut==1) return;
	if (keyp("i")) move(q,-1,0);
	if (keyp("j")) move(q,0,-1);
	if (keyp("k")) move(q,1,0);
	if (keyp("l")) move(q,0,1);*/
	if (q->qut==1) return;
 
	if ((MT*CLOCKS_PER_SEC/1000)+st<=clock())
	{
		z=1; st=clock();
	}
 
#ifdef WIN
	if ((GetKeyState(VK_UP)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,-3,0,1);
	if ((GetKeyState(VK_LEFT)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,0,-3,1);
	if ((GetKeyState(VK_DOWN)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,3,0,1);
	if ((GetKeyState(VK_RIGHT)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,0,3,1);
 
	if ((GetKeyState(VK_UP)<0)&&(GetKeyState(VK_LEFT)<0)) move(q,-sqrt(2)/2,-sqrt(2)/2,0);
	if ((GetKeyState(VK_UP)<0)&&(GetKeyState(VK_RIGHT)<0)) move(q,-sqrt(2)/2,sqrt(2)/2,0);
	if ((GetKeyState(VK_DOWN)<0)&&(GetKeyState(VK_LEFT)<0)) move(q,sqrt(2)/2,-sqrt(2)/2,0);
	if ((GetKeyState(VK_DOWN)<0)&&(GetKeyState(VK_RIGHT)<0)) move(q,sqrt(2)/2,sqrt(2)/2,0);
	if (GetKeyState(VK_UP)<0) move(q,-1,0,0);
	if (GetKeyState(VK_LEFT)<0) move(q,0,-1,0);
	if (GetKeyState(VK_DOWN)<0) move(q,1,0,0);
	if (GetKeyState(VK_RIGHT)<0) move(q,0,1,0);
#endif
	if ((GetKeyState(VK_NUMPAD7)<0)&&((q->tol.id!=0)||(iflor[(int)(q->x)][(int)(q->y)]->id>70)))
	{
		pick(q);
	}
	if (GetKeyState(VK_NUMPAD8)<0) attack(q,-1,0);
	if (GetKeyState(VK_NUMPAD4)<0) attack(q,0,-1);
	if (GetKeyState(VK_NUMPAD5)<0) attack(q,1,0);
	if (GetKeyState(VK_NUMPAD6)<0) attack(q,0,1);
	#ifndef WIN
	if (z&&keyp("1")) spawn(2,rand()%60+21,rand()%60+21),z=0;
	if (z&&keyp("2")) spawn(3,rand()%60+21,rand()%60+21),z=0;
    if (keyp("E")) pause(exitflag);
	#endif
    #ifdef WIN
	if (z&&keyp("c")&&(GetKeyState(VK_UP)<0)) spawn(2,rand()%60+21,rand()%60+21),z=0;
	if (z&&keyp("c")&&(GetKeyState(VK_LEFT)<0)) spawn(3,rand()%60+21,rand()%60+21),z=0;
    if (GetKeyState(VK_ESCAPE)<0) pause(exitflag);
    #endif
}
#else
void control2(player *q,int *exitflag)
{
	if (q->qut==1) return;
 
	if ((MT*CLOCKS_PER_SEC/1000)+st<=clock())
	{
		z=1; st=clock();
	}
 
#ifdef WIN
	if ((GetKeyState(VK_UP)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,-3,0,1);
	if ((GetKeyState(VK_LEFT)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,0,-3,1);
	if ((GetKeyState(VK_DOWN)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,3,0,1);
	if ((GetKeyState(VK_RIGHT)<0)&&(GetKeyState(VK_RSHIFT)<0)&&(q->og>RUNOG)) move(q,0,3,1);
 
	if ((GetKeyState(VK_UP)<0)&&(GetKeyState(VK_LEFT)<0)) move(q,-sqrt(2)/2,-sqrt(2)/2,0);
	if ((GetKeyState(VK_UP)<0)&&(GetKeyState(VK_RIGHT)<0)) move(q,-sqrt(2)/2,sqrt(2)/2,0);
	if ((GetKeyState(VK_DOWN)<0)&&(GetKeyState(VK_LEFT)<0)) move(q,sqrt(2)/2,-sqrt(2)/2,0);
	if ((GetKeyState(VK_DOWN)<0)&&(GetKeyState(VK_RIGHT)<0)) move(q,sqrt(2)/2,sqrt(2)/2,0);
	if (GetKeyState(VK_UP)<0) move(q,-1,0,0);
	if (GetKeyState(VK_LEFT)<0) move(q,0,-1,0);
	if (GetKeyState(VK_DOWN)<0) move(q,1,0,0);
	if (GetKeyState(VK_RIGHT)<0) move(q,0,1,0);
#endif
	if (keyp("[")&&((q->tol.id!=0)||(iflor[(int)(q->x)][(int)(q->y)]->id>70)))
	{
		pick(q);
	}
	if (keyp("p")) attack(q,-1,0);
	if (keyp("l")) attack(q,0,-1);
	if (keyp(";")) attack(q,1,0);
	if (keyp("'")) attack(q,0,1);
	#ifndef WIN
	if (z&&keyp("1")) spawn(2,rand()%60+21,rand()%60+21),z=0;
	if (z&&keyp("2")) spawn(3,rand()%60+21,rand()%60+21),z=0;
    if (keyp("E")) pause(exitflag);
	#endif
    #ifdef WIN
	if (z&&keyp("c")&&(GetKeyState(VK_UP)<0)) spawn(2,rand()%60+21,rand()%60+21),z=0;
	if (z&&keyp("c")&&(GetKeyState(VK_LEFT)<0)) spawn(3,rand()%60+21,rand()%60+21),z=0;
    if (GetKeyState(VK_ESCAPE)<0) pause(exitflag);
    #endif
}
#endif

void gamescreen(int playern,int level)
{
    clrscr();
	inbufn=0; spst=opst=ppst=dpst=fpst=clock(); fpsf=fps=0;
    stayt=clock();
    int zz=0;  //退出标记
	while (1)
	{
 
		playerlogic();
			
		maprefresh();
 
		if (fpst+1000*CLOCKS_PER_SEC/1000<=clock())
		{
			fps=fpsf; fpsf=0; fpst=clock();
			inbufn=0;
		}
 
		if ((level!=0)&&(spst+SPT[level]*CLOCKS_PER_SEC/1000<=clock()))
		{
			spst=clock();
			mapspawn(level);
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
			inbufn=0;
			
			draw(&p[1],1,1);
            if (playern==2)
			{
				draw(&p[2],1,25);
				int i;
				for (i=1;i<=16;i++)
				{
					gotoxy(i,23); print("┃",8,0);
				}
			}
			#ifdef DEBUG
			else draw(&p[0],1,25);
			#endif

            gotoxy(1,47);
            print("STAYED",0,0);
            gotoxy(2,47);
            printf("%.2lfs",((double)clock()-stayt)/CLOCKS_PER_SEC);
		}
		getinput();
		
		control1(&p[1],&zz);
		if (playern==2) control2(&p[2],&zz);
		#ifdef DEBUG
		else controldbg(); 
		#endif
		
        if (endcheck()) zz=1;
 
		inputdbg();
		gotoxy(1,1);
        if (zz) return;
	}
}