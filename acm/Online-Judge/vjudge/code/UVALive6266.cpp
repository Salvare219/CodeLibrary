#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int nn,mm;
struct edge
{
    int y,c,f,next;
    edge(int y_=0,int c_=0,int f_=0,int next_=0){y=y_,c=c_,f=f_,next=next_;}
}e[90005];
int p[5005],dis[5005],head[5005];
bool vis[5005];
bool spfa(int s,int t)
{
    queue<int> que;
    int x,to;
    for(int i=1;i<=nn;i++) vis[i]=0,dis[i]=0x3fffffff;
    dis[s]=0;vis[s]=1;que.push(s);
    while(!que.empty())
    {
        x=que.front();
        que.pop();vis[x]=0;
        for(int i=head[x];~i;i=e[i].next)
        {
            to=e[i].y;
            if(e[i].c>0 && dis[to]>dis[x]+e[i].f)
            {
                dis[to]=dis[x]+e[i].f;p[to]=i;
                if(vis[to]==0) que.push(to),vis[to]=1;
            }
        }
    }
    if(dis[t]<0x3fffffff) return 1;
    else return 0;
}
int cost_flow(int s,int t)
{
	int ans=0,flow,x;
	while(spfa(s,t))
	{
	    flow=0x3fffffff;
		for(x=t;x!=s;x=e[p[x]^1].y) flow=min(flow,e[p[x]].c);
		for(x=t;x!=s;x=e[p[x]^1].y)
			e[p[x]^1].c+=flow,e[p[x]].c-=flow,ans+=flow*e[p[x]].f;
	}
	return ans;
}
void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int x,y,w;nn=2*n+2;
        int s=nn-1,t=nn;
        memset(head,-1,sizeof(head));
        mm=0;
        add(1,1+n,2,0);
        add(n,n+n,2,0);
        for(int i=2;i<n;i++)
            add(i,i+n,1,0);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&w);
            add(x+n,y,1,w);
        }
        add(s,1,2,0);add(n+n,t,2,0);
        printf("%d\n",cost_flow(s,t));
    }
    return 0;
}
