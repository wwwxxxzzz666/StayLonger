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

int dis(player *p1,player *p2)  //直线距离取整
{
	return (int)(sqrt((p1->x-p2->x)*(p1->x-p2->x)+(p1->y-p2->y)*(p1->y-p2->y)));
}

double getv(player *q)
{
	return (sqrt(q->vx*q->vx+q->vy*q->vy));
}
 
void movev(player *q,double xx,double yy)
{
	if ((MT*CLOCKS_PER_SEC/1000)+q->mt>clock()) return;
	q->mt=clock();
	q->vx+=xx; q->vy+=yy;
}
 
void move(player *q,double xx,double yy,int ifog)
{
	if ((MT*CLOCKS_PER_SEC/1000)+q->mt>clock()) return;
	q->mt=clock();
	q->vx+=xx*q->spd; q->vy+=yy*q->spd;
	if (ifog) q->og-=20+rand()%6;
}
 
void pickup(player *q)
{
	q->tol=imap[(int)(q->x)][(int)(q->y)];
	iflor[(int)(q->x)][(int)(q->y)]=&stb[1];
	imap[(int)(q->x)][(int)(q->y)]=sti[0];
}
 
void drop(player *q)
{
	iflor[(int)(q->x)][(int)(q->y)]=&stb[q->tol.id+70];
	imap[(int)(q->x)][(int)(q->y)]=q->tol;
	q->tol=sti[0];
}

void pick(player *q)
{
	if ((q->swt*CLOCKS_PER_SEC/1000)+SWT>clock()) return;
	q->swt=clock();
	if ((q->tol.id==0)&&(iflor[(int)(q->x)][(int)(q->y)]->id>70))
	{
		pickup(q);
	}
	else if (q->tol.id&&(iflor[(int)(q->x)][(int)(q->y)]->id==1))
	{
		drop(q);
	}
	else
	{
		item tt;
		tt=q->tol;
		q->tol=imap[(int)(q->x)][(int)(q->y)];
		iflor[(int)(q->x)][(int)(q->y)]=&stb[tt.id+70];
		imap[(int)(q->x)][(int)(q->y)]=tt;
	}
}

void ammocheck(player *q)
{
	if (q->tol.ava<=0)
	{
		q->tol=sti[0];
	}
}
 
