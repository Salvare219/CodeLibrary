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
    edge(int y1=0,int c1=0,int ne=0){y=y1,c=c1,next=ne;}
}e[30005];
int head[2605];
int nn,mm;
int d[2605],cont[2605];
int pre[2605],cur[2605];
bool vis[2605];
void bfs(int s)
{
    int x,to;
    queue<int> que;
    for(int i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;
    d[s]=0;cont[0]=1;
    que.push(s);vis[s]=1;
    while(!que.empty())
    {
        x=que.front();que.pop();
        for(int i=head[x];i!=-1;i=e[i].next)
        {
            to=e[i].y;
            if(!vis[to] && e[i^1].c)
            {
                d[to]=d[x]+1;
                vis[to]=1;
                que.push(to);
                cont[d[to]]++;
            }
        }
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
                    if(flow>e[cur[y]].c) flow=e[cur[y]].c,back=y;
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
char maz[100][100];
int dy[]={0,0,1,-1},dx[]={1,-1,0,0};
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m,dd,ff,bb;scanf("%d%d%d%d%d",&m,&n,&dd,&ff,&bb);
        for(int i=0;i<n;i++)
            scanf("%s",maz[i]);
        nn=n*m+2;mm=0;
        memset(head,-1,sizeof(head));
        int s=nn-1,t=nn,ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(i==0||i==n-1||j==0||j==m-1)
                {
                    if(maz[i][j]!='#')ans+=ff;
                    add(s,i*m+j+1,0x3fffffff);
                }
                else
                {
                    if(maz[i][j]=='.')add(i*m+j+1,t,ff);
                    else add(s,i*m+j+1,dd);
                }
                for(int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if(-1<x&&x<n&&-1<y&&y<m)
                        add(i*m+j+1,x*m+y+1,bb);
                }
            }
        printf("%d\n",ans+SAP(s,t));
    }
    return 0;
}
