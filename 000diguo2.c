/*����lyc����*/
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int i, j, temp, shijian = 0, m, n;
char a[5] = "��", b[5] = "��", c[5] = "��", d[5] = "��", e[5] = "��", f[5] = "��", g[5] =
        "��", h[5] = "��", k[5] = "��", l[5] = "��", o[5] = "��", s[20], t[20], u[5] = " ";
void ascii();
void form(char aa[], char cc[], char bb[]);
void how(int, char m[]);
void ma();
void search();
void diguo();

int main() {
	char select;
	system("cls");
	printf
	("\n\n��ѡ���ܣ�\n1����ѯASCII��\n2���鿴ASCII��\n3���������\n4���۹�ʱ���ַ���\n");
loop:
	select = getch();
	if (select == '1')
		search();
	else if (select == '2')
		ascii();
	else if (select == '3')
		ma();
	else if (select == '4')
		diguo();
	else
		goto loop;

}

void ma() {
	printf("\n\n����������ÿ�е�ÿ�񳤶�.����0����\n");
	int make[20], n, make1;
	char lop;
	for (i = 0; i < 50; i++) {
		scanf("%d", &make[i]);
		if ((char)(make[i]) == 0)
			break;
	}
	printf("\n����������\n");
	scanf("%d", &make1);
	printf("\n���Ϊ��\n");
	n = i;
	how(1, a);
	for (i = 0; i < n; i++) {
		how(make[i], b);
		how(1, k);
	}
	printf("\b");
	how(1, c);
	printf("\n");
	int j = 0;
	while (j < make1 - 1) {
		how(1, o);
		for (i = 0; i < n; i++) {
			how(make[i], u);
			how(1, o);
		}
		printf("\b");
		how(1, o);
		printf("\n");
		how(1, d);
		for (i = 0; i < n; i++) {
			how(make[i], b);
			how(1, e);
		}
		printf("\b");
		how(1, f);
		printf("\n");
		j++;
	}
	how(1, o);
	for (i = 0; i < n; i++) {
		how(make[i], u);
		how(1, o);
	}
	printf("\b");
	how(1, o);
	printf("\n");
	how(1, g);
	for (i = 0; i < n; i++) {
		how(make[i], b);
		how(1, l);
	}
	printf("\b");
	how(1, h);
	printf("\n");
	printf("\n������������밴�س������������˵��밴�ո��");
	getch();
loop:


	lop = getch();
	if (lop == '\n')
		ma();
	else if (lop == ' ')
		main();
	else
		goto loop;

}

void how(int n, char m[]) {
	int i;

	for (i = 0; i < n; i++)

		printf("%s", m);


}

void form(char aa[], char cc[], char bb[]) {
	how(1, aa);
	for (i = 0; i < 4; i++) {

		how(7, b);
		how(1, cc);
		how(4, b);
		how(1, cc);
	}
	printf("\b");
	how(1, bb);
	printf("\n");
}

void search() {
	char b, a;


	printf("\n\n������һ���ַ���\n");
	a = getch();
	if (a >= 0 && a <= 127) {
		if (a == '\n') {
			printf("\"�س�����\\n\"��ASCII��Ϊ%d\n", a);
		} else if (a == ' ') {
			printf("���ո񡱵�ASCII��Ϊ%d\n", a);
		} else if (a == 127)
			printf("��delete����ASCII��Ϊ%d\n", a);
		else if (a >= 0 && a <= 31)
			printf("�á������ַ�����ASCII��Ϊ%d", a);

		else {
			printf("%c��ASCII��Ϊ%d\n", a, a);
		}
	} else
		printf("������ѯ��Χ��n��\n");
	printf("\n������ѯ�밴�س������������˵��밴�ո��");
loop:


	b = getch();
	if (b == '\n')
		search();
	else if (b == ' ')
		main();
	else
		goto loop;
}

void ascii() {

	int num, num1;
	char b, ha[][6] = {
		"NULL", "SOH", "STX", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "'\\t'", "'\\n'", "'\\v'",
		"'\\f'", "'\\r'", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "TB", "CAN",
		"EM",
		"Ctrz", "ESC", "FS", "GS", "RS", "US"
	};
	printf("\nASCII���Ϊ\n");
	form(a, k, c);
	{
		how(1, o);
		strcpy(s, "ASCIIֵ");
		strcpy(t, "�ַ�");
		for (i = 0; i < 4; i++) {
			printf("%-7s", s);
			how(1, o);
			printf("%-4s", t);
			how(1, o);

		}
		printf("\n");
	}
	for (num = 0; num < 32; num++) {
		form(d, e, f);
		num1 = num + 32;
		how(1, o);
		printf("%-7d", num);
		how(1, o);
		printf("%-4s", ha[num]);
		how(1, o);
		for (i = 0; i < 3; i++) {
			printf("%-7d", num1);
			how(1, o);
			if (num == 0 && i == 0)
				printf("%-4s", "�ո�");
			else if (num == 31 && i == 2)
				printf("%-4s", "DEL");
			else
				printf("%-4c", num1);
			how(1, o);
			num1 = num1 + 32;
		}
		printf("\n");
	}
	form(g, l, h);
	printf("\n�������˵��밴�ո��\n");
loop:
	b = getch();
	if (b == ' ')
		main();
	else
		goto loop;

}

int v = 1;
char str[100];
int map[17][20] = { 0 }, x = 10, y = 15;

/********һ��Ѷ��弰��ʼ��*********/
// ����
int bubinged, bu, x1, y1, p1, q1, *x1a, *y1a;
float x11, y11, *x11a, *y11a;
void bubing() {
	map[x1][y1] = 0;
	bubinged = 0;
	bu = 0;
	x1 = 14;
	y1 = 15;
	p1 = 12;
	q1 = 12;
	x1a = &x1;
	y1a = &y1;
	x11 = x1;
	y11 = y1;
	x11a = &x11;
	y11a = &y11;
}

//
int dbubinged, dbu, dx1, dy1, dp1, dq1, *dx1a, *dy1a;
float dx11, dy11, *dx11a, *dy11a;
void dbubing() {
	map[dx1][dy1] = 0;
	srand(time(0));
	dbubinged = 0;
	dbu = 0;
	dx1 = 0;
	dy1 = 4;
	dp1 = rand() % 5 + 5;
	dq1 = rand() % 5 + 5;
	dx1a = &dx1;
	dy1a = &dy1;
	dx11 = dx1;
	dy11 = dy1;
	dx11a = &dx11;
	dy11a = &dy11;
}

// ����
int gongbinged, gong, x2, y2, p2, q2, *x2a, *y2a = &y2, jian, jianshi = 0;
float x21, y21, *x21a, *y21a;
void gongbing() {
	map[x2][y2] = 0;
	gongbinged = 0;
	gong = 0;
	x2 = 14;
	y2 = 15;
	p2 = 11;
	q2 = 13;
	x2a = &x2;
	y2a = &y2;
	x21 = x2;
	y21 = y2;
	x21a = &x21;
	y21a = &y21;
	jian = 1;
}

//
int dgongbinged, dgong, dx2, dy2, dp2, dq2, *dx2a, *dy2a = &dy2, djian;
float dx21, dy21, *dx21a, *dy21a;
void dgongbing() {
	map[dx2][dy2] = 0;
	srand(time(0));
	dgongbinged = 0;
	dgong = 0;
	dx2 = 0;
	dy2 = 4;
	dp2 = 1 + rand() % 5 + 5;
	dq2 = rand() % 5 + 5;
	dx2a = &dx2;
	dy2a = &dy2;
	dx21 = dx2;
	dy21 = dy2;
	dx21a = &dx21;
	dy21a = &dy21;
	djian = 1;
}

// ���
int qibinged, qi, x3, y3, p3, q3, *x3a, *y3a;
float x31, y31, *x31a, *y31a;
void qibing() {
	map[x3][y3] = 0;
	qibinged = 0;
	qi = 0;
	x3 = 14;
	y3 = 15;
	p3 = 10;
	q3 = 14;
	x3a = &x3;
	y3a = &y3;
	x31 = x3;
	y31 = y3;
	x31a = &x31;
	y31a = &y31;
}

//
int dqibinged, dqi, dx3, dy3, dp3, dq3, *dx3a, *dy3a;
float dx31, dy31, *dx31a, *dy31a;
void dqibing() {
	map[dx3][dy3] = 0;
	srand(time(0));
	dqibinged = 0;
	dqi = 0;
	dx3 = 0;
	dy3 = 4;
	dp3 = 2 + rand() % 5 + 5;
	dq3 = rand() % 5 + 5;
	dx3a = &dx3;
	dy3a = &dy3;
	dx31 = dx3;
	dy31 = dy3;
	dx31a = &dx31;
	dy31a = &dy31;
}

// ���
int shenbinged, shen, x4, y4, p4, q4, *x4a, *y4a;
float x41, y41, *x41a, *y41a;
void shenbing() {
	map[x4][y4] = 0;
	shenbinged = 0;
	shen = 0;
	x4 = 14;
	y4 = 15;
	p4 = 9;
	q4 = 14;
	x4a = &x4;
	y4a = &y4;
	x41 = x4;
	y41 = y4;
	x41a = &x41;
	y41a = &y41;
}

//
int dshenbinged, dshen, dx4, dy4, dp4, dq4, *dx4a, *dy4a;
float dx41, dy41, *dx41a, *dy41a;
void dshenbing() {
	map[dx4][dy4] = 0;
	srand(time(0));
	dshenbinged = 0;
	dshen = 0;
	dx4 = 0;
	dy4 = 4;
	dp4 = 3 + rand() % 5 + 5;
	dq4 = rand() % 5 + 5;
	dx4a = &dx4;
	dy4a = &dy4;
	dx41 = dx4;
	dy41 = dy4;
	dx41a = &dx41;
	dy41a = &dy41;
}

// ��
int zhued, zhu, x5, y5, p5, q5, *x5a, *y5a;
float x51, y51, *x51a, *y51a;
void zhuu() {
	map[x5][y5] = 0;
	zhued = 0;
	zhu = 0;
	x5 = 14;
	y5 = 15;
	p5 = 13;
	q5 = 13;
	x5a = &x5;
	y5a = &y5;
	x51 = x5;
	y51 = y5;
	x51a = &x51;
	y51a = &y51;
}

//
int dzhued, dzhu, dx5, dy5, dp5, dq5, *dx5a, *dy5a;
float dx51, dy51, *dx51a, *dy51a;
void dzhuu() {
	map[dx5][dy5] = 0;
	srand(time(0));
	dzhued = 0;
	dzhu = 0;
	dx5 = 0;
	dy5 = 4;
	dp5 = rand() % 5 + 5;
	dq5 = 1 + rand() % 5 + 5;
	dx5a = &dx5;
	dy5a = &dy5;
	dx51 = dx5;
	dy51 = dy5;
	dx51a = &dx51;
	dy51a = &dy51;
}

