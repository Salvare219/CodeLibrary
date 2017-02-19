#include<cstdio>
#include<cstdlib>
#include<cstring>

char a[100];
int b[100];
bool f[20];

inline int toInt(char x)
{
	if(x>='0'&&x<='9')
		return x-'0';
	if(x>='A'&&x<='F')
		return x-'A'+10;
	return -1;
}
inline char toChar(int x)
{
	if(x>=0&&x<=9)
		return x+'0';
	if(x>=10&&x<=15)
		return x-10+'A';
	return 0;
}

void dfs(int x)
{
	if(a[x]==0)
	{
		puts(a[0]=='0'?a+1:a);
		exit(0);
	}
	for(int i=toInt(a[x]);i<16;i++)
	{
		if(!f[i])
		{
			if(x==0&&i==0)
				{}
			else
				f[i]=1;
			int j=toChar(i);
			if(j!=a[x])
				for(int k=x;a[k];k++)
					a[k]='0';
			a[x]=j;
			dfs(x+1);
			f[i]=0;
		}
	}
}

int main()
{
	scanf("%s",a+1);
	a[0]='0';
	int l=strlen(a),i;
	for(i=0;i<l;i++)
		b[i]=toInt(a[i]);
	for(i=l;i--;)
	{
		b[i]++;
		if(b[i]>=16)
			b[i]=0;
		else
			break;
	}
	for(i=0;i<l;i++)
		a[i]=toChar(b[i]);
	dfs(0);
	return -1;
}
