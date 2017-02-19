#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    int y,c,next;
    edge(int y_=0,int c_=0,int n_=0){y=y_,c=c_,next=n_;}
}e[5000];
int head[205];
int nn,mm;
int d[205],cont[205],q[205];
int pre[205],cur[205];
bool vis[205];
void bfs(int s)
{
    int x,to,tail=1,front=0;
    for(int i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;
    d[s]=0;cont[0]=1;q[0]=s;vis[s]=1;
    while(front<tail)
        for(int i=head[x=q[front++]];i!=-1;i=e[i].next)
            if(!vis[to=e[i].y] && e[i^1].c)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                q[tail++]=to;
                cont[d[to]]++;
            }
}
int SAP(int s,int t)
{
    if(s==t) return 0x7fffffff;
    bfs(t);pre[s]=-1;
    int ans=0,x=s,y,len=0,flow,back;
    while(d[s]<nn)
    {
        y=-1;
        for(int i=cur[x];i!=-1;i=e[i].next)
            if(e[i].c && d[x]==d[e[i].y]+1)
            {
                y=e[i].y;
                cur[x]=i;
                break;
            }
        if(y!=-1)
        {
            pre[y]=x;x=y;
            if(x==t)
            {
                flow=0x3fffffff;
                for(y=pre[y];y!=-1;y=pre[y])
                    if(flow>=e[cur[y]].c) flow=e[cur[y]].c,back=y;
                for(x=pre[x];x!=-1;x=pre[x])
                    e[cur[x]^1].c+=flow,e[cur[x]].c-=flow;
                ans+=flow;x=back;
            }
        }
        else
        {
            y=nn;
            for(int i=head[x];i!=-1;i=e[i].next)
                if(e[i].c && y>d[e[i].y])
                    y=d[e[i].y],cur[x]=i;
            cont[d[x]]--;
            if(cont[d[x]]==0) break;
            cont[d[x]=y+1]++;
            if(x!=s) x=pre[x];
        }
    }
    return ans;
}
void add(int x,int y,int c)
{
    e[mm]=edge(y,c,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}
int deg[205];
vector<int>gra[205];
int st;
bool v[205];
void dfs(int s)
{
    v[s]=1;st++;
    for(int i=0;i<gra[s].size();i++)
        if(v[gra[s][i]]==0)dfs(gra[s][i]);
}
int main()
{
    int tt;scanf("%d",&tt);
    while(tt--)
    {
        int n,m,x,y,w;
        scanf("%d%d",&n,&m);
        nn=n+2;mm=0;
        int s=nn-1,t=nn;
        for(int i=1;i<=nn;i++)head[i]=-1,deg[i]=v[i]=0,gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            gra[x].push_back(y);
            gra[y].push_back(x);
            if(w)deg[y]++,deg[x]--;
            else add(y,x,1),deg[y]++,deg[x]--;
        }
        st=0;dfs(1);
        if(st<n)puts("impossible");
        else
        {
            int sum=0;
            bool f=1;
            for(int i=1;i<=n&&f;i++)
                if(deg[i]%2!=0)f=0;
                else
                {
                    if(deg[i]>0)add(s,i,deg[i]/2),sum+=deg[i]/2;
                    else if(deg[i]<0)add(i,t,-deg[i]/2);
                }
            if(f&&SAP(s,t)==sum)puts("possible");
            else puts("impossible");
        }
    }
    return 0;
}