// ������
int jiqirened, ji, x6, y6, p6, q6, *x6a, *y6a;
float x61, y61, *x61a, *y61a;
void jiqiren() {
	map[x6][y6] = 0;
	jiqirened = 0;
	ji = 0;
	x6 = 14;
	y6 = 15;
	p6 = 7;
	q6 = 14;
	x6a = &x6;
	y6a = &y6;
	x61 = x6;
	y61 = y6;
	x61a = &x61;
	y61a = &y61;
}

//
int djiqirened, dji, dx6, dy6, dp6, dq6, *dx6a, *dy6a;
float dx61, dy61, *dx61a, *dy61a;
void djiqiren() {
	map[dx6][dy6] = 0;
	srand(time(0));
	djiqirened = 0;
	dji = 0;
	dx6 = 0;
	dy6 = 4;
	dp6 = rand() % 5 + 5;
	dq6 = 2 + rand() % 5 + 5;
	dx6a = &dx6;
	dy6a = &dy6;
	dx61 = dx6;
	dy61 = dy6;
	dx61a = &dx61;
	dy61a = &dy61;
}

// Ӣ��
int yingxionged, ying, x7, y7, p7, q7, *x7a, *y7a;
float x71, y71, *x71a, *y71a;
void yingxiong() {
	map[x7][y7] = 0;
	yingxionged = 0;
	ying = 3;
	x7 = 14;
	y7 = 15;
	p7 = 14;
	q7 = 13;
	x7a = &x7;
	y7a = &y7;
	x71 = x7;
	y71 = y7;
	x71a = &x71;
	y71a = &y71;
}

//
int dyingxionged, dying, dx7, dy7, dp7, dq7, *dx7a, *dy7a;
float dx71, dy71, *dx71a, *dy71a;
void dyingxiong() {
	map[dx7][dy7] = 0;
	srand(time(0));
	dyingxionged = 0;
	dying = 3;
	dx7 = 0;
	dy7 = 4;
	dp7 = rand() % 5 + 5;
	dq7 = 3 + rand() % 5 + 5;
	dx7a = &dx7;
	dy7a = &dy7;
	dx71 = dx7;
	dy71 = dy7;
	dx71a = &dx71;
	dy71a = &dy71;
}

// ��ʦ
int fashied, fa, x8, y8, p8, q8, *x8a, *y8a;
float x81, y81, *x81a, *y81a;
void fashi() {
	map[x8][y8] = 0;
	fashied = 0;
	fa = 0;
	x8 = 14;
	y8 = 15;
	p8 = 13;
	q8 = 11;
	x8a = &x8;
	y8a = &y8;
	x81 = x8;
	y81 = y8;
	x81a = &x81;
	y81a = &y81;
}

//
int dfashied, dfa, dx8, dy8, dp8, dq8, *dx8a, *dy8a;
float dx81, dy81, *dx81a, *dy81a;
void dfashi() {
	map[dx8][dy8] = 0;
	srand(time(0));
	dfashied = 0;
	dfa = 0;
	dx8 = 0;
	dy8 = 4;
	dp8 = 3;
	dq8 = 5;
	dx8a = &dx8;
	dy8a = &dy8;
	dx81 = dx8;
	dy81 = dy8;
	dx81a = &dx81;
	dy81a = &dy81;
}

// ����
int jurened, ju, x9, y9, p9, q9, *x9a, *y9a;
float x91, y91, *x91a, *y91a;
void juren() {
	map[x9][y9] = 0;
	jurened = 0;
	ju = 30;
	x9 = 14;
	y9 = 15;
	p9 = 14;
	q9 = 11;
	x9a = &x9;
	y9a = &y9;
	x91 = x9;
	y91 = y9;
	x91a = &x91;
	y91a = &y91;
}

//
int djurened, dju, dx9, dy9, dp9, dq9, *dx9a, *dy9a;
float dx91, dy91, *dx91a, *dy91a;
void djuren() {
	map[dx9][dy9] = 0;
	srand(time(0));
	djurened = 0;
	dju = 30;
	dx9 = 0;
	dy9 = 4;
	dp9 = 2 + rand() % 5 + 5;
	dq9 = 2 + rand() % 5 + 5;
	dx9a = &dx9;
	dy9a = &dy9;
	dx91 = dx9;
	dy91 = dy9;
	dx91a = &dx91;
	dy91a = &dy91;
}

// ��ʼ��Դ(��Ҫ���ס�_��)
int food = 300, food1, pig = 1, piged = 0;
int mood = 300, mood1, tree = 1, mooded = 0;
int gold = 200, gold1, coin = 1, coined = 0;

// �˿�(Ѫ��)
int people = 2000, people1, human = 1, total = 100;
int dpeople = 2000, dpeople1, dtotal = 100;
//
int paoloued = 0;
int pao = 1;
int dpao = 1;
int jianzhuxueed = 0;
int duanzaoshued = 0;
int anheicailiaoed = 0;
int junshililuned = 0;
int arm = 0;
int yaned = 0;
int marketed = 0;
int chengbaoed = 0;
int qijied = 0;
int jiange = 300;
int nian;
void start();
void null();
void (*pi) () = null;
void buy();
void draw();
void position();
void soldier();
void zhujuan();
void jinkuang();
void mucai();
void yanjiu();
void chengbao();
void shichang();
void qiji();
void enemy();
void fighter();
void destroy();
void die();
void final();
int remain, *fighter1, *fighter2;
void (*binged1) (), (*binged2) ();
char key;
//
void move(int a, int b, int *x, int *y, float *x1, float *y1, int p, int q, float c);
void keyy(char *aa1, char *bb1, char *cc1, char *dd1, char *ee1, char *ff1);
int markmove = 0, wall = 0;
void diguo() {
	printf
	("X+Y=Z�Ǵӵ���������ʼ����ͬ������һֱ�ڷ����ų�ͻ��ֱ������ʱ�����ڣ�DARK������쳣ǿ������̵�ֳ�����֣�ʹ�����ø��Ӻڰ�����������������ֱ�ӽ���ڰ�ʱ������Ҳʹ�ô󲿷����˲�������ϣ����������ϲ���LIGHT�����ǣ�LIGHT�����ʵ����Ȼ��DARK�����кܴ��࣬�ھ�����ֻ�в�����ս�����ƺź첽����ΪDARK�����к�ǿ�����������LIGHT������˶�����Ȧ���о��������Ͼ������ۿΡ�"
	 "��Ȧ��Ȧ��PIG���˺ܶ���������ɫ�ģ����ڲ���ʱ�����ڲ�û���г������ױȽ��鷳������PIG���齨���г�������ʹ�ø�����Դ���г��Ľ����������ܹ�����������á�LIGHT�����ܹ����õķ�չ��DARK�����к�ǿ��ľ��ӣ����󳣹���������ƺ�D���������ƺ�D��������ƺ�D��ڰ���12�꣬DARK������֣�������ٽ�����LIGHT��ʧ���أ������ܻ�����Ȧ�ڸ�Ԫ�����ۣ�Ԫ��1��D��̫�죬��ô�죿Ԫ��2�����Ǻ첽����̫�̻�û����D��ͱ������ˡ�Ԫ��3���ţ���ʱ����������ˡ�Ԫ��1���ԣ������ٶȿ���������Ȼ��ˤ������ˤ���ˡ�Ԫ��2���ԣ������̹����������������ļ��죬DARK�Ľ�����������������ΪDARK����ʮ��D�ˤ�����򡣲���LIGHTҲ�����ܣ��˼�������·��̫�����̹�û�����ã���D��ȫ������PIG�Ͼ������ۿ�����ʦ�����������Ҳ�򲻹����������ż�������ͷ���ⲻ���������г�û����ô�졣����ʦ˵��˵�е����������Ըɵ����󳣹�����������ʦ���ˣ���ʦ˵�úö������ɣ���Ϲ�룬������ȥ�����о�Ժ��˵�����������أ��Ǻǡ�_������ľ�ĳ��ڣ�ľ��ʦ��Ҳ����취�ֵ����֣���������ΧǽҲ���ܵ�һ����ɣ�PIG����ѧ��һ�꽨��ѧ����������ѧ�����������¥Ҳ���Դ������е�������ã���Ȼ�����е�С��һ��PIGȥ����棬�ú��棬�����������ʦ���ж���Ķ���ʦ���д����Ĵ���ʦ����ƴװ��ƴװʦ���е纸�ĵ纸ʦ���С����ġ���ʦ������PIG��һ����ʦ���֪�öණ��Ū��������Ҫ�����о�Ժ�ͺ��ˣ�����PIG����ͼǿ������ѧ��һ�����������ȥľ�ĳ�ѧ��һ�꽨��ѧ���ۣ����ڿ��Խ��о�Ժ��Ү��PIG�õ�����ʦ�ı���������ѧ������һ�꣬һ�꺮����PIG�Դ������ˣ���֪��Ū����ʲô���������ɫ�ģ�������ģ�����˵��������ʦ�����ӡ�û��ֱ���ӵ�DARK��ǰ���ԡ�������ͦ��DARK�Ż��ˡ����ǵ�����������XY֮ս����һս�����ˣ�֮��LIGHT�����ʵķ�Ծ����XY֮ս��LIGHT�����ˣ����󳣹����������������Ƕ�����ʲô����Ϊ���ֿ���DARK���ܶ�ʱ��LIGHT����ռ�Ϸ磬���о�Ժ���˲ų���һ����ĸ߿�ѡ�γ��˴����˲ţ������ε�ĥ�£����˺��г���Ψһһ��Ӣ��BANANA�������ޱ�ǿ����ս�����ܿ�����һ�˿���з�һ֧���ӣ�����BANANA�������ǵİ������������þ�������һ�Σ���һ�������֧���֮�󣬿��°�ĭ�������ɸ�������ٲ��������о�Ժ���ѡ�γ���һλӢ�ۣ�����Ϊ�˼���BANANAҲ����λӢ��BANANA���ٲ������ǲ���DARK��һλ�ͽ�����Ҳ�൱ǿ������ȫ����а��Ļ�������һ�����á�DARK�������˷�ʦ��ֱ�ӹ�������������Ȧ�ֻ�Ծ������PIG����һ��������ۣ����ַ�ʦ���У�LIGHTҲ�з�ʦ����ս������󾭸���Ŭ�������ڣ�ֻ��DARK��ǿӮ��ʤ������ս���У�Ϊ�������õĲ����������и������Դ���о�Ժ��취����µ���Դ������Ȧ����󳧣�ľ�ĳ����и����о����׷������������ҵ�������Դ��LIGHT��չ�������ʵķ�Ծ����˵��չ�ǿ��ˣ�����DARK�Ľ���Ҳ�������ˣ�LIGHT�ڲ����ң��и������ΪûǮ��ѧ��һ�꽨��ѧ����һ���Ǳ���PIG�ڿ󳧶�������ڲ��ϣ��ܹ������漣���ٻ�����DESTROY���漣�ÿ��ۣ���������ؽ���԰ʹ�����˿����ӣ�-_-||�಻��ȥ�ˣ�����LIGHT��DARKһֱ��ս���š�����\n���������\n");
	getch();
	bubing();
	gongbing();
	qibing();
	shenbing();
	zhuu();
	jiqiren();
	yingxiong();
	fashi();
	juren();
	dbubing();
	dgongbing();
	dqibing();
	dshenbing();
	dzhuu();
	djiqiren();
	dyingxiong();
	dfashi();
	djuren();
	start();
}

