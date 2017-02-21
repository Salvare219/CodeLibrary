#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    int y,pdc,next;
    edge(int y_=0,int pdc_=0,int n_=0){y=y_,pdc=pdc_,next=n_;}
}e[2000005];
int head[1005],mm;
bool vis[1005];
int low[1005],dfn[1005];
int stack2[2000005],sk2;
bool cut[1005];
int pcnt,timer,root;
void dfs(int s,int fa)
{
	dfn[s]=low[s]=++timer;
	int to,sz=0;
	bool flag=vis[s]=1;
	for(int i=head[s];~i;i=e[i].next)
        if(e[i].pdc==0)
        {
            stack2[sk2++]=i;
            if((to=e[i].y)==fa&&flag)flag=0;
            else
            {
                if(vis[to])low[s]=min(dfn[to],low[s]);
                else
                {
                    dfs(to,s);sz++;
                    low[s]=min(low[to],low[s]);
                    if(low[to]>=dfn[s])
                    {
                        if(s!=root||sz>1)cut[s]=1;
                        do to=stack2[--sk2],e[to].pdc=e[to^1].pdc=pcnt;
                        while(stack2[sk2]!=i);
                        pcnt++;
                    }
                }
            }
        }
}
void add(int x,int y)
{
    e[mm]=edge(y,0,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}
bool sta[1005];
bool dfs2(int s)
{
    int y;dfn[s]=timer;
    bool f=0;
    for(int i=head[s];~i;i=e[i].next)
        if(e[i].pdc==root)
        {
            if(dfn[y=e[i].y]!=timer)
            {
                sta[y]=sta[s]^1;
                if(dfs2(y))return 1;
            }
            else if(sta[y]==sta[s])return 1;
        }
    return 0;
}
bool col[1005];
bool sol(int s)
{
    col[s]=1;
    for(int i=head[s];~i;i=e[i].next)
        if(e[i].pdc==root&&col[e[i].y]==0)
            sol(e[i].y);
}
bool maz[1005][1005];
bool sb[2000005];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        int x,y;mm=0;
        for(int i=1;i<=n;i++)head[i]=-1;
        memset(maz,0,sizeof(maz));
        for(int i=0;i<m;i++)
            scanf("%d%d",&x,&y),maz[x][y]=maz[y][x]=1;
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(maz[i][j]==0)add(i,j);
        memset(vis,0,sizeof(vis));
        memset(cut,0,sizeof(cut));
        pcnt=root=1;timer=0;
        for(int i=1;i<=n;i++)
            if(vis[i]==0)
                dfs(i,0);
        memset(dfn,0,sizeof(dfn));
        memset(col,0,sizeof(col));
        for(int i=1;i<pcnt;i++)sb[i]=0;
        for(int i=0;i<mm;i++)
            if(sb[e[i].pdc]==0)
            {
                x=e[i].y;
                sb[root=e[i].pdc]=1;
                if(dfs2(x))sol(x);
                timer++;
            }
        int ans=0;
        for(int i=1;i<=n;i++)
            ans+=col[i];
        printf("%d\n",n-ans);
    }
    return 0;
}
