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
int head[105];
int nn,mm;
int d[105],cont[105],q[105];
int pre[105],cur[105];
bool vis[105];
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
int deg[105],st[505],sk;
vector<pair<int,bool> >gra[105];
void dfs(int s)
{
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i].second)
        {
            gra[s][i].second=0;
            dfs(gra[s][i].first);
        }
    st[sk++]=s;
}
int main()
{
    int tt;scanf("%d",&tt);
    bool f=0;
    while(tt--)
    {
        if(f)putchar(10);f=1;
        int n,m,x,y;
        char te[5];
        scanf("%d%d",&n,&m);
        nn=n+2;mm=0;
        int s=nn-1,t=nn;
        for(int i=1;i<=nn;i++)head[i]=-1,deg[i]=0,gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%s",&x,&y,te);
            if(te[0]=='D')gra[x].push_back(make_pair(y,1)),deg[y]++,deg[x]--;
            else add(y,x,1),deg[y]++,deg[x]--;
        }
        int sum=0;
        bool f=1;
        for(int i=1;i<=n&&f;i++)
            if(deg[i]&1)f=0;
            else
            {
                if(deg[i]>0)add(s,i,deg[i]/2),sum+=deg[i]/2;
                else if(deg[i]<0)add(i,t,-deg[i]/2);
            }
        if(f&&SAP(s,t)==sum)
        {
            for(int i=1;i<=n;i++)
                for(int j=head[i];~j;j=e[j].next)
                    if(e[j].c==0&&e[j].y!=t)
                        gra[i].push_back(make_pair(e[j].y,1));
            sk=0;dfs(1);
            if(sk<=m)puts("No euler circuit exist");
            else
            {
                for(int i=sk-1;i>-1;i--)
                    printf("%d%c",st[i],i?' ':10);
            }
        }
        else puts("No euler circuit exist");
    }
    return 0;
}