void start() {
	while (1) {
		while (kbhit()) {
			key = getch();
			if (key == '6') {
				map[x][y] = 0;
				y++;
			} else if (key == '4') {
				map[x][y] = 0;
				y--;
			} else if (key == '2') {
				map[x][y] = 0;
				x--;
			} else if (key == '8') {
				map[x][y] = 0;
				x++;
			} else if (key == '1') {
				map[x][y] = 0;
				x--;
				y--;
			} else if (key == '3') {
				map[x][y] = 0;
				x--;
				y++;
			} else if (key == '7') {
				map[x][y] = 0;
				x++;
				y--;
			} else if (key == '9') {
				map[x][y] = 0;
				x++;
				y++;
			} else if (key == '0')
				while (1) {
					printf("\n\033[21;0H��ͣ�С�����\b\b\033[0m");
					while (kbhit()) {
						key = getch();
						if (key == '0')
							start();
					}
					usleep(100000);
				} else if (key == '5') {
				if (markmove == 1) {
					strcpy(str, "OK");
					p1 = x;
					q1 = y;
					markmove = 0;
				}
				if (markmove == 2) {
					strcpy(str, "��Ȼ");
					p2 = x;
					q2 = y;
					markmove = 0;
				}
				if (markmove == 3) {
					strcpy(str, "û����");
					p3 = x;
					q3 = y;
					markmove = 0;
				}
				if (markmove == 4) {
					strcpy(str, "�����");
					p4 = x;
					q4 = y;
					markmove = 0;
				}
				if (markmove == 5) {
					strcpy(str, "û��");
					p5 = x;
					q5 = y;
					markmove = 0;
				}
				if (markmove == 6) {
					strcpy(str, "Of course");
					p6 = x;
					q6 = y;
					markmove = 0;
				}
				if (markmove == 7) {
					strcpy(str, "��");
					p7 = x;
					q7 = y;
					markmove = 0;
				}
				if (markmove == 8) {
					strcpy(str, "���");
					p8 = x;
					q8 = y;
					markmove = 0;
				}
				if (markmove == 9) {
					strcpy(str, "er~~");
					p9 = x;
					q9 = y;
					markmove = 0;
				}
				if (x == 14 && y == 19) {
					strcpy(str, "�ҵ�����,��Ҫ����ʲô\n");

					buy();

				}
				if ((x == 14 && y == 17) && (arm == 7)) {

					strcpy(str, "�ҵ�������ץ׳����\n");
					soldier();
				}
				if ((x == x1) && (y == y1) && (bubinged == 8)) {

					strcpy(str, "���ң��Ҳ�������\n");
					markmove = 1;
				}
				if ((x == x2) && (y == y2) && (gongbinged == 9)) {

					strcpy(str, "���䲻����\n");
					markmove = 2;
				}
				if ((x == x3) && (y == y3) && (qibinged == 10)) {

					strcpy(str, "���˽�����������֮��\n");
					markmove = 3;
				}
				if ((x == x4) && (y == y4) && (shenbinged == 11)) {

					strcpy(str, "û�������赲��\n");
					markmove = 4;
				}
				if ((x == x5) && (y == y5) && (zhued == 12)) {

					strcpy(str, "�������ҽ���\n");
					markmove = 5;
				}
				if ((x == x6) && (y == y6) && (jiqirened == 13)) {

					strcpy(str, "�Ҳ������ʱ���Ĳ�����\n");
					markmove = 6;
				}
				if ((x == x7) && (y == y7) && (yingxionged == 14)) {

					strcpy(str, "Ը��Ϊ��Ч��\n");
					markmove = 7;
				}
				if ((x == x8) && (y == y8) && (fashied == 15)) {

					strcpy(str, "���ںڰ�������\n");
					markmove = 8;
				}
				if ((x == x9) && (y == y9) && (jurened == 16)) {

					strcpy(str, "���Ƕ���С��\n");
					markmove = 9;
				}
				if ((x == 13 && y == 18) && (coined == 6)) {
					strcpy(str, "��󳧿������ӽ�Ҳ���\n");
					jinkuang();
				}
				if ((x == 14 && y == 18) && (piged == 4)) {
					strcpy(str, "��Ȧ������ʳ�����\n");
					zhujuan();
				}
				if ((x == 13 && y == 19) && (mooded == 5)) {
					strcpy(str, "ľ�ĳ�������ľ�Ĳ���\n");
					mucai();
				}
				if ((x == 12 && y == 19) && (yaned == 2)) {
					strcpy(str, "֪ʶ���������������������ڸ߿�\n");
					yanjiu();
				}
				if ((x == 12 && y == 18) && (marketed == 30)) {
					strcpy(str, "����������¥������\n");
					shichang();
				}
				if ((x == 12 && y == 17) && (chengbaoed == 33)) {
					strcpy(str, "����,��Ҫ�����ֲ�˼��,С���Ҵ�λ����?? \n");
					chengbao();
				}
				if ((x == 13 && y == 17) && (qijied == 34)) {
					strcpy(str, "���������Ľᾧ\n");
					qiji();
				}
			}
			if (x < 0)
				x++;
			if (x > 14)
				x--;
			if (y < 0)
				y++;
			if (y > 19)
				y--;
		}
		position();
		draw();
		usleep(100000);
	}
}

void position() {
	map[14][19] = 3;			// ��
	map[14][18] = piged;		// Ȧ
	map[13][19] = mooded;		// ľ
	map[13][18] = coined;		// ��
	map[12][18] = marketed;		// ��
	map[12][19] = yaned;		// ��
	map[14][17] = arm;			// ��
	map[11][16] = paoloued;		// ��
	map[12][17] = chengbaoed;
	map[13][17] = qijied;
	map[0][0] = 41;
}

int jjj = 0, kkk = 0, lll = 0, ooo = 0, action;
void die() {
	if (dbu < 1)
		dbubing();
	if (dgong < 1)
		dgongbing();
	if (dqi < 1)
		dqibing();
	if (dshen < 1)
		dshenbing();
	if (dzhu < 1)
		dzhuu();
	if (dji < 1)
		djiqiren();
	if (dying < 1)
		dyingxiong();
	if (dfa < 1)
		dfashi();
	if (dju < 1)
		djuren();
	if (bu < 1)
		bubing();
	if (gong < 1)
		gongbing();
	if (qi < 1)
		qibing();
	if (shen < 1)
		shenbing();
	if (zhu < 1)
		zhuu();
	if (ji < 1)
		jiqiren();
	if (ying < 1)
		yingxiong();
	if (fa < 1)
		fashi();
	if (ju < 1)
		juren();
}

