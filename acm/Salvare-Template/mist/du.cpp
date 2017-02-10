C++:

//注意有负数要改
//可以改成引用试试
inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}

//另一种  可处理负数
inline int Int()
{
	int a=0;char c=getc(stdin),s;
	while(c<'0')s=c,c=getc(stdin);
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getc(stdin);
	return s!='-'?a:-a;
}

//输出外挂
inline void out(int c)
{
    if(c>9)out(c/10);
    putchar(c-c/10*10+'0');
}
