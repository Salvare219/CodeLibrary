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
    edge(int y1=0,int c1=0,int ne=0){y=y1,c=c1,next=ne;}
}e[50005],et[50005];
int head[505],h1[505];
int nn,mm,mm1;
int d[505],cont[505];
int pre[505],cur[505];
bool vis[505];
void bfs(int s)
{
    int x,to;
    queue<int> que;
    for(int i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;
    d[s]=0;cont[0]=1;
    que.push(s);vis[s]=1;
    while(!que.empty())
    {
        x=que.front();que.pop();
        for(int i=head[x];i!=-1;i=e[i].next)
        {
            to=e[i].y;
            if(!vis[to] && e[i^1].c)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                que.push(to);
                cont[d[to]]++;
            }
        }
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
                    if(flow>e[cur[y]].c) flow=e[cur[y]].c,back=y;
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
    et[mm1]=edge(y,c,h1[x]);h1[x]=mm1++;
    et[mm1]=edge(x,0,h1[y]);h1[y]=mm1++;
}
int n,m,s,t,p,ans;
bool ok1(int mid)
{
    for(int i=1;i<=n;i++)
        head[i]=h1[i];
    for(int i=0;i<mm1;i++)
        e[i]=et[i],e[i].c=min(e[i].c,mid);
    mm=mm1;nn=n;
    if(SAP(s,t)==ans)return 1;
    else return 0;
}
int in[505];
void add2(int x,int y,int c)
{
    e[mm]=edge(y,c,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}
bool ok2(int mid)
{
    memset(in,0,sizeof(in));
    for(int i=0;i<mm1;i++)e[i]=et[i];
    for(int i=1;i<=n;i++)head[i]=h1[i];
    for(int i=1;i<=n;i++)
        for(int j=head[i];~j;j=e[j].next)
            if(e[j].c>0)
            {
                if(e[j].c<mid)return 0;
                else e[j].c-=mid,in[i]-=mid,in[e[j].y]+=mid;
            }
    mm=mm1;nn=n+2;
    int sum=0;
    head[n+1]=head[n+2]=-1;
    int sp=mm;
    add2(t,s,2000000000);
    for(int i=1;i<=n;i++)
        if(in[i]>0)add2(n+1,i,in[i]),sum+=in[i];
        else add2(i,n+2,-in[i]);
    if(SAP(n+1,n+2)!=sum) return 0;
    else
    {
        for(int i=1;i<=n;i++)
            for(int j=head[i];~j;j=e[j].next)
                if(e[j].y==n+1||e[j].y==n+2)e[j].c=0;
        if(SAP(s,t)==ans)return 1;
        else return 0;
    }
}
int main()
{
    int ti;scanf("%d",&ti);
    while(ti--)
    {
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);s++;t++;
        memset(h1,-1,sizeof(h1));mm1=0;
        int x,y,c;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&x,&y,&c),add(x+1,y+1,c);
        for(int i=1;i<=n;i++)head[i]=h1[i];
        for(int i=0;i<mm1;i++)
            e[i]=et[i];
        mm=mm1;nn=n;
        ans=SAP(s,t);
        int l=0,r=min(100000,ans),mid;
        while(l<r)
        {
            mid=(l+r)>>1;
            if(ok1(mid))r=mid;
            else l=mid+1;
        }
        long long a1=1ll*r*p,a2;
        l=0;r=min(100000,ans);
        while(l<r)
        {
            mid=(l+r+1)>>1;
            if(ok2(mid))l=mid;
            else r=mid-1;
        }
        a2=1ll*l*p;
        printf("%lld %lld\n",a1,a2);
    }
    return 0;
}
