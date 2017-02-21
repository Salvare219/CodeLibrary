#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    int y,next,i;
    double c;
    edge(int y1=0,double c1=0,int ii=0,int ne=0){y=y1,c=c1,i=ii,next=ne;}
}e[2000];
int head[200];
int nn,mm;
int d[200],cont[200];
int pre[200],cur[200];
bool vis[200];
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
            if(!vis[to] && e[i^1].c>0.0)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                que.push(to);
                cont[d[to]]++;
            }
        }
    }
}
double SAP(int s,int t)
{
	if(s==t) return 1e10;
    bfs(t);pre[s]=-1;
    int x=s,y,len=0,back;
    double ans=0.0,flow;
    while(d[s]<nn)
    {
        y=-1;
        for(int i=cur[x];i!=-1;i=e[i].next)
            if(e[i].c>0 && d[x]==d[e[i].y]+1)
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
                if(e[i].c>0 && y>d[e[i].y])
                    y=d[e[i].y],cur[x]=i;
            cont[d[x]]--;
            if(cont[d[x]]==0) break;
            cont[d[x]=y+1]++;
            if(x!=s) x=pre[x];
        }
    }
    return ans;
}
void add(int x,int y,double c,int i)
{
    e[mm]=edge(y,c,i,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,i,head[y]);head[y]=mm++;
}
struct p
{
    int x,y;
    double w;
    p(int a=0,int b=0,double c=0){x=a,y=b,w=c;}
    bool operator<(p a)const{return w<a.w;}
}e1[500];
int n,m;
bool ans[500];
bool ok(double mid)
{
    double sum=0.0;nn=n;
    for(int i=1;i<=n;i++)head[i]=-1;mm=0;
    for(int i=0;i<m;i++)
        if(e1[i].w<mid)sum+=e1[i].w-mid,ans[i]=1;
        else add(e1[i].x,e1[i].y,e1[i].w-mid,i),add(e1[i].y,e1[i].x,e1[i].w-mid,i);
    sum+=SAP(1,n);
    return sum<0.0;
}
void dfs(int s)
{
    vis[s]=1;
    for(int i=head[s];i!=-1;i=e[i].next)
        if(vis[e[i].y]==0&&e[i].c>0.0)dfs(e[i].y);
}
int main()
{
    int x,y,w;bool bl=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(bl)putchar(10);bl=1;
        for(int i=0;i<m;i++)
            scanf("%d%d%d",&x,&y,&w),e1[i]=p(x,y,w);
        double l=0,r=1e7,mid;
        while(r-l>1e-3)
        {
            mid=(l+r)/2;
            if(ok(mid))r=mid;
            else l=mid;
        }
        memset(ans,0,sizeof(ans));ok(l);
        memset(vis,0,sizeof(vis));dfs(1);
        for(int i=0;i<m;i++)
            if(vis[e1[i].x]!=vis[e1[i].y])ans[i]=1;
        int sum=0;
        for(int i=0;i<m;i++)sum+=ans[i];
        printf("%d\n",sum);
        bool f=0;
        for(int i=0;i<m;i++)
            if(ans[i])
                f?printf(" %d",i+1):(printf("%d",i+1),f=1);
        putchar(10);
    }
	return 0;
}
