#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;


struct edge
{
    int y,c,f,next;
    edge(){}
    edge(int y_,int c_,int f_,int n_){y=y_,c=c_,f=f_,next=n_;}
}e[57000];
int head[5505];
int nn,mm;
int q[5505],p[5505],dis[5505];
bool vis[5505];
bool spfa(int s,int t)
{
    int to,tail=1,front=0;
    for(int i=1;i<=nn;i++) vis[i]=0,dis[i]=0x3fffffff;
    dis[s]=0;q[0]=s;
    while(tail!=front)
    {
        s=q[front++];vis[s]=0;
        if(front>nn)front=0;
        for(int i=head[s];~i;i=e[i].next)
            if(e[i].c&&dis[to=e[i].y]>dis[s]+e[i].f)
            {
                dis[to]=dis[s]+e[i].f;p[to]=i^1;
                if(vis[to]==0)
                {
                    vis[to]=1;
                    if(dis[to]<dis[q[front]])
                        front==0?front=nn:front--,q[front]=to;
                    else
                        q[tail++]=to,tail>nn?tail=0:0;
                }
            }
    }
    if(dis[t]<0x3fffffff) return 1;
    else return 0;
}
long long cost_flow(int s,int t,int k)
{
	int flow,x;
	long long ans=1ll<<60,sum=0,now=k,las=0;
	while(spfa(s,t))
	{
	    flow=0x3fffffff;
		for(x=t;x!=s;x=e[p[x]].y) flow=min(flow,e[p[x]^1].c);
		for(x=t;x!=s;x=e[p[x]].y)
			e[p[x]].c+=flow,e[p[x]^1].c-=flow;
        now=max(0ll,now-(dis[t]-las)*sum);
        sum+=flow;
        ans=min(ans,dis[t]-1+(now+sum-1)/sum);
        las=dis[t];
	}
	return ans;
}
inline void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int x,y,z;
        for(int i=1;i<=n;i++)
            head[i]=-1;mm=0;
        nn=n;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            x++;y++;
            add(x,y,z,1);
        }
        if(k==0)
            puts("0");
        else
        {
            long long ga=cost_flow(1,n,k);
            if(ga<(1ll<<60))
                printf("%I64d\n",ga);
            else
                puts("No solution");
        }
    }
    return 0;
}
