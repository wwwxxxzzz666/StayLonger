char inbuf[100];
int inbufn;
 
#ifdef WIN
void getinput()
{
}
 
void inputdbg()
{
}
 
int keyp(char ss[])
{
	if (GetKeyState(ss[0])<0) return 1;
	return 0;
}
#endif
 
#ifndef WIN
void getinput()
{
	while (kbhit())
	{
		char c = getch();
		int i, t = 0;
		for (i = 1; i <= inbufn; i++)
			if (inbuf[i] == c)
				t = 1;
		if (t)
			continue;
		inbuf[++inbufn] = c;
	}
	// rewind(stdin);
}
 
void inputdbg()
{
	int i;
	for (i = 1; i <= inbufn; i++)
		putchar(inbuf[i]);
	puts("");
 
}
 
int keyp(char ss[])
{
	int i, j, l = strlen(ss);
	for (j = 0; j < l; j++)
	{
		char c = ss[j];
		int z = 0;
		for (i = 1; i <= inbufn; i++)
			if (inbuf[i] == c)
				z = 1;
		if (!z)
			return 0;
	}
	for (j = 0; j < l; j++)
	{
		char c = ss[j];
		for (i = 1; i <= inbufn; i++)
			if (inbuf[i] == c)
			{
				inbuf[i] = inbuf[inbufn];
				inbufn--;
				break;
			}
	}
	return 1;
}
#endif