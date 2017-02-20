#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


vector<int>gra[5000];
int deg[6000];
int ans;
void dfs(int s,int d)
{
    ans=max(d,ans);
    for(int i=0;i<gra[s].size();i++)
        dfs(gra[s][i],d+1);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    int x,y;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x!=-1)gra[x].push_back(i),deg[i]++;
    }
    ans=0;
    for(int i=1;i<=n;i++)
        if(deg[i]==0)
            dfs(i,1);
    printf("%d\n",ans);
	return 0;
}
