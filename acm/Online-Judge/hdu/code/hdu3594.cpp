#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


vector<int>gra[20050];
int vis[20050];
int dfn[20050],low[20050];
int timer;
bool Cactus(int s)
{
    int y,cnt=0;
    vis[s]=1;
    dfn[s]=low[s]=timer++;
    for(int i=0;i<gra[s].size();i++)
    {
        if(vis[y=gra[s][i]]==2)return 0;
        if(vis[y]==0)
        {
            if(!Cactus(y))return 0;
            if(low[y]>dfn[y])return 0;
        }
        low[s]=min(low[s],dfn[y]);
        if(low[y]<dfn[s])cnt++;
        if(cnt>1)return 0;
    }
    vis[s]=2;
    return 1;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,y;scanf("%d",&n);
        for(int i=1;i<=n;i++)
            gra[i].clear(),vis[i]=0;
        while(1)
        {
            scanf("%d%d",&x,&y);x++;y++;
            if(x*y==1)break;
            gra[x].push_back(y);
        }
        timer=0;
        puts((Cactus(1)&&timer==n)?"YES":"NO");
    }
    return 0;
}