void draw() {					// �������
	for (i = 0; i < 2; i++)		// ��
		for (j = 7 + i; j < 17; j++)
			map[i][j] = 63;
	for (i = 0; i < 4; i++)
		for (j = 18; j < 20; j++)
			map[i][j] = 63;
	for (i = 3; i < 6; i++)		// ˮ
		for (j = 10; j < 16; j++)
			map[i][j] = 61;
	for (i = 4; i < 5; i++)
		for (j = 17; j < 20; j++)
			map[i][j] = 61;
	for (i = 0; i < 4; i++)
		for (j = 17; j < 18; j++)
			map[i][j] = 61;
	for (j = 7; j < 10; j++)
		for (i = 9; i < 11; i++)
			map[i][j] = 62;
	map[8][5] = 63;
	map[11][2] = 63;
	map[6][3] = 63;
	map[13][8] = 63;
	map[8][12] = 64;
	map[4][7] = 64;
	if (wall == 1) {
		for (i = 10; i < 11; i++)
			for (j = 15; j < 20; j++)
				map[i][j] = 31;
		for (j = 15; j < 16; j++)
			for (i = 11; i < 14; i++)
				map[i][j] = 31;
	}
	// ���Զ���λ��λ
	map[x1][y1] = bubinged;		// ����8
	map[x2][y2] = gongbinged;	// ����9
	map[x3][y3] = qibinged;		// ���10
	map[x4][y4] = shenbinged;	// ���11
	map[x5][y5] = zhued;		// ��12
	map[x6][y6] = jiqirened;	// ������13
	map[x7][y7] = yingxionged;	// Ӣ��14
	map[x8][y8] = fashied;		// ��ʦ15
	map[x9][y9] = jurened;		// ����16
	map[dx1][dy1] = dbubinged;	// ����81
	map[dx2][dy2] = dgongbinged;	// ����82
	map[dx3][dy3] = dqibinged;	// ���83
	map[dx4][dy4] = dshenbinged;	// ���84
	map[dx5][dy5] = dzhued;
	map[dx6][dy6] = djiqirened;	// ������86
	map[dx7][dy7] = dyingxionged;	// Ӣ��87
	map[dx8][dy8] = dfashied;	// ��ʦ88
	map[dx9][dy9] = djurened;	// ����89
	map[14][15] = 35;
	map[0][4] = 52;
	if (jian == 1) {
		jianshi = shijian;
	} else if (jian < 1) {
		if (shijian - jianshi == 300) {
			jianshi = shijian;
			jian = 1;
		}
	}
	if (paoloued == 32) {
		if (shijian - jjj > 5) {
			jjj = shijian;
			if (map[11][14] == 81) {
				dbu = dbu - pao;
			}
			if (map[11][14] == 82) {
				dgong = dgong - pao;
			}
			if (map[11][14] == 83) {
				dqi = dqi - pao;
			}
			if (map[11][14] == 84) {
				dshen = dshen - pao;
			}
			if (map[11][14] == 85) {
				dzhu = dzhu - pao;
			}
			if (map[11][14] == 88) {
				dfa = dfa - pao;
			}
		}
	}
	if (map[3][3] == 49) {
		if (shijian - lll > 5) {
			lll = shijian;
			if (map[3][5] == 8) {
				bu = bu - dpao;
			}
			if (map[3][5] == 9) {
				gong = gong - dpao;
			}
			if (map[3][5] == 10) {
				qi = qi - dpao;
			}
			if (map[3][5] == 11) {
				shen = shen - dpao;
			}
			if (map[3][5] == 12) {
				zhu = zhu - dpao;
			}
			if (map[3][5] == 15) {
				fa = fa - dpao;
			}
		}
	}
	fighter();
	if (map[x][y] == 0)
		strcpy(str, "�����������������");
	else if (map[x][y] == 2)
		strcpy(str, "�о�Ժ");
	else if (map[x][y] == 3)
		strcpy(str, "����");
	else if (map[x][y] == 4)
		strcpy(str, "��Ȧ");
	else if (map[x][y] == 5)
		strcpy(str, "ľ�ĳ�");
	else if (map[x][y] == 6)
		strcpy(str, "��");
	else if (map[x][y] == 7)
		strcpy(str, "��Ӫ");
	else if (map[x][y] == 30)
		strcpy(str, "�г�");
	else if (map[x][y] == 31)
		strcpy(str, "��ǽ");
	else if (map[x][y] == 32)
		strcpy(str, "��¥");
	else if (map[x][y] == 33)
		strcpy(str, "�Ǳ�");
	else if (map[x][y] == 34)
		strcpy(str, "�漣");
	if (map[x][y] == 0 || map[x][y] == 1)
		temp = 1;				// �I
	else
		temp = 80;
	map[x][y] = temp;
	system("cls");
	how(1, a);
	how(40, b);
	how(1, c);
	printf("\n");
	for (i = 0; i < 15; i++) {
		how(1, o);
		for (j = 0; j < 20; j++) {
			if (map[i][j] == 80)
				printf("\033[40;33m? \033[0m");
			else if (map[i][j] == 1)
				printf("\033[40;33m�I \033[0m");
			else if (map[i][j] == 2)
				printf("\033[45;37m��\033[0m");
			else if (map[i][j] == 3)
				printf("\033[43;31m��\033[0m");
			else if (map[i][j] == 4)
				printf("\033[41;37mȦ\033[0m");
			else if (map[i][j] == 5)
				printf("\033[42;31mľ\033[0m");
			else if (map[i][j] == 6)
				printf("\033[43;30m��\033[0m");
			else if (map[i][j] == 7)
				printf("\033[44;37m��\033[0m");
			else if (map[i][j] == 8)
				printf("\033[41m%2d\033[0m", bu);
			else if (map[i][j] == 9)
				printf("\033[42m%2d\033[0m", gong);
			else if (map[i][j] == 10)
				printf("\033[43m%2d\033[0m", qi);
			else if (map[i][j] == 11)
				printf("\033[45m%2d\033[0m", shen);
			else if (map[i][j] == 12)
				printf("\033[46m%2d\033[0m", zhu);
			else if (map[i][j] == 13)
				printf("\033[44m%2d\033[0m", ji);
			else if (map[i][j] == 14)
				printf("\033[40;33m��\033[0m");
			else if (map[i][j] == 15)
				printf("\033[40m%2d\033[0m", fa);
			else if (map[i][j] == 16)
				printf("\033[40;32m��\033[0m");
			else if (map[i][j] == 30)
				printf("\033[46;31m��\033[0m");
			else if (map[i][j] == 31)
				printf("\033[40;37m���\033[0m");
			else if (map[i][j] == 32)
				printf("\033[41;37m��\033[0m");
			else if (map[i][j] == 33)
				printf("\033[43;30m��\033[0m");
			else if (map[i][j] == 34)
				printf("\033[42;30m��\033[0m");
			else if (map[i][j] == 35)
				printf("\033[40;33m�� \033[0m");
			else if (map[i][j] == 41)
				printf("\033[43;31m��\033[0m");
			else if (map[i][j] == 42)
				printf("\033[41;37mȦ\033[0m");
			else if (map[i][j] == 43)
				printf("\033[42;31mľ\033[0m");
			else if (map[i][j] == 44)
				printf("\033[43;30m��\033[0m");
			else if (map[i][j] == 45)
				printf("\033[45;37m��\033[0m");
			else if (map[i][j] == 46)
				printf("\033[44;37m��\033[0m");
			else if (map[i][j] == 47)
				printf("\033[46;31m��\033[0m");
			else if (map[i][j] == 48)
				printf("\033[40;37m��\033[0m");
			else if (map[i][j] == 49)
				printf("\033[41;37m��\033[0m");
			else if (map[i][j] == 50)
				printf("\033[43;30m��\033[0m");
			else if (map[i][j] == 51)
				printf("\033[42;30m��\033[0m");
			else if (map[i][j] == 52)
				printf("\033[40;33m�� \033[0m");
			else if (map[i][j] == 61)
				printf("\033[44;36m~~\033[0m");
			else if (map[i][j] == 62)
				printf("\033[41;37m��\033[0m");
			else if (map[i][j] == 63)
				printf("\033[42;31m�զ�\033[0m");
			else if (map[i][j] == 64)
				printf("\033[43;35m����\033[0m");
			else if (map[i][j] == 81)
				printf("\033[41;30m%2d\033[0m", dbu);
			else if (map[i][j] == 82)
				printf("\033[42;30m%2d\033[0m", dgong);
			else if (map[i][j] == 83)
				printf("\033[43;30m%2d\033[0m", dqi);
			else if (map[i][j] == 84)
				printf("\033[45;30m%2d\033[0m", dshen);
			else if (map[i][j] == 85)
				printf("\033[46;30m%2d\033[0m", dzhu);
			else if (map[i][j] == 86)
				printf("\033[44;30m%2d\033[0m", dji);
			else if (map[i][j] == 87)
				printf("\033[40;33mӢ\033[0m");
			else if (map[i][j] == 88)
				printf("\033[40;32m%2d\033[0m", dfa);
			else if (map[i][j] == 89)
				printf("\033[40;32m��\033[0m");
			else
				printf("\033[40m  \033[0m");
		}
		how(1, o);
		printf("\n");
	}
	how(1, g);
	how(40, b);
	how(1, h);
	printf("\n");
	how(1, u);
	printf("\033[41m��\033[0m%d/%d ", dpeople1, dtotal);
	if (fa > 0)
		dpeople -= 1 * fa;
	if (dpeople1 < dtotal) {
		dpeople += 1;
	}
	dpeople1 = dpeople / 20;
	printf("\033[43;31m��\033[0m%d ", gold1);
	gold += coin;
	gold1 = (gold / 20);
	printf("\033[42;31mľ\033[0m%d ", mood1);
	mood += tree;
	mood1 = (mood / 20);
	printf("\033[41;37mʳ\033[0m%d ", food1);
	food += pig;
	food1 = (food / 20);
	printf("\033[43;34m��\033[0m%d/%d\n", people1, total);
	if (dfa > 0)
		people -= 1 * dfa;
	if (people1 != total) {
		people += human;
		if (human == 3)
			gold -= 1;
		if (human == 5)
			gold -= 3;
	}
	people1 = (people / 20);
	printf(" \033[46;44mʱ\033[0m\033[40;32m�ڰ���\033[0m%d�� ", nian);
	nian = shijian / 10;
	shijian = shijian + 1;
	if (gongbinged == 9)
		printf("\033[40;33;5m����װ��\033[0m%d(%s)", 30 - (shijian - jianshi) / 10,
		       (30 - (shijian - jianshi) / 10 == 30) ? ("װ�����") : ("װ����"));
	printf("\n");
	how(5, u);
	printf("\033[40;33;5m����PIG��\033[0m\033[36;5m%s \033[0m\n", str);
	enemy();
	destroy();
	die();
	if (dpeople < 0 || people < 0)
		final();
	move(bubinged, 8, x1a, y1a, x11a, y11a, p1, q1, 0.05);
	move(dbubinged, 81, dx1a, dy1a, dx11a, dy11a, dp1, dq1, 0.05);
	move(gongbinged, 9, x2a, y2a, x21a, y21a, p2, q2, 0.05);
	move(dgongbinged, 82, dx2a, dy2a, dx21a, dy21a, dp2, dq2, 0.05);
	move(qibinged, 10, x3a, y3a, x31a, y31a, p3, q3, 0.1);
	move(dqibinged, 83, dx3a, dy3a, dx31a, dy31a, dp3, dq3, 0.1);
	move(shenbinged, 11, x4a, y4a, x41a, y41a, p4, q4, 0.05);
	move(dshenbinged, 84, dx4a, dy4a, dx41a, dy41a, dp4, dq4, 0.05);
	move(zhued, 12, x5a, y5a, x51a, y51a, p5, q5, 0.05);
	move(dzhued, 85, dx5a, dy5a, dx51a, dy51a, dp5, dq5, 0.05);
	move(jiqirened, 13, x6a, y6a, x61a, y61a, p6, q6, 0.02);
	move(djiqirened, 86, dx6a, dy6a, dx61a, dy61a, dp6, dq6, 0.02);
	move(yingxionged, 14, x7a, y7a, x71a, y71a, p7, q7, 0.05);
	move(dyingxionged, 87, dx7a, dy7a, dx71a, dy71a, dp7, dq7, 0.05);
	move(fashied, 15, x8a, y8a, x81a, y81a, p8, q8, 0.05);
	move(dfashied, 88, dx8a, dy8a, dx81a, dy81a, dp8, dq8, 0.05);
	move(jurened, 16, x9a, y9a, x91a, y91a, p9, q9, 0.02);
	move(djurened, 89, dx9a, dy9a, dx91a, dy91a, dp9, dq9, 0.02);
}

void final() {
	while (1) {
		system("cls");
		if (dpeople < 0)
			printf("��Ӯ��\n");
		else if
		(people < 0)
			printf("������\n");
		usleep(100000);
	}
}

void destroy() {	// ����
	if (map[14][14] == 81) {
		people = people - 160 * dbu;
		dbubing();
	}
	if (map[14][14] == 82) {
		people = people - 80 * dgong;
		dgongbing();
	}
	if (map[14][14] == 83) {
		people = people - 240 * dqi;
		dqibing();
	}
	if (map[14][14] == 84) {
		people = people - 400 * dshen;
		dshenbing();
	}
	if (map[14][14] == 85) {
		people = people - 40 * dzhu;
		dzhuu();
	}
	if (map[14][14] == 86) {
		people = people - 800 * dji;
		djiqiren();
	}
	if (map[14][14] == 87) {
		people = people - 1000;
		dyingxiong();
	}
	if (map[14][14] == 88) {
		people = people - 400 * dfa;
		dfashi();
	}
	if (map[14][14] == 89) {
		people = people - 200 * dju;
		djuren();
	}
	if (map[0][5] == 8) {
		dpeople = dpeople - 160 * bu;
		bubing();
	}
	if (map[0][5] == 9) {
		dpeople = dpeople - 80 * gong;
		gongbing();
	}
	if (map[0][5] == 10) {
		dpeople = dpeople - 240 * qi;
		qibing();
	}
	if (map[0][5] == 11) {
		dpeople = dpeople - 400 * shen;
		shenbing();
	}
	if (map[0][5] == 12) {
		dpeople = dpeople - 40 * zhu;
		zhuu();
	}
	if (map[0][5] == 13) {
		dpeople = dpeople - 800 * ji;
		jiqiren();
	}
	if (map[0][5] == 14) {
		dpeople = dpeople - 1000;
		yingxiong();
	}
	if (map[0][5] == 15) {
		dpeople = dpeople - 400 * fa;
		fashi();
	}
	if (map[0][5] == 16) {
		dpeople = dpeople - 200 * ju;
		juren();
	}
}

