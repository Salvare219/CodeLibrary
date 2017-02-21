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
    edge(int y_=0,int c_=0,int n_=0){y=y_,c=c_,next=n_;}
}e[900005];
int head[20005];
int nn,mm;
int d[20005],cont[20005],q[20005];
int pre[20005],cur[20005];
bool vis[20005];
void bfs(int s)
{
    int x,to,tail=1,front=0;
    for(int i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;
    d[s]=0;cont[0]=1;q[0]=s;vis[s]=1;
    while(front<tail)
        for(int i=head[x=q[front++]];i!=-1;i=e[i].next)
            if(!vis[to=e[i].y] && e[i^1].c)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                q[tail++]=to;
                cont[d[to]]++;
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
                    if(flow>=e[cur[y]].c) flow=e[cur[y]].c,back=y;
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
    e[mm]=edge(y,c,head[x]);head[x]=mm++;
    e[mm]=edge(x,0,head[y]);head[y]=mm++;
}
int main()
{
    int n,k,x,y,ti=1;
    while(scanf("%d%d",&k,&n)&&k)
    {
        nn=2*n;getchar();
        for(int i=1;i<=nn;i++)
            head[i]=-1;mm=0;
        for(int i=3;i<=n;i++)
            add(i,i+n,1);
        add(1,1+n,k);add(2,2+n,k);
        for(int i=1;i<=n;i++)
        {
            char c=0;
            while(c!=10)
                scanf("%d%c",&x,&c),add(i+n,x,1);
        }
        printf("Case %d:\n",ti++);
        if(SAP(1,2+n)==k)
            for(int i=0;i<k;i++)
            {
                x=n+1;printf("%d",1);
                while(x!=n+2)
                {
                    for(int i=head[x];i!=-1;i=e[i].next)
                        if(e[i].c==0)
                        {
                            x=e[i].y+n;
                            e[i].c=1;break;
                        }
                    printf(" %d",x-n);
                }
                putchar(10);
            }
        else puts("Impossible");
        putchar(10);
    }
    return 0;
}