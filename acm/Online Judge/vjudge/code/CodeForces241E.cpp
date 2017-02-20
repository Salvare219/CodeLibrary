#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int y,w,next,i;
    p(int y_=0,int w_=0,int n_=0,int i_=0){y=y_;w=w_;next=n_;i=i_;}
}e[20050];
int head[1008],mm;
void add(int x,int y,int w,int i)
{
    e[mm]=p(y,w,head[x],i);
    head[x]=mm++;
}
int dis[1008],q[1020];
bool vis[1008],sol[1008];
int timer[1008];
int n,m;
int spfa(int s,int t)
{
    for(int i=1;i<=n;i++)dis[i]=-0x3fffffff,vis[i]=0,timer[i]=0;
    int tail=0,front=0,x,y;
    q[tail++]=s;dis[s]=0;timer[s]++;
    while(tail!=front)
    {
        x=q[front++];vis[x]=0;
        if(front>1005)front=0;
        for(int i=head[x];~i;i=e[i].next)
            if(sol[y=e[i].y])
            {
                if(dis[x]+e[i].w>dis[y])
                {
                    dis[y]=dis[x]+e[i].w;
                    if(vis[y]==0)
                    {
                        vis[y]=1;
                        q[tail++]=y;
                        timer[y]++;
                        if(timer[y]>n+5)return 0;
                        if(tail>1005)tail=0;
                    }
                }
            }
    }
    return 1;
}
bool ho[1005],mo[1005];
int ans[5005];
pair<int,int>fe[5005],et[5005];
int main()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=n;i++)head[i]=-1;mm=0;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        add(x,y,1,i);
        add(y,x,-2,i);
        et[i]=make_pair(x,y);
        fe[i]=make_pair(y,x);
    }
    sort(et,et+m);sort(fe,fe+m);
    ho[1]=mo[n]=1;
    for(int i=0;i<m;i++)ho[et[i].second]|=ho[et[i].first];
    for(int i=m-1;i>-1;i--)mo[fe[i].second]|=mo[fe[i].first];
    for(int i=1;i<=n;i++)
        if(ho[i]&&mo[i])sol[i]=1;
    if(spfa(1,n))
    {
        puts("Yes");
        for(int i=1;i<=n;i++)
            if(sol[i])
            {
                for(int j=head[i];~j;j=e[j].next)
                    if(e[j].w>0&&sol[e[j].y])
                        ans[e[j].i]=dis[e[j].y]-dis[i];
            }
        for(int i=0;i<m;i++)
            if(ans[i])printf("%d\n",ans[i]);
            else puts("1");
    }
    else puts("No");
    return 0;
}
