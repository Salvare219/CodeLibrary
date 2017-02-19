#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

struct p
{
    int y,w,next;
    p(int y_=0,int w_=0,int n_=0){y=y_;w=w_;next=n_;}
}e[300050];
int head[50008],mm;
void add(int x,int y,int w)
{
    e[mm]=p(y,w,head[x]);
    head[x]=mm++;
}
int dis[50008],q[50020];
bool vis[50008];
int spfa(int s,int t)
{
    for(int i=0;i<50005;i++)dis[i]=-1,vis[i]=0;
    int tail=0,front=0,x,y;
    q[tail++]=s;dis[s]=0;
    while(tail!=front)
    {
        x=q[front++];vis[x]=0;
        if(front>50005)front=0;
        for(int i=head[x];~i;i=e[i].next)
        {
            y=e[i].y;
            if(dis[x]+e[i].w>dis[y])
            {
                dis[y]=dis[x]+e[i].w;
                if(vis[y]==0)
                {
                    vis[y]=1;
                    q[tail++]=y;
                    if(tail>50005)tail=0;
                }
            }
        }
    }
    return dis[t];
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int x,y,w;
        for(int i=0;i<50005;i++)head[i]=-1;
        mm=0;
        for(int i=0;i<n;i++)
            scanf("%d%d%d",&x,&y,&w),add(x,y+1,w);
        for(int i=0;i<50004;i++)
            add(i,i+1,0),add(i+1,i,-1);
        printf("%d\n",spfa(0,50004));
    }
    return 0;
}