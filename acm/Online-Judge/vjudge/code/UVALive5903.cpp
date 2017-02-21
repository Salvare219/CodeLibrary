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
}e[4000005];
int head[500050];
int nn,mm;
int d[500050],cont[500050];
int pre[500050],cur[500050];
bool vis[500050];
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
char maz[600][600];
int cnt[600][600];
int dx[]={0,0,1,-1},dy[]={1,-1,0,0};
int main()
{
    int t;scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%s",maz[i+1]+1);
        int a=1,b=1,c=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(i&1)maz[i][j]=='W'?(cnt[i][j]=a++):0;
                else maz[i][j]=='W'?(cnt[i][j]=b++):0;
                maz[i][j]=='B'?(cnt[i][j]=c++):0;
            }
        a--;b--;c--;
        if(a==c&&b==c)
        {
            int s=a+b+2*c+1,t=a+b+2*c+2;
            nn=t;mm=0;
            bool sb=1;
            for(int i=1;i<=nn;i++)head[i]=-1;
            for(int i=1;i<=n&&sb;i++)
                for(int j=1;j<=m&&sb;j++)
                    if(maz[i][j]=='W')
                    {
                        bool f=i&1,o=1;
                        f?add(s,cnt[i][j],1):add(cnt[i][j]+a,t,1);
                        for(int k=0;k<4;k++)
                        {
                            int x=i+dx[k],y=j+dy[k];
                            if(maz[x][y]=='B')
                                f?add(cnt[i][j],cnt[x][y]+a+b,1):add(cnt[x][y]+a+b+c,cnt[i][j]+a,1),o=0;
                        }
                        if(o)sb=0;
                    }
                    else if(maz[i][j]=='B')add(cnt[i][j]+a+b,cnt[i][j]+a+b+c,1);
            if(sb&&SAP(s,t)==c)puts("YES");
            else puts("NO");
        }
        else puts("NO");
    }
	return 0;
}