void fighter() {				// ����
	float power1 = 1., power2 = 1.;
	for (i = 0; i < 15; i++)
		for (j = 0; j < 20; j++) {
			m = 0;
			n = 0;
			if (map[i][j] == 82) {
				if (map[i][j + 2] >= 8 && map[i][j + 2] < 17) {
					m = i;
					n = j + 2;
				} else if (map[i][j - 2] >= 8 && map[i][j - 2] < 17) {
					m = i;
					n = j - 2;
				} else if (i != 1)
					if (map[i + 2][j] >= 8 && map[i + 2][j] < 17) {
						m = i + 2;
						n = j;
					} else if (map[i - 2][j] >= 8 && map[i - 2][j] < 17) {
						m = i - 2;
						n = j;
					} else if (map[i - 1][j - 1] >= 8 && map[i - 1][j - 1] < 17) {
						m = i - 1;
						n = j - 1;
					} else if (map[i + 1][j + 1] >= 8 && map[i + 1][j + 1] < 17) {
						m = i + 1;
						n = j + 1;
					} else if (map[i - 1][j + 1] >= 8 && map[i - 1][j + 1] < 17) {
						m = i - 1;
						n = j + 1;
					} else if (map[i + 1][j - 1] >= 8 && map[i + 1][j - 1] < 17) {
						m = i + 1;
						n = j - 1;
					}
			}
			if ((map[i][j] > 7) && (map[i][j] < 20)) {
				// ����(Զ��)
				if (map[i][j] == 9) {
					if (map[i][j + 2] >= 81 && map[i][j + 2] < 90) {
						m = i;
						n = j + 2;
					} else if (map[i][j - 2] >= 81 && map[i][j - 2] < 90) {
						m = i;
						n = j - 2;
					} else if (map[i + 2][j] >= 81 && map[i + 2][j] < 90) {
						m = i + 2;
						n = j;
					} else if (map[i - 2][j] >= 81 && map[i - 2][j] < 90) {
						m = i - 2;
						n = j;
					} else if (map[i - 1][j - 1] >= 81 && map[i - 2][j] < 90) {
						m = i - 1;
						n = j - 1;
					} else if (map[i + 1][j + 1] >= 81 && map[i - 2][j] < 90) {
						m = i + 1;
						n = j + 1;
					} else if (map[i - 1][j + 1] >= 81 && map[i - 2][j] < 90) {
						m = i - 1;
						n = j + 1;
					} else if (map[i + 1][j - 1] >= 81 && map[i - 2][j] < 90) {
						m = i + 1;
						n = j - 1;
					}
				}
				// ����
				if (map[i][j + 1] >= 81 || map[i][j - 1] >= 81 || map[i - 1][j] >= 81
				        || map[i + 1][j] >= 81) {
					if (map[i][j + 1] >= 81 && map[i][j + 1] < 90) {
						m = i;
						n = j + 1;
					} else if (map[i][j - 1] >= 81 && map[i][j - 1] < 90) {
						m = i;
						n = j - 1;
					} else if (map[i + 1][j] >= 81 && map[i + 1][j] < 90) {
						m = i + 1;
						n = j;
					} else if (map[i - 1][j] >= 81 && map[i - 1][j] < 90) {
						m = i - 1;
						n = j;
					}
				}
			}
			// ȷ����
			if (map[m][n] == 8) {
				fighter2 = &bu;
				binged2 = bubing;
			} else if (map[m][n] == 9) {
				fighter2 = &gong;
				binged2 = gongbing;
			} else if (map[m][n] == 10) {
				fighter2 = &qi;
				binged2 = qibing;
			} else if (map[m][n] == 11) {
				fighter2 = &shen;
				binged2 = shenbing;
			} else if (map[m][n] == 12) {
				fighter2 = &zhu;
				binged2 = zhuu;
			} else if (map[m][n] == 13) {
				fighter2 = &ji;
				binged2 = jiqiren;
			} else if (map[m][n] == 15)

			{
				fighter2 = &fa;
				binged2 = fashi;
			}
			if (map[m][n] == 81) {
				fighter2 = &dbu;
				binged2 = dbubing;
			} else if (map[m][n] == 82) {
				fighter2 = &dgong;
				binged2 = dgongbing;
			} else if (map[m][n] == 83) {
				fighter2 = &dqi;
				binged2 = dqibing;
			} else if (map[m][n] == 84) {
				fighter2 = &dshen;
				binged2 = dshenbing;
			} else if (map[m][n] == 85) {
				fighter2 = &dzhu;
				binged2 = dzhuu;
			} else if (map[m][n] == 86) {
				fighter2 = &dji;
				binged2 = djiqiren;
			} else if (map[m][n] == 88) {
				fighter2 = &dfa;
				binged2 = dfashi;
			}
			// ȷ����
			if (map[i][j] == 8) {
				fighter1 = &bu;
				binged1 = bubing;
			} else if (map[i][j] == 9) {
				fighter1 = &gong;
				binged1 = gongbing;
			} else if (map[i][j] == 10) {
				fighter1 = &qi;
				binged1 = qibing;
			} else if (map[i][j] == 11) {
				fighter1 = &shen;
				binged1 = shenbing;
			} else if (map[i][j] == 12) {
				fighter1 = &zhu;
				binged1 = zhuu;
			} else if (map[i][j] == 13) {
				fighter1 = &ji;
				binged1 = jiqiren;
			} else if (map[i][j] == 14) {
				fighter1 = &ying;
				binged1 = yingxiong;
			}

			else if (map[i][j] == 15) {
				fighter1 = &fa;
				binged1 = fashi;
			} else if (map[i][j] == 16) {
				fighter1 = &ju;
				binged1 = juren;
			} else if (map[i][j] == 82) {
				fighter1 = &dgong;
				binged1 = dgongbing;
			}
			// ����
			if (map[i][j] == 8 && map[m][n] == 82)
				power1 = 4;
			if (map[i][j] == 10 && map[m][n] == 82)
				power1 = 3;
			else if (map[i][j] == 9 && map[m][n] == 83)
				power1 = 5;
			else if (map[i][j] == 10 && (map[m][n] == 81 || map[m][n] == 82))
				power1 = 4;
			else if (map[i][j] == 11)
				power1 = 6;
			else if (map[i][j] == 12)
				power1 = 0.5;
			else if (map[i][j] == 12 && map[m][n] == 84)
				power1 = 2;
			else if (map[i][j] == 13)
				power1 = 8.;
			else if (map[i][j] == 14) {
				if (map[i][j + 1] >= 81 || map[i][j - 1] >= 81 || map[i - 1][j] >= 81
				        || map[i + 1][j] >= 81) {
					ying -= 1;
					binged2();
				}
			} else if (map[i][j] == 16) {
				if (map[i][j + 1] >= 81 || map[i][j - 1] >= 81 || map[i - 1][j] >= 81
				        || map[i + 1][j] >= 81) {
					ju -= 1;
					*fighter2 = *fighter2 - ju;
				}
			} else if (map[i][j] == 15)
				power1 = 3;
			//
			if (map[i][j] == 9 && map[m][n] == 81)
				power2 = 4;
			else if (map[i][j] == 10 && map[m][n] == 82)
				power2 = 5;
			else if (map[m][n] == 83 && (map[i][j] == 8 || map[i][j] == 9))
				power2 = 4;
			else if (map[m][n] == 84 || map[m][n] == 11)
				power2 = 6;
			else if (map[m][n] == 85 || map[m][n] == 12)
				power2 = 0.5;
			else if (map[i][j] == 11 && map[m][n] == 85)
				power2 = 2;
			else if (map[m][n] == 86 || map[m][n] == 13)
				power2 = 8.;
			else if (map[m][n] == 87) {
				if (map[i][j + 1] >= 81 || map[i][j - 1] >= 81 || map[i - 1][j] >= 81
				        || map[i + 1][j] >= 81) {
					dying -= 1;
					binged1();
				}
			} else if (map[m][n] == 88 || map[m][n] == 15)
				power2 = 3.;
			else if (map[m][n] == 89) {
				if (map[i][j + 1] >= 81 || map[i][j - 1] >= 81 || map[i - 1][j] >= 81
				        || map[i + 1][j] >= 81) {
					dju -= 1;
					*fighter1 = *fighter1 - dju;
				}
			}
			// ���
			if ((map[i][j] > 7) && (map[i][j] < 20)) {
				if (map[i][j + 1] >= 81 || map[i][j - 1] >= 81 || map[i - 1][j] >= 81
				        || map[i + 1][j] >= 81) {
					if (map[i][j] != 14 && map[m][n] != 87 && map[i][j] != 16 && map[m][n] != 89) {
						remain = power1 **fighter1 - power2 **fighter2;
						if (remain > 0) {
							*fighter1 = remain / power1;
							*fighter2 = 0;
						} else {
							*fighter2 = (0 - remain) / power2;
							*fighter1 = 0;
						}
					}
				}
			}
			if (m != 0 || n != 0) {
				if ((map[i][j] == 9 && jian > 0) || (map[i][j] == 82 && djian == 1)) {
					if (map[i][j] == 9)
						jian -= 1;
					if (map[i][j] == 82)
						djian -= 1;
					remain = power1 **fighter1 - power2 **fighter2;
					if (remain > 0) {
						*fighter2 = 0;
					}

					else {
						*fighter2 = (0 - remain) / power2;
					}
				}
			}
		}
}

