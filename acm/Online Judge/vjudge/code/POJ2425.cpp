#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
using namespace std;



vector<int> gra[1005];
int sg[1005];
bool ter[1005];
int dfs(int n)
{
	if(ter[n]==0) return 0;
	if(sg[n]!=-1) return sg[n];
	int size=gra[n].size(),i;
	bool vis[1005]={0};
	for(i=0;i<size;i++)
	{
		vis[dfs(gra[n][i])]=1;
	}
	i=0;
	while(vis[i]) i++;
	return sg[n]=i;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,m;
	while(scanf("%d",&n)==1)
	{
		for(int i=0;i<n;i++)
		{
			ter[i]=0;
			sg[i]=-1;
			gra[i].clear();
		}
		int x;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				gra[i].push_back(x);
				ter[i]=1;
			}
		}
		while(scanf("%d",&m))
		{
			if(m==0) break;
			int ans=0;
			for(int i=0;i<m;i++)
			{
				scanf("%d",&x);
				ans^=dfs(x);
			}
			if(ans) printf("WIN\n");
			else printf("LOSE\n");
		}
	}
	return 0;
}
