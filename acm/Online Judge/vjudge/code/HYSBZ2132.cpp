#include <bits/stdc++.h>
using namespace std;


struct edge
{
    int y,c,next;
    edge(){}
    edge(int y_,int c_,int n_){y=y_,c=c_,next=n_;}
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
int a[105][105];
int b[105][105];
int c[105][105];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]),ans+=a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&b[i][j]),ans+=b[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&c[i][j]);
    nn=n*m+2;mm=0;
    int s=nn-1,t=nn;
    for(int i=1;i<=nn;i++)head[i]=-1;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if((i+j)&1)
            {
                int f=i*m+j+1;
                add(s,f,a[i][j]);
                add(f,t,b[i][j]);
                for(int z=0;z<4;z++)
                {
                    int x=i+dx[z],y=j+dy[z];
                    if(x>=0&&x<n&&y>=0&&y<m)
                    {
                        add(f,x*m+y+1,c[i][j]+c[x][y]);
                        add(x*m+y+1,f,c[i][j]+c[x][y]);
                        ans+=c[i][j]+c[x][y];
                    }
                }
            }
            else
            {
                int f=i*m+j+1;
                add(s,f,b[i][j]);
                add(f,t,a[i][j]);
            }
    printf("%d\n",ans-SAP(s,t));
    return 0;
}
