#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct edge
{
    int y,c,f,next;
    edge(int y_=0,int c_=0,int f_=0,int n_=0){y=y_,c=c_,f=f_,next=n_;}
}e[2007000];
int head[2005];
int nn,mm;
int q[2005],p[2005],dis[2005];
bool vis[2005];
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
int cost_flow(int s,int t)
{
	int ans=0,flow,x;
	while(spfa(s,t))
	{
	    flow=0x3fffffff;
		for(x=t;x!=s;x=e[p[x]].y) flow=min(flow,e[p[x]^1].c);
		for(x=t;x!=s;x=e[p[x]].y)
			e[p[x]].c+=flow,e[p[x]^1].c-=flow,ans+=flow*e[p[x]^1].f;
	}
	return ans;
}
inline void add(int x,int y,int c,int f)
{
    e[mm]=edge(y,c,f,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,-f,head[y]);head[y]=mm++;
}
int sa[405],a[205],b[205],w[205];
#include<map>
map<int,int>mp;
int main()
{
    int t,n,k;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
            scanf("%d%d%d",a+i,b+i,w+i),sa[i]=a[i],sa[i+n]=b[i];
        sort(sa,sa+n+n);mp.clear();
        int l=unique(sa,sa+n+n)-sa;
        nn=l+1;mm=0;
        for(int i=1;i<=nn;i++)head[i]=-1;
        for(int i=1;i<=l;i++)mp[sa[i-1]]=i;
        for(int i=1;i<l;i++)add(i,i+1,k,0);
        for(int i=0;i<n;i++)add(mp[a[i]],mp[b[i]],1,-w[i]);
        add(nn,1,k,0);
        printf("%d\n",-cost_flow(nn,l));
    }
	return 0;
}
