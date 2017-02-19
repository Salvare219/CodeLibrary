#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int mod=1000000007;
vector<int> v[100005];
int slf[100005];
bool vis[100005];

void dfs(int x,int p,int&sta,int&cnt)
{
	if(vis[x])
	{
		if(sta>100)
			sta=50;
		else if(sta>10)
			sta=2;
		else
			sta=0;
		return;
	}
	vis[x]=1;
	cnt++;
	if(slf[x])
	{
		if(slf[x]>1)
			sta=0;
		else if(sta>10)
			sta=1;
		else
			sta=0;
	}
	int i,y;
	for(i=0;i<v[x].size();i++)
	{
		y=v[x][i];
		if(y==p)
			p=-1;
		else
			dfs(y,x,sta,cnt);
	}
}

int main()
{
	int n,m,T=0,x,y,s1,s2,i;
	long long s;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		memset(vis,0,sizeof(vis));
		memset(slf,0,sizeof(slf));
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			if(x==y)
				slf[x]++;
			else
				v[x].push_back(y),v[y].push_back(x);
		}
		s=1ll;
		for(i=0;i<m;i++)
			if(!vis[i])
			{
				s1=1<<10,s2=0;
				dfs(i,-1,s1,s2);
				s=s*(s1<10?s1:s2)%mod;
			}
		printf("Case %d: %I64d\n",++T,s);
		for(i=0;i<m;i++)
			v[i].clear();
	}
	return 0;
}
