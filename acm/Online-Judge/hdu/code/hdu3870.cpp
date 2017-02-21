#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

#include<queue>
struct edge
{
    int y,w,next;
    edge(int y_=0,int w_=0,int n_=0){y=y_,w=w_,next=n_;}
}e[700005];
int dis[160005],head[160005];
int nn,mm;
bool vis[160005];
inline int Dijkstra(int s,int t)
{
    int mdis,mx,k=1,to,w;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
    for(int i=1;i<=nn;i++) dis[i]=0x3fffffff,vis[i]=0;
    q.push(make_pair(0,s));dis[s]=0;
    while(!q.empty())
    {
        mdis=q.top().first;
        mx=q.top().second;q.pop();
        if(vis[mx]) continue;
        if(mx==t) return mdis;
        vis[mx]=1;
        for(int i=head[mx];~i;i=e[i].next)
            if(dis[to=e[i].y]>(w=e[i].w)+mdis)
                dis[to]=w+mdis,q.push(make_pair(dis[to],to));
    }
    return -1;
}
inline void add(int x,int y,int w)
{
    e[mm]=edge(y,w,head[x]);head[x]=mm++;
    e[mm]=edge(x,w,head[y]);head[y]=mm++;
}
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,x,y;
        scanf("%d",&n);
        nn=(n-1)*(n-1)+2;
        int s=nn-1,t=nn;mm=0;
        for(int i=1;i<=nn;i++)head[i]=-1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
            {
                scanf("%d",&y);x=i*(n-1)+j+1;
                if(i+1!=n)
                {
                    if(j==0)add(s,x,y);
                    else if(j+1==n)add(t,x-1,y);
                    else add(x-1,x,y);
                }
                if(j+1!=n)
                {
                    if(i==0)add(t,x,y);
                    else if(i+1==n)add(s,x-n+1,y);
                    else add(x-n+1,x,y);
                }
            }
        printf("%d\n",Dijkstra(s,t));
    }
    return 0;
}
