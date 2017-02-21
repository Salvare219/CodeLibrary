#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    long long y,c,next;
    edge(long long y_=0,long long c_=0,long long n_=0){y=y_,c=c_,next=n_;}
}e[200005];
long long head[6005];
long long nn,mm;
long long d[6005],cont[6005],q[6005];
long long pre[6005],cur[6005];
bool vis[6005];
void bfs(long long s)
{
    long long x,to,tail=1,front=0;
    for(long long i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;
    d[s]=0;cont[0]=1;q[0]=s;vis[s]=1;
    while(front<tail)
        for(long long i=head[x=q[front++]];i!=-1;i=e[i].next)
            if(!vis[to=e[i].y] && e[i^1].c)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                q[tail++]=to;
                cont[d[to]]++;
            }
}
long long SAP(long long s,long long t)
{
	if(s==t) return 0x7fffffff;
    bfs(t);pre[s]=-1;
    long long ans=0,x=s,y,len=0,flow,back;
    while(d[s]<nn)
    {
        y=-1;
        for(long long i=cur[x];i!=-1;i=e[i].next)
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
            for(long long i=head[x];i!=-1;i=e[i].next)
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
void add(long long x,long long y,long long c)
{
    e[mm]=edge(y,c,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}
bool v[6000];
void dfs(int s)
{
    int y;v[s]=1;
    for(int i=head[s];~i;i=e[i].next)
        if(e[i].c>0&&!v[y=e[i].y])dfs(y);
}
long long w[6005];
int main()
{
    long long n,m;scanf("%lld%lld",&n,&m);
    nn=n+2;mm=0;
    for(long long i=1;i<=nn;i++)head[i]=-1,v[i]=0;
    long long x,y,s=nn-1,t=nn;
    for(long long i=1;i<=n;i++)
        scanf("%lld",w+i);
    for(long long i=0;i<m;i++)
        scanf("%lld%lld",&x,&y),add(x,y,0x3fffffff);
    long long sum=0;
    for(long long i=1;i<=n;i++)
        if(w[i]>0)add(s,i,w[i]),sum+=w[i];
        else if(w[i]<0)add(i,t,-w[i]);
    long long how=0,ans=sum-SAP(s,t);dfs(s);
    for(int i=1;i<=n;i++)how+=v[i];
    printf("%I64d %I64d\n",how,ans);
    return 0;
}
