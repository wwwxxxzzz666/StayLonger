typedef struct{
	int id;
	int dmg;
	int ft;  //冷却时间 单位ms
	char c[6];
}item;
 
typedef struct{
	int id,fc;
	int hp,fd,wt,og;
	item *tol;
	int eqp;
	int sx,sy;
	clock_t at,mt,dt; //攻击冷却，移动冷却，伤害冷却
	double x,vx,y,vy;
	double spd;
	char c[12];
}player;
 
typedef struct{
	char c[2];
	int id,fc;
	int csh;
	player *p;
}block;
 
#define MB 100
#define MI 100
#define MP 100
 
block stb[MB+1];
item sti[MI+1];
player stp[MP+1];  //???
 
void stbinit()
{
	int i;
	for (i=0;i<=MB;i++) stb[i].id=i;
	strcpy(stb[0].c," ");stb[0].fc=0;stb[0].csh=1; //虚空
	strcpy(stb[1].c," ");stb[1].fc=1;stb[1].csh=1; //空气
	strcpy(stb[2].c,"ロ");stb[2].fc=7;stb[2].csh=0; //墙
	strcpy(stb[21].c,"デ");stb[21].fc=15;stb[21].csh=0; //人类
	strcpy(stb[22].c,"バ");stb[22].fc=15;stb[22].csh=0; //敌人
	strcpy(stb[23].c,"ヽ");stb[23].fc=15;stb[23].csh=1;  //子弹
	strcpy(stb[71].c,"ヶ");stb[71].fc=13; //小枪
}
 
void stiinit()
{
	int i;
	for (i=0;i<=MI;i++) sti[i].id=i;
	strcpy(sti[0].c,"双手");sti[0].dmg=5;sti[0].ft=500;
	strcpy(sti[1].c,"小枪");sti[1].dmg=3;sti[1].ft=300;
}
 
void stpinit()
{
	int i;
	for (i=0;i<=MP;i++) stp[i].id=i;
	strcpy(stp[0].c,"测试");
	stp[0].sx=stp[0].sy=1;
	strcpy(stp[1].c,"玩家");
	stp[1].hp=stp[1].fd=stp[1].wt=stp[1].og=1000;
	stp[1].tol=&sti[0];
	stp[1].eqp=0;
	stp[1].spd=0.7;
	strcpy(stp[2].c,"敌人");
	stp[2].hp=stp[2].fd=stp[2].wt=stp[2].og=100;
	stp[2].tol=&sti[1];
	stp[2].eqp=0;
	stp[2].spd=0.6;
	strcpy(stp[3].c,"子弹");
	stp[3].hp=20;
	stp[3].eqp=8;  //暂定伤害
	stp[3].spd=0.2;
}