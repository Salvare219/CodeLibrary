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
}e[6005];
int p[105],dis[105],head[105];
int que[105];
bool vis[105];
bool spfa(int s,int t)
{
    int x,to,front=0,tail=0;
    for(int i=1;i<=nn;i++) vis[i]=0,dis[i]=0x3fffffff;
    dis[s]=0;vis[s]=1;que[tail++]=s;
    while(front!=tail)
    {
        x=que[front++];vis[x]=0;
        if(front>nn)front=0;
        for(int i=head[x];~i;i=e[i].next)
        {
            to=e[i].y;
            if(e[i].c>0 && dis[to]>dis[x]+e[i].f)
            {
                dis[to]=dis[x]+e[i].f;p[to]=i;
                if(vis[to]==0)
                {
                    vis[to]=1;
                    if(dis[to]<dis[que[front]])
                    {
                        front--;
                        if(front<0)front=nn;
                        que[front]=to;
                    }
                    else
                    {
                        que[tail++]=to;
                        if(tail>nn)tail=0;
                    }
                }
            }
        }
    }
    if(dis[t]<0x3fffffff) return 1;
    else return 0;
}
int fin;
int cost_flow(int s,int t)
{
	int ans=0,flow,x;fin=0;
	while(spfa(s,t))
	{
	    flow=0x3fffffff;
		for(x=t;x!=s;x=e[p[x]^1].y) flow=min(flow,e[p[x]].c);
		for(x=t;x!=s;x=e[p[x]^1].y)
			e[p[x]^1].c+=flow,e[p[x]].c-=flow,ans+=flow*e[p[x]].f;
        fin+=flow;
	}
	return ans;
}
int nd[105];
void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}
int main()
{
    int tt,ti=1;scanf("%d",&tt);
    while(tt--)
    {
        int n,m,s,t,x,y,a,b;
        scanf("%d%d%d%d",&n,&m,&s,&t);
        nn=n+2;
        for(int i=1;i<=nn;i++)
            nd[i]=0,head[i]=-1;
        int ans=0;mm=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&a,&b);
            if(a>b)add(x,y,1,a-b),ans+=b;
            else add(y,x,1,b-a),ans+=a,nd[x]--,nd[y]++;
        }
        nd[s]++;nd[t]--;s=n+1;t=n+2;
        int tot=0;
        for(int i=1;i<=n;i++)
            if(nd[i]>0)add(s,i,nd[i],0),tot+=nd[i];
            else if(nd[i]<0)add(i,t,-nd[i],0);
        ans+=cost_flow(s,t);
        printf("Case %d: ",ti++);
        if(fin==tot)printf("%d\n",ans);
        else puts("impossible");
    }
    return 0;
}
