#include<bits/stdc++.h>
using namespace std;

const int mn=1<<31;
int s[2][5][5][5][5],a[4][2],x,y,w,b[4];
bool f[2][5][5][5][5];

inline void get(int& a,int& b)
{
	char x;
	int y;
	scanf(" %c%d",&x,&y);
	switch(x)
	{
	case 'B':a=0;break;
	case 'G':a=1;break;
	case 'R':a=2;break;
	case 'Y':a=3;break;
	}
	b=y;
}

inline void add(int u,int v,int c)
{
	if(!b[u])
		return;
	int p,p0=s[x][b[0]][b[1]][b[2]][b[3]];
	b[u]--,b[v]++;
	switch(u)
	{
	case 0:p=w-c;break;
	case 1:p=w+c;break;
	case 2:p=w*c;break;
	case 3:p=c?w/c:0;break;
	}
	p+=p0;
	if(!f[y][b[0]][b[1]][b[2]][b[3]])
		s[y][b[0]][b[1]][b[2]][b[3]]=p,f[y][b[0]][b[1]][b[2]][b[3]]=1;
	else
		s[y][b[0]][b[1]][b[2]][b[3]]=max(s[y][b[0]][b[1]][b[2]][b[3]],p);
	b[u]++,b[v]--;
}
void dfs(int d,int z)
{
	int i;
	if(d>=4)
	{
		if(f[x][b[0]][b[1]][b[2]][b[3]])
			for(i=0;i<4;i++)
				add(a[i][0],a[(i+2)%4][0],a[i][1]);
		return;
	}
	for(i=d<3?0:z;i<=z;i++)
	{
		b[d]=i;
		dfs(d+1,z-i);
	}
}

int main()
{
	int T,n,i,j,k,l,ans;
	for(scanf("%d",&T);T--;)
	{
		scanf("%d",&n);
		x=0,y=1;
		memset(f,0,sizeof(f[0]));
		memset(b,0,sizeof(b));
		for(i=0;i<4;i++)
			get(a[i][0],a[i][1]),b[a[i][0]]++;
		f[0][b[0]][b[1]][b[2]][b[3]]=1;
		s[0][b[0]][b[1]][b[2]][b[3]]=0;
		while(--n)
		{
			memset(f[y],0,sizeof(f[0]));
			for(w=i=0;i<4;i++)
				get(a[i][0],a[i][1]),w+=a[i][1];
			for(i=0;i<5;i++)
				for(j=0;j<5;j++)
					for(k=0;k<5;k++)
						for(l=0;l<5;l++)
							if(f[x][i][j][k][l])
								f[y][i][j][k][l]=1,s[y][i][j][k][l]=s[x][i][j][k][l]-w;
			dfs(0,4);
			swap(x,y);
		}
		for(ans=mn,i=0;i<5;i++)
			for(j=0;j<5;j++)
				for(k=0;k<5;k++)
					for(l=0;l<5;l++)
						if(f[x][i][j][k][l])
							ans=max(ans,s[x][i][j][k][l]);
		printf("%d\n",ans);
	}
	return 0;
}