void enemy() {				// *****�з�����*****
	if (shijian > 200) {
		map[1][0] = 43;			// ľ�ĳ�
		if (shijian < 202) {
			dtotal = dtotal + 20;
			dpeople = dpeople + 400;
		}
	}
	if (shijian > 300) {
		map[2][2] = 42;			// ��Ȧ
		if (shijian < 302) {
			dtotal = dtotal + 20;
			dpeople = dpeople + 400;
		}
	}
	if (shijian > 400) {
		map[2][1] = 46;			// ��Ӫ
		if (shijian < 402) {
			dtotal = dtotal + 10;
			dpeople = dpeople + 200;
		}
	}
	if (shijian > 1000) {
		map[2][0] = 44;			// ���
		if (shijian < 1002) {
			dtotal = dtotal + 20;
			dpeople = dpeople + 400;
		}
	}
	if (shijian > 2000) {
		map[3][3] = 49;			// ��¥
		if (shijian < 2002) {
			dtotal = dtotal + 20;
			dpeople = dpeople + 400;
		}
	}
	if (shijian > 2500) {		// ��ǽ
		jiange = 250;
		for (i = 4; i < 5; i++)
			for (j = 0; j < 5; j++)
				map[i][j] = 48;
		for (j = 4; j < 5; j++)
			for (i = 1; i < 5; i++)
				map[i][j] = 48;
		if (shijian < 2502) {
			dtotal = dtotal + 200;
			dpeople = dpeople + 4000;
		}
	}
	if (shijian > 4000) {
		jiange = 200;
		map[1][2] = 47;			// �г�
		if (shijian < 4002) {
			dtotal = dtotal + 50;
			dpeople = dpeople + 1000;
		}
	}
	if (shijian > 5000) {
		jiange = 150;
		map[1][1] = 45;			// �о�Ժ
		if (shijian < 5002) {
			dtotal = dtotal + 100;
			dpeople = dpeople + 2000;
		}
	}
	if (shijian > 9000) {
		jiange = 100;
		map[0][2] = 50;			// �Ǳ�
		if (shijian < 9002) {
			dtotal = dtotal + 500;
			dpeople = dpeople + 10000;
		}
	}
	if (shijian > 12000) {
		map[0][1] = 51;			// �漣
		if (shijian < 12002) {
			dtotal = dtotal + 960;
			dpeople = dpeople + 960 * 20;
		}
	}
	if (shijian > 13000) {
		dpao = 2;
	}
	for (i = 0; i < 9; i++) {	// �о�����
		for (j = 0; j < 12; j++) {
			if (map[i][j] < 17 && map[i][j] > 7 || (shijian - ooo) > 500 || fa > 0) {
				ooo = shijian;
				dp1 = 14;
				dq1 = 14;
				dp2 = 14;
				dq2 = 14;
				dp3 = 14;
				dq3 = 14;
				dp4 = 14;
				dq4 = 14;
				dp5 = 14;
				dq5 = 14;
				dp6 = 14;
				dq6 = 14;
				dp7 = 14;
				dq7 = 14;
				dp8 = 14;
				dq8 = 14;
				dp9 = 14;
				dq9 = 14;
				for (i = 0; i < 15; i++) {
					for (j = 0; j < 20; j++)

					{
						if (map[i][j] == 9) {
							dp1 = i;
							dq1 = j;
						}
						if (map[i][j] == 10) {
							dp2 = i;
							dq2 = j;
						}
						if (map[i][j] == 8) {
							dp3 = i;
							dq3 = j;
						}
						if (map[i][j] == 10) {
							dp4 = i;
							dq4 = j;
						} else if (map[i][j] == 9) {
							dp4 = i;
							dq4 = j;
						} else if (map[i][j] == 8) {
							dp4 = i;
							dq4 = j;
						}
						if (map[i][j] == 11) {
							dp5 = i;
							dq5 = j;
						}
						if (map[i][j] > 7 && map[i][j] < 17) {
							dp9 = i;
							dq9 = j;
						}
						if (map[i][j] == 15) {
							dp1 = i;
							dq1 = j;
							dp2 = i;
							dq2 = j;
							dp3 = i;
							dq3 = j;
							dp8 = i;
							dq8 = j;
						}
						if (map[i][j] > 7 && map[i][j] < 17) {
							dp7 = i;
							dq7 = j;
						}
					}
				}
			}
		}
	}
	if (map[2][2] == 42) {
		v = 2;
	}

	if (map[2][1] == 46) {
		v = 3;
		if (shijian > 800)
			v = 4;
		if (shijian > 1200)
			v = 5;
	}
	if (map[2][0] == 44) {
		v = 6;
	}
	if (map[1][1] == 45) {
		v = 7;
		if (shijian > 7000)
			v = 8;
		if (shijian > 8000)
			v = 9;
	}
	if (map[0][2] == 50) {
		if (shijian > 10500)
			v = 10;
	}
	if (shijian - kkk > jiange) {	// ����
		kkk = shijian;
		action = rand() % v + 0;
		switch (action) {
			case 0: {
				break;
			}
			case 1: {
				if (dzhu > 90) {
				} else {
					dzhued = 85;
					dzhu = dzhu + (rand() % 10 + 1);
				}
			}
			break;
			case 2: {
				if (dbu > 90) {
				} else {
					dbubinged = 81;
					dbu = dbu + (rand() % 10 + 1);
				}
			}
			break;
			case 3: {
				if (dgong > 90) {
				} else {
					dgongbinged = 82;
					dgong = dgong + (rand() % 10 + 1);
				}
			}
			break;
			case 4: {
				if (dqi > 40) {
				} else {
					dqibinged = 83;
					dqi = dqi + (rand() % 10 + 1);
				}
			}
			break;
			case 5: {
				if (dji > 4) {
				} else {
					djiqirened = 86;
					dji = dji + (rand() % 2 + 1);
				}
			}
			break;
			case 6: {
				if (dshen > 8) {
				} else {
					dshenbinged = 84;
					dshen = dshen + (rand() % 3 + 1);
				}
			}
			break;
			case 7: {
				dyingxionged = 87;
			}
			break;
			case 8: {
				if (dfa > 4) {
				} else {
					dfashied = 88;
					dfa = dfa + (rand() % 5 + 1);
				}
			}
			break;
			case 9: {
				djurened = 89;

			}
			break;
		}
	}
}

void move(int a, int b, int *x, int *y, float *x1, float *y1, int p, int q, float c) {
	if (a == b) {
		int d = *x, e = *y;
		map[*x][*y] = 0;
		*x1 -= c;				// �ٶ�
		*y1 -= c;
		if (map[(int)(*x1)][*y] > 1)
			*x1 = d;
		if (map[*x][(int)(*y1)] > 1)
			*y1 = e;
		if (*x1 < p) {
			*x1 += 2 * c;
			if (map[(int)(*x1)][*y] > 1)
				*x1 = d;
		}
		if (*y1 < q) {
			*y1 += 2 * c;
			if (map[*x][(int)(*y1)] > 1)
				*y1 = e;
		}
		*x = *x1;
		*y = *y1;
	}
}