void attack(player *pp,int xx,int yy)
{
	if ((pp->tol.ft*CLOCKS_PER_SEC/1000)+pp->at>clock()) return;
	if (((int)(pp->x)+xx<1)||((int)(pp->x)+xx>MX)) return;
	if (((int)(pp->y)+yy<1)||((int)(pp->y)+yy>MY)) return;
	pp->at=clock();
	if ((pp->tol.id==0)||(pp->tol.id==3))  //双手&球棒
	{
		if (liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->id==0) return;
		if (liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->hp)
			liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->own=pp;
		liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->hp-=pp->tol.dmg; //!!!
		liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->by+=(abs(pp->vy)+pp->tol.blow)*EK*yy;
		liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->bx+=(abs(pp->vx)+pp->tol.blow)*EK*xx;
		liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->bt=clock();
 
#ifdef WEAKMSG
		char ts[34];
		strcpy(ts,"你打了");
		strcat(ts,liv[(int)(pp->x)+xx][(int)(pp->y)+yy]->c);
		addmsg(pp,ts);
		strcpy(ts,pp->c);
		strcat(ts,"打了你");
		addmsg(liv[(int)(pp->x)+xx][(int)(pp->y)+yy],ts);
#endif
 
	}
	if ((pp->tol.id==1)||(pp->tol.id==4)||(pp->tol.id==5))  //小枪&冲锋枪&机枪
	{
		pp->tol.ava--;
		pn++;
		p[pn]=stp[21];p[pn].sx=xx;p[pn].sy=yy;p[pn].eqp+=pp->tol.dmg;
		p[pn].blow=pp->tol.blow;
		p[pn].x=pp->x+xx;p[pn].y=pp->y+yy;
		p[pn].own=pp;
	}
	if (pp->tol.id==2)  //手雷
	{
		pp->tol.ava--;
		pn++;
		p[pn]=stp[4]; p[pn].vx=pp->vx+0.8*xx; p[pn].vy=pp->vy+0.8*yy; p[pn].eqp+=pp->tol.dmg;
		p[pn].blow=pp->tol.blow;
		p[pn].x=pp->x+xx;p[pn].y=pp->y+yy;
		p[pn].own=pp;
	}
	if (pp->tol.id==6)  //武士刀
	{
		if (xx==0)
		{
			pn++;
			p[pn]=stp[25]; p[pn].vx=xx; p[pn].vy=yy; p[pn].eqp+=pp->tol.dmg;
			p[pn].blow=pp->tol.blow;
			p[pn].x=pp->x+xx;p[pn].y=pp->y+yy*2;
			p[pn].own=pp;
			pn++;
			p[pn]=stp[25]; p[pn].vx=xx; p[pn].vy=yy; p[pn].eqp+=pp->tol.dmg;
			p[pn].blow=pp->tol.blow;
			p[pn].x=pp->x+xx-1;p[pn].y=pp->y+yy;
			p[pn].own=pp;
			pn++;
			p[pn]=stp[25]; p[pn].vx=xx; p[pn].vy=yy; p[pn].eqp+=pp->tol.dmg;
			p[pn].blow=pp->tol.blow;
			p[pn].x=pp->x+xx+1;p[pn].y=pp->y+yy;
			p[pn].own=pp;
		}
		else
		{
			pn++;
			p[pn]=stp[25]; p[pn].vx=xx; p[pn].vy=yy; p[pn].eqp+=pp->tol.dmg;
			p[pn].blow=pp->tol.blow;
			p[pn].x=pp->x+xx*2;p[pn].y=pp->y+yy;
			p[pn].own=pp;
			pn++;
			p[pn]=stp[25]; p[pn].vx=xx; p[pn].vy=yy; p[pn].eqp+=pp->tol.dmg;
			p[pn].blow=pp->tol.blow;
			p[pn].x=pp->x+xx;p[pn].y=pp->y+yy-1;
			p[pn].own=pp;
			pn++;
			p[pn]=stp[25]; p[pn].vx=xx; p[pn].vy=yy; p[pn].eqp+=pp->tol.dmg;
			p[pn].blow=pp->tol.blow;
			p[pn].x=pp->x+xx;p[pn].y=pp->y+yy+1;
			p[pn].own=pp;
		}
	}
	ammocheck(pp);
}
 
void ai2(player *q)
{
	player *tar;
	tar=&p[0];  //??
	int dmin=1<<7;
	int i,j;
	
	for (i=1;i<=pn;i++)  //找目标
	{
		if ((q==&p[i])||(p[i].team!=1)) continue;
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
			move(q,t,sgny(q,tar)+tt,0);
		}
		else
		{
			move(q,sgnx(q,tar)+tt,t,0);
		}
	}
	else
	{
		if (qdisx(q,tar)<=qdisy(q,tar))
		{
			move(q,sgnx(q,tar),0,0);
		}
		else
		{
			move(q,0,sgny(q,tar),0);
		}
	}
	
}
 
void ai3(player *q)
{
	player *tar;
	tar=&p[0];  //??
	int dmin=1<<7;
	int i,j;
	
	for (i=1;i<=pn;i++)  //找目标
	{
		if ((q==&p[i])||(p[i].team!=0)) continue;
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
			move(q,t,sgny(q,tar)+tt,0);
		}
		else
		{
			move(q,sgnx(q,tar)+tt,t,0);
		}
	}
	else
	{
		if (qdisx(q,tar)<=qdisy(q,tar))
		{
			move(q,sgnx(q,tar),0,0);
		}
		else
		{
			move(q,0,sgny(q,tar),0);
		}
	}
	
}