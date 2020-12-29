typedef struct{
	int id;
	int dmg;
	int ft;  //冷却时间 单位ms
	int ava;  //弹药数
	double blow; //击退程度
	char c[6];
}item;
 
typedef struct player{
	int id,fc;
	int hp,fd,wt,og;
	item tol;
	int eqp;
	int sx,sy;
	int team;  //阵营
	int qut;  //死亡宣告
	clock_t at,mt,ot; //攻击冷却，移动冷却，氧气冷却
	double x,vx,y,vy;
	double spd;
	double miu;  //阻力系数
	struct player *own;
	char c[17];
	char msg[3][34];
	int kill[21];  //击杀数
	int score;  //分数
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
	strcpy(stb[1].c,"  ");stb[1].fc=1;stb[1].csh=1; //空气
	strcpy(stb[2].c,"ロ");stb[2].fc=7;stb[2].csh=0; //墙
	strcpy(stb[21].c,"デ");stb[21].fc=15;stb[21].csh=0; //人类
	strcpy(stb[22].c,"バ");stb[22].fc=15;stb[22].csh=0; //敌人
	strcpy(stb[23].c,"ㄐ");stb[23].fc=15;stb[23].csh=0; //护卫
	strcpy(stb[24].c,"ぁ");stb[24].fc=15;stb[24].csh=0;  //手雷
	strcpy(stb[41].c,"ヽ");stb[41].fc=15;stb[41].csh=1;  //子弹
	strcpy(stb[42].c,"▓");stb[42].fc=15;stb[42].csh=1;  //冲击波
	strcpy(stb[71].c,"ヶ");stb[71].fc=13; //小枪
	strcpy(stb[72].c,"ゥ");stb[72].fc=13; //手雷
	strcpy(stb[73].c,"く");stb[73].fc=13; //球棒
}
 
void stiinit()
{
	int i;
	for (i=0;i<=MI;i++) sti[i].id=i;
	strcpy(sti[0].c,"双手");sti[0].dmg=5;sti[0].ft=500; sti[0].ava=7; sti[0].blow=0.5;
	strcpy(sti[1].c,"小枪");sti[1].dmg=3;sti[1].ft=300; sti[1].ava=25;
	strcpy(sti[2].c,"手雷");sti[2].dmg=20;sti[2].ft=1000; sti[2].ava=5;
	strcpy(sti[3].c,"球棒");sti[3].dmg=10;sti[3].ft=600; sti[3].ava=7; sti[3].blow=0.8;
}
 
void stpinit()
{
	int i;
	for (i=0;i<=MP;i++) {stp[i].id=i; stp[i].score=0;}
	strcpy(stp[0].c,"测试");
	stp[0].sx=stp[0].sy=1;
	strcpy(stp[1].c,"玩家");
	stp[1].hp=stp[1].fd=stp[1].wt=stp[1].og=1000;
	stp[1].tol=sti[0];
	stp[1].eqp=0;
	stp[1].team=1;
	stp[1].spd=0.333;
	stp[1].miu=0.33;
	stp[1].score=-50;
	strcpy(stp[2].c,"敌人");
	stp[2].hp=stp[2].fd=stp[2].wt=stp[2].og=100;
	stp[2].tol=sti[1];
	stp[2].tol.ava=50;
	stp[2].tol.ft=500;
	stp[2].eqp=0;
	stp[2].team=0;
	stp[2].spd=0.3;
	stp[2].miu=0.33;
	stp[2].score=15;
	strcpy(stp[3].c,"护卫");
	stp[3].hp=stp[3].fd=stp[3].wt=stp[3].og=100;
	stp[3].tol=sti[1];
	stp[3].tol.ava=70;
	stp[3].tol.ft=300;
	stp[3].eqp=0;
	stp[3].team=1;
	stp[3].spd=0.3;
	stp[3].miu=0.33;
	stp[3].score=-10;
	strcpy(stp[4].c,"手雷");
	stp[4].hp=10;
	stp[4].tol=sti[0];
	stp[4].eqp=5;  //暂定伤害
	stp[4].team=-1;
	stp[4].spd=0;
	stp[4].miu=0.95;
	strcpy(stp[21].c,"子弹");
	stp[21].hp=20;
	stp[21].tol=sti[0];
	stp[21].eqp=8;  //暂定伤害
	stp[21].team=-1;
	stp[21].spd=0.7;
	strcpy(stp[22].c,"冲击波");
	stp[22].hp=3;
	stp[22].tol=sti[0];
	stp[22].eqp=20;  //暂定伤害
	stp[22].team=-1;
	stp[22].spd=0;
}