void buy() {					// ****����****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;

	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1��Ȧ\033[0m10ľ%c\033[42;31m2ľ�ĳ�\033[0m10ľ%c\033[43;31m3���\033[0m10ľ%c\033[45m4��Ӫ\033[0m10ľ%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1': {
					if (piged == 4)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "��Ȧ�ܹ�����ʳ�����\n");
				}
				break;
				case '2': {
					if (mooded == 5)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "ľ�ĳ��ܹ�����ľ�Ĳ���\n");
				}
				break;
				case '3': {
					if (coined == 6)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "����ܹ����ӽ�����\n");
				}
				break;
				case '4': {
					if (arm == 7)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "��Ӫ�ܹ���ļ����\n");
				}
				break;
				case '0':
					strcpy(str, "���߲���\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (piged == 4)
							strcpy(str, "�����ظ�����\n");
						else {
							if (mood < 200)
								strcpy(str, "��Դ����\n");
							else {
								mood = mood - 200;
								pig = 2;
								piged = 4;
								total = total + 10;
								people = people + 200;
								strcpy(str, "����ʩ��,ʳ������ٶ�����\n");
							}
						}
					}			// ��Ȧ
					else if (bb == '>') {
						if (mooded == 5)
							strcpy(str, "�����ظ�����\n");
						else {
							if (mood < 200)
								strcpy(str, "��Դ����\n");
							else {
								mooded = 5;
								mood = mood - 200;
								tree = 2;
								total = total + 10;
								people = people + 200;
								strcpy(str, "����ʩ��,��ľ�ٶ�����\n");
							}
						}
					} else if (cc == '>') {
						if (coined == 6)
							strcpy(str, "�����ظ�����\n");
						else {
							if (mood < 200)
								strcpy(str, "��Դ����\n");
							else {
								coined = 6;
								mood = mood - 200;
								coin = 2;
								total = total + 10;
								people = people + 200;
								strcpy(str, "����ʩ��,ȫ�������������\n");
							}
						}
					} else if (ff == '>') {
						if (arm == 7)
							strcpy(str, "�����ظ�����\n");
						else {
							if (mood < 200)
								strcpy(str, "��Դ����\n");
							else {
								arm = 7;
								mood = mood - 200;
								total = total + 10;
								people = people + 200;
								strcpy(str, "����ʩ��,���������ļʿ����\n");
							}
						}
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}


void null() {
}



void keyy(char *aa1, char *bb1, char *cc1, char *dd1, char *ee1, char *ff1) {
	char aa = *aa1, bb = *bb1, cc = *cc1, ee = *ee1, dd, ff = *ff1;
	dd = getch();
	if (dd == '\n')
		dd = '\n';
	else {
		if (dd == '1') {
			aa = '>';
			bb = ' ';
			cc = ' ';
			ee = ' ';
			ff = ' ';
		} else if (dd == '2') {
			aa = ' ';
			bb = '>';
			cc = ' ';
			ee = ' ';
			ff = ' ';
		} else if (dd == '3') {
			aa = ' ';
			bb = ' ';
			cc = '>';
			ee = ' ';
			ff = ' ';
		} else if (dd == '4') {
			aa = ' ';
			bb = ' ';
			cc = ' ';
			ff = '>';
			ee = ' ';
		} else if (dd == '0') {
			aa = ' ';
			bb = ' ';
			cc = ' ';
			ff = ' ';
			ee = '>';
		}
	}
	*aa1 = aa;
	*bb1 = bb;
	*cc1 = cc;
	*dd1 = dd;
	*ee1 = ee;
	*ff1 = ff;
}

void soldier() {				// ****��Ӫ*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1����\033[0m10ʳ%c\033[42;31m2����\033[0m8ʳ5��%c\033[43;31m3���\033[0m10ʳ10��%c\033[45m4���\033[0m30��10ľ20ʳ%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1':
					strcpy(str, "��ս��λ\n");
					break;
				case '2':
					strcpy(str, "Զ�̵�λ\n");
					break;
				case '3':
					strcpy(str, "�ٹ�\n");
					break;
				case '4':
					strcpy(str, "��˵�еı���\n");
					break;
				case '0':
					strcpy(str, "���߲���\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {	// ����
						if (bu == 99)
							strcpy(str, "�Ѵ�����\n");
						else {
							if (food < 200)
								strcpy(str, "��Դ����\n");
							else {
								food = food - 200;
								bubinged = 8;
								bu = bu + 1;
							}
						}
					} else if (bb == '>') {	// ����
						if (junshililuned == 0)
							strcpy(str, "��̫�̣���\n");
						else {
							if (gong == 99)
								strcpy(str, "�Ѵ�����\n");
							else {
								if (food < 160 || gold < 100)
									strcpy(str, "��Դ����\n");
								else {
									gongbinged = 9;
									food = food - 160;
									gold = gold - 100;
									gong = gong + 1;
								}
							}
						}
					} else if (cc == '>') {	// ���
						if (junshililuned < 2)
							strcpy(str, "̫��̫��\n");
						else {
							if (qi == 50)
								strcpy(str, "�Ѵ�����\n");
							else {
								if (food < 200 || gold < 200)
									strcpy(str, "��Դ����\n");
								else {
									food = food - 200;
									gold = gold - 200;
									qibinged = 10;
									qi = qi + 1;
								}
							}
						}
					} else if (ff == '>') {	// ���
						if (yaned == 2) {
							if (shen == 10)
								strcpy(str, "�Ѵ�����\n");
							else {
								if (mood < 200 || food < 400 || gold < 600)
									strcpy(str, "��Դ����\n");
								else {
									food = food - 400;
									gold = gold - 600;
									mood = mood - 200;
									shenbinged = 11;
									shen = shen + 1;
								}
							}
						} else
							strcpy(str, "ʲô�������û��˵��,�������ȥ��\n");
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}

void zhujuan() {				// ****��Ȧ*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1��\033[0m5ʳ%c\033[42;31m2�г�\033[0m8ʳ10��30ľ%c\033[43;31m3��������\033[0m20ʳ%c\033[45m4������Ȧ\033[0m200��120ľ%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1':
					strcpy(str, "Զ��ʱ�ڣ�����а�������ܴ��ǿ���սʿ\n");
					break;
				case '2': {
					if (marketed == 30)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str,
						       "��������ʣ���ʳ����ȥ�����Լ���Ҫ�Ķ������г�������\n");
				}
				break;
				case '3': {
					if (junshililuned == 1)
						strcpy(str, "��������һ��(������������Դ)\n");
					else if (junshililuned == 2)
						strcpy(str, "�������۶���(������ű���Դ)\n");
					else if (junshililuned == 3)
						strcpy(str, "������\n");
					else
						strcpy(str, "�о��µı��������սʤ��\n");
				}
				break;
				case '4': {
					if (pig != 2)
						strcpy(str, "������\n");
					else
						strcpy(str, "�����ӿ�ʳ������\n");
				}
				break;
				case '0':
					strcpy(str, "�װ�\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (zhu == 99)
							strcpy(str, "�Ѵ�����\n");
						else {
							if (food < 100)
								strcpy(str, "��Դ����\n");
							else {
								food = food - 100;
								zhued = 12;
								zhu = zhu + 1;
							}
						}
					} else if (bb == '>') {
						if (marketed == 30)
							strcpy(str, "�����ظ�����\n");
						else {
							if (mood < 600 || food < 160 || gold < 200)
								strcpy(str, "��Դ����\n");
							else {
								food = food - 160;
								gold = gold - 200;
								mood = mood - 600;
								marketed = 30;
								total = total + 50;
								people = people + 1000;
								strcpy(str, "����ʩ��������Ϳ���������\n");
							}
						}
					} else if (cc == '>') {
						if (junshililuned == 0) {
							if (food < 400)
								strcpy(str, "��Դ����\n");
							else {
								junshililuned = 1;
								food = food - 400;
								strcpy(str,
								       "��������һ����������ļ������(����������������Դ)\n");
							}
						} else if (junshililuned == 1) {
							if (food < 1200)
								strcpy(str, "��Դ����\n");
							else {
								junshililuned = 2;
								food = food - 1200;
								strcpy(str,
								       "�������۶�����������ļ�����(����������ű���Դ)\n");
							}
						} else if (junshililuned == 2) {
							if (food < 3600)
								strcpy(str, "��Դ����\n");
							else {
								junshililuned = 3;
								food = food - 3600;
								strcpy(str,
								       "��������������������ļ��ʦ��(������)\n");
							}
							if (junshililuned == 3)
								strcpy(str, "������ߵȼ�\n");
						}
					}

					else if (ff == '>') {
						if (pig != 2)
							strcpy(str, "���������ˣ�������ô��������Դ��\n");
						else {
							if (mood < 2400 || gold < 4000)
								strcpy(str, "��Դ����\n");
							else {
								strcpy(str, "�����ɹ���ʳ���������\n");
								mood = mood - 2400;
								gold = gold - 4000;
								total = total + 10;
								people = people + 200;
								pig = 4;
							}
						}
					}

					else if (ee == '>')
						start();
				}
			}
		}
	}
}

void jinkuang() {				// ****���*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1�о�Ժ\033[0m20ʳ50��100ľ%c\033[42;31m2������\033[0m50��10ľ%c\033[43;31m3������\033[0m50��20ľ%c\033[45m4������\033[0m100��500ľ%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1': {
					if (yaned == 2)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "����ʦ��������ô�õ��¼���\n");
				}
				break;
				case '2': {
					if (duanzaoshued == 0)
						strcpy(str,
						       "���������������������������죨�ֶ��ҹ���\n");
					else if (duanzaoshued == 1)
						strcpy(str, "������1��(����������������Դ)\n");
					else if (duanzaoshued == 2)
						strcpy(str, "������2��(����������������Դ)\n");
					else if (duanzaoshued == 3)
						strcpy(str, "������\n");
				}
				break;
				case '3':
					strcpy(str, "���������ˣ�׼��\n");
					break;
				case '4': {
					if (coin != 2)
						strcpy(str, "������\n");
					else {
						strcpy(str, "�����ϲ���ͣ��\n");
					}
				}
				break;
				case '0':
					strcpy(str, "�װ�\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (yaned == 2)
							strcpy(str, "�����ظ�����\n");
						else {
							if (duanzaoshued != 0 && jianzhuxueed > 1) {
								if (mood < 2000 || food < 400 || gold < 1000)
									strcpy(str, "��Դ����\n");
								else {
									food = food - 400;
									gold = gold - 1000;
									mood = mood - 2000;
									yaned = 2;
									total = total + 100;
									people = people + 2000;
									strcpy(str, "����ʩ�������о�ɶ�о�ɶȥ\n");
								}
							} else
								strcpy(str, "��û������û������ɶ��\n");
						}
					} else if (bb == '>') {
						if (duanzaoshued == 3) {
							strcpy(str, "������ߵȼ�\n");
						} else if (duanzaoshued == 2) {
							if (mood < 1200 || gold < 6000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 6000;
								mood = mood - 1200;
								duanzaoshued = 3;
								strcpy(str, "�ɹ��ﵽ����������(������)\n");
							}
						} else if (duanzaoshued == 1) {
							if (mood < 400 || gold < 2000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 2000;
								mood = mood - 400;
								duanzaoshued = 2;
								strcpy(str,
								       "�ɹ��ﵽ����������(����������������Դ)\n");
							}
						} else {
							if (mood < 200 || gold < 1000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 1000;
								mood = mood - 200;
								duanzaoshued = 1;
								strcpy(str,
								       "�ɹ��ﵽ������һ��(����������������Դ)\n");
							}
						}
					} else if (cc == '>') {
						if (duanzaoshued > 1) {
							if (ji == 5)
								strcpy(str, "�Ѵ�����\n");
							else {
								if (mood < 400 || gold < 1000)
									strcpy(str, "��Դ����\n");
								else {
									mood = mood - 400;
									gold = gold - 1000;
									jiqirened = 13;
									ji = ji + 1;
								}
							}
						} else
							strcpy(str, "̫�߿Ƽ���,����������\n");
					} else if (ff == '>') {
						if (coin != 2)
							strcpy(str, "���������ˣ�Ǯ����ȥ����ȥ\n");
						else {
							if (mood < 10000 || gold < 2000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 2000;
								mood = mood - 10000;
								coin = 4;
								total = total + 10;
								people = people + 200;
								strcpy(str, "�ɹ�������\n");
							}
						}
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}

void mucai() {				// ****ľ�ĳ�*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1����ǽ\033[0m7��50ľ%c\033[42;31m2����ѧ\033[0m25��%c\033[43;31m3��¥\033[0m10��20ľ%c\033[45m4����ľ�ĳ�\033[0m150��100ľ100ʳ%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1': {
					if (wall == 1)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "����ʲô�����赲�о�������\n");
				}
				break;
				case '2': {
					if (jianzhuxueed == 0)
						strcpy(str, "������ë������\n");
					else if (jianzhuxueed == 1)
						strcpy(str, "����ѧ1��(����������������Դ)\n");
					else if (jianzhuxueed == 2)
						strcpy(str, "����ѧ2��(����������ʮ����Դ)\n");
					else if (jianzhuxueed == 3)
						strcpy(str, "����ѧ3��(������)\n");
				}
				break;
				case '3': {
					if (paoloued == 32)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "��ֹ��Զ�̹�����λ\n");
				}
				break;
				case '4': {
					if (tree != 2)
						strcpy(str, "������\n");
					else {
						strcpy(str, "�ӿ�ľ�������ٶȣ�\n");
					}
				}
				break;
				case '0':
					strcpy(str, "OK\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (wall == 1)
							strcpy(str, "�����ظ�����\n");
						else {
							if (mood < 600 || gold < 140)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 140;
								mood = mood - 600;
								wall = 1;
								total = total + 200;
								people = people + 4000;
								strcpy(str, "�޺��ˣ���ȫ��һ\n");
							}
						}
					} else if (bb == '>')

					{
						if (jianzhuxueed == 3) {
							strcpy(str, "������ߵȼ�\n");
						} else if (jianzhuxueed == 2) {
							if (gold < 5000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 5000;
								jianzhuxueed = 3;
								strcpy(str, "�ɹ��ﵽ����ѧ����(������)\n");
							}
						} else if (jianzhuxueed == 1) {
							if (gold < 1000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 1000;
								jianzhuxueed = 2;
								strcpy(str,
								       "�ɹ��ﵽ����ѧ����(����������ʮ����Դ)\n");
							}
						} else {
							if (gold < 500)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 500;
								jianzhuxueed = 1;
								strcpy(str,
								       "�ɹ��ﵽ����ѧһ��(����������������Դ)\n");
							}
						}
					} else if (cc == '>') {
						if (paoloued == 32)
							strcpy(str, "�����ظ�����\n");
						else {
							if (jianzhuxueed == 0)
								strcpy(str, "�������𣬺Ǻ�\n");
							else if (jianzhuxueed != 0) {
								if (mood < 400 || gold < 200)
									strcpy(str, "��Դ����\n");
								else {
									strcpy(str, "�����У�����������԰\n");
									gold = gold - 200;
									mood = mood - 400;
									paoloued = 32;
									total = total + 10;
									people = people + 200;
									total = total + 10;
								}
							}
						}
					} else if (ff == '>') {
						if (tree != 2)
							strcpy(str,
							       "���������ˣ���Ҫ�ҿ��ķ���Ҫ��������\n");
						else {
							if (mood < 2000 || gold < 3000 || food < 2000)
								strcpy(str, "��Դ����\n");
							else {
								gold = gold - 3000;
								food = food - 2000;
								mood = mood - 2000;
								total = total + 10;
								people = people + 200;
								strcpy(str, "����ľ�ĳ��ɹ�\n");
								tree = 4;
							}
						}
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}

