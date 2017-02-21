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
bool des[1005];
int dfs(int n)
{
	int i;
	for(i=0;i<gra[n].size();i++)
	{
		if(des[gra[n][i]]) continue;
		des[n]=1;
		if(dfs(gra[n][i])==0) return gra[n][i];
		des[n]=0;
	}
	return 0;
}
int main()
{
//	freopen("1.txt","r",stdin);
	int n,k,x,y;
	while(scanf("%d%d",&n,&k)==2)
	{
		for(int i=0;i<n;i++)
		{
			gra[i+1].clear();
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			gra[x].push_back(y);
			gra[y].push_back(x);
		}
		int ans=dfs(k);
		if(ans==0) printf("First player loses\n");
		else printf("First player wins flying to airport %d\n",ans);
	}
	return 0;
}