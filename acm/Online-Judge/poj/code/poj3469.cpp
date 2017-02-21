#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


struct edge
{
    int y,c,next;
    edge(){}
    edge(int y_,int c_,int n_){y=y_,c=c_,next=n_;}
}e[500005];
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
inline void add(int x,int y,int c,int d)
{
    e[mm]=edge(y,c,head[x]);head[x]=mm++;
    e[mm]=edge(x,d,head[y]);head[y]=mm++;
}
inline int Int()
{
	int a=0;char c=getchar();
	while(c<'0')c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+c-'0',c=getchar();
	return a;
}
inline void out(int c)
{
    if(c>9)out(c/10);
    putchar(c-c/10*10+'0');
}
int main()
{
    int n=Int(),m=Int(),x,y,c,sum=0;
    nn=n+2;
    for(int i=1;i<=nn;i++)
        head[i]=-1;mm=0;
    for(int i=1;i<=n;i++)
    {
        x=Int();y=Int();
        if(x>y)sum+=y,add(nn-1,i,x-y,0);
        else if(x<y)sum+=x,add(i,nn,y-x,0);
        else sum+=x;
    }
    for(int i=0;i<m;i++)
        x=Int(),y=Int(),c=Int(),add(x,y,c,c);
    out(sum+SAP(n+1,n+2));putchar(10);
    return 0;
}