void yanjiu() {				// ****�о�Ժ*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1��ʦ\033[0m50ʳ50ľ%c\033[42;31m2Ӣ��BANANA\033[0m100ʳ5��%c\033[43;31m3����Դ\033[0m150��100ľ100ʳ%c\033[45m4�Ƚ�ʱ��\033[0m50ʳ300ľ600��%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1':
					strcpy(str, "����Ϊʲô��������һ�Ż���\n");
					break;
				case '2': {
					if (yingxionged == 14)
						strcpy(str, "���ٻ�\n");
					else
						strcpy(str, "����������һ��սʿ����������\n");
				}
				break;
				case '3': {
					if (pig == 8 && tree == 8 && coin == 8)
						strcpy(str, "��ӵ��\n");
					else
						strcpy(str, "������Դ�ĳ�����ζ���ϸ�ʱ�����ս�\n");
				}
				break;
				case '4': {
					if (chengbaoed == 33)
						strcpy(str, "ǰ�ڰ�ʱ��\n");
					else
						strcpy(str, "��ûǮ�ˣ���Ҫ����\n");
				}
				break;
				case '0':
					strcpy(str, "���ڷ�ѧ��\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (junshililuned < 3)
							strcpy(str, "�޷��ٻ�\n");
						else {
							if (fa == 5)
								strcpy(str, "�Ѵ�����\n");
							else {
								if (mood < 1000 || food < 1000)
									strcpy(str, "��Դ����\n");
								else {
									food = food - 1000;
									mood = mood - 1000;
									fashied = 15;
									fa = fa + 1;
								}
							}
						}
					} else if (bb == '>') {
						if (yingxionged == 14)
							strcpy(str, "��������Ψһ��Ӣ��\n");
						else {
							if (gold < 100 || food < 2000)
								strcpy(str, "��Դ����\n");
							else {
								food = food - 2000;
								gold = gold - 100;
								yingxionged = 14;
							}
						}
					} else if (cc == '>') {
						if (pig == 8 && tree == 8 && coin == 8)
							strcpy(str, "�Ѿ���չ�ù�����\n");
						else {
							if (pig == 4 && tree == 4 && coin == 4) {
								if (mood < 2000 || gold < 3000 || food < 2000)
									strcpy(str, "��Դ����\n");
								else {
									gold = gold - 3000;
									mood = mood - 2000;
									food = food - 2000;
									pig = 8;
									tree = 8;
									coin = 8;
									strcpy(str, "�۹����ڷ��ٷ�չ\n");
								}
							} else
								strcpy(str, "��û�з�������Դ\n");
						}
					}

					else if (ff == '>') {
						if (chengbaoed == 33)
							strcpy(str, "�������ķ�չ\n");
						else {
							if (jianzhuxueed == 3) {
								if (mood < 6000 || gold < 12000 || food < 1000)
									strcpy(str, "��Դ����\n");
								else {
									gold = gold - 12000;
									mood = mood - 6000;
									food = food - 1000;
									chengbaoed = 33;
									total = total + 500;
									people = people + 10000;
									strcpy(str,
									       "���ѽ�����һʱ����������Ϊ��׼���˳Ǳ�\n");
								}
							} else {
								strcpy(str, "ʱ���Ľ���Ҳ������ô���׵�\n");
							}
						}
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}

void shichang() {				// ****�г�*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1��ľ��\033[0m+7��%c\033[42;31m2��ʳ��\033[0m+7��%c\033[43;31m3��ľ��\033[0m7��%c\033[45m4��ʳ��\033[0m7��%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1':
					strcpy(str, "10ľ��7��\n");
					break;
				case '2':
					strcpy(str, "10ʳ��7��\n");
					break;
				case '3':
					strcpy(str, "10���7ľ\n");
					break;
				case '4':
					strcpy(str, "10���7ʳ\n");
					break;
				case '0':
					strcpy(str, "��ӭ�´ι���\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (mood < 200)
							strcpy(str, "��Դ����\n");
						else {
							mood = mood - 200;
							gold = gold + 140;
						}
					} else if (bb == '>') {
						if (food < 200)
							strcpy(str, "��Դ����\n");
						else {
							food = food - 200;
							gold = gold + 140;
						}
					} else if (cc == '>') {
						if (gold < 200)
							strcpy(str, "��Դ����\n");
						else {
							gold = gold - 200;
							mood = mood + 140;
						}
					} else if (ff == '>') {
						if (gold < 200)
							strcpy(str, "��Դ����\n");
						else {
							gold = gold - 200;
							food = food + 140;
						}
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}

void chengbao() {				// ****�Ǳ�*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1���ڲ���\033[0m500��500ľ500ʳ%c\033[42;31m2�漣\033[0m1000��1000ľ200ʳ%c\033[43;31m3����DESTROY\033[0m20��100ľ1000ʳ%c\033[45m4����İ���\033[0m999999��999999ľ999999ʳ%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1': {
					if (anheicailiaoed == 1)
						strcpy(str, "�ѻ��\n");
					else
						strcpy(str, "����ʦ����Ѱ���²���\n");
				}
				break;
				case '2': {
					if (qijied == 34)
						strcpy(str, "�ѽ���\n");
					else
						strcpy(str, "�������ļ�֤\n");
				}
				break;
				case '3': {
					if (jurened == 16)
						strcpy(str, "���ٻ�\n");
					else
						strcpy(str, "�����и������ӡ�ľ��ްԻ�������������\n");
				}
				break;
				case '4':
					strcpy(str, "���������\n");
					break;
				case '0':
					strcpy(str, "�մˡ�����\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (duanzaoshued < 3)
							strcpy(str, "�Ҳ���\n");
						else {
							if (anheicailiaoed == 1)
								strcpy(str, "���а��ڲ���\n");
							else {
								if (mood < 10000 || gold < 10000 || food < 10000)
									strcpy(str, "��Դ����\n");
								else {
									anheicailiaoed = 1;
									mood = mood - 10000;
									gold = gold - 10000;
									food = food - 10000;
									strcpy(str, "�ɹ���ð��ڲ���\n");
								}
							}
						}
					}

					else if (bb == '>')

					{
						if (qijied == 34)
							strcpy(str, "֮���Գ�Ϊ�漣����Ϊ����Ψһ��\n");
						else {
							if (anheicailiaoed == 1) {
								if (mood < 20000 || gold < 20000 || food < 4000)
									strcpy(str, "��Դ����\n");
								else {
									food = food - 4000;
									gold = gold - 20000;
									mood = mood - 20000;
									qijied = 34;
									total = total + 960;
									people = people + 960 * 20;
									strcpy(str, "���ڽ��������˲���Ŀ\n");
								}
							} else
								strcpy(str, "û�п��ò���\n");
						}
					}

					else if (cc == '>') {
						if (anheicailiaoed == 1) {
							if (jurened == 16)
								strcpy(str, "ֻ������һ�����ˣ������ٶ���\n");
							else {
								if (mood < 2000 || food < 20000 || gold < 400)
									strcpy(str, "��Դ����\n");
								else {
									gold = gold - 400;
									mood = mood - 2000;
									food = food - 20000;
									jurened = 16;
									strcpy(str, "���ٻ����������\n");
								}
							}
						} else
							strcpy(str, "û�п��ٻ�����\n");
					} else if (ff == '>') {
						if (gold < 999999 * 20 || food < 999999 * 20 || mood < 999999 * 20)
							strcpy(str, "��Դ����\n");
						else {
							gold = gold - 999999 * 20;
							food = food - 999999 * 20;
							mood = mood - 999999 * 20;
						}
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}

void qiji() {					// ****�漣*****
	char aa = ' ', bb = ' ', cc = ' ', ee = ' ', dd, ff = ' ', *aa1, *bb1, *cc1, *dd1, *ee1, *ff1;
	while (1) {
		aa1 = &aa;
		bb1 = &bb;
		cc1 = &cc;
		dd1 = &dd;
		ee1 = &ee;
		ff1 = &ff;
		draw();
		printf
		("%c\033[41m1�ؽ�\033[0m���÷Ż�%c\033[42;31m2��¥��ǿ\033[0m500ľ%c\033[43;31m3�����ڴ�\033[0m��%c\033[45m4�����ڴ�\033[0m��%c0�˳��������Ӧ���ֻس�ȷ����",
		 aa, bb, cc, ff, ee);
		printf("\n");
		usleep(100000);
		while (kbhit()) {
			keyy(aa1, bb1, cc1, dd1, ee1, ff1);
			switch (dd) {		// ������ʾ
				case '1': {
					if (human != 1)
						strcpy(str, "�ؽ��С�����ȡ���ؽ���\n");
					else
						strcpy(str, "�ؽ���԰���ø������������Ĺ���\n");
				}
				break;
				case '2': {
					if (pao == 2)
						strcpy(str, "��¥��������\n");
					else
						strcpy(str, "��¥�����Ͱ�\n");
				}
				break;
				case '3':
					strcpy(str, "10���7ľ\n");
					break;
				case '4':
					strcpy(str, "10���7ʳ\n");
					break;
				case '0':
					strcpy(str, "��ӭ�´ι���\n");
					break;
				case '\n': {		// �س�����
					if (aa == '>') {
						if (human != 1) {
							human = 1;
							strcpy(str, "��ȡ���ؽ�\n");
						}

						else {
							if (jianzhuxueed == 0)
								human = 3;
							else if (jianzhuxueed > 0)
								human = 5;
							strcpy(str, "�����ؽ�������ȡ���ؽ���\n");
						}
					} else if (bb == '>') {
						if (pao == 2)
							strcpy(str, "���ü�ǿ��\n");

						else if (pao < 2) {
							mood = mood - 10000;
							pao = 2;
							strcpy(str, "��¥��������\n");
						}
					} else if (cc == '>') {
						gold = gold - 200;
						mood = mood + 140;
					} else if (ff == '>') {
						gold = gold - 200;
						food = food + 140;
					} else if (ee == '>')
						start();
				}
			}
		}
	}
}