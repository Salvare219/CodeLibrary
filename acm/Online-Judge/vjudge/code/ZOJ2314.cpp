#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

int n,m;
int now[205];
vector<int> gra[205];
int d[205],cont[205];
int cap[205][205];
int pre[205],cur[205];
bool vis[205];
void bfs(int t,int s)
{
    int x,to;
    queue<int> que;
    for(int i=0;i<n;i++) vis[i]=cont[i]=cur[i]=0,d[i]=0x3fffffff;
    d[t]=0;cont[0]=1;
    que.push(t);vis[t]=1;
    while(!que.empty())
    {
        x=que.front();que.pop();
        for(int i=0;i<gra[x].size();i++)
        {
            to=gra[x][i];
            if(vis[to]==0 && cap[to][x])
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
    bfs(t,s);
    int ans=0,x=s,y,flow,back,temp;
    while(d[s]<n)
    {
        y=-1;
        if(x==73)
            int kk=0;
        for(int i=cur[x];i<gra[x].size();i++)
            if(cap[x][gra[x][i]] && d[x]==d[gra[x][i]]+1)
            {
                y=gra[x][i];
                cur[x]=i;
                break;
            }
        if(y!=-1)
        {
            pre[y]=x;
            x=y;
            if(x==t)
            {
                flow=0x3fffffff;
                for(;y!=s;y=pre[y])
                    if(flow>cap[pre[y]][y]) flow=cap[pre[y]][y],back=pre[y];
                for(;x!=s;x=pre[x])
                    cap[x][pre[x]]+=flow,cap[pre[x]][x]-=flow;
                ans+=flow;
                x=back;
            }
        }
        else
        {
            y=n;
            for(int i=0;i<gra[x].size();i++)
                if(cap[x][gra[x][i]] && y>d[gra[x][i]])
                    y=d[gra[x][i]],cur[x]=i;
            cont[d[x]]--;
            if(cont[d[x]]==0) break;
            cont[y+1]++;
            d[x]=y+1;
            if(x!=s) x=pre[x];
        }
    }
    return ans;
}
int fa[40005][3];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x,y,l,r;
        scanf("%d%d",&n,&m);
        memset(now,0,sizeof(now));
        for(int i=1;i<n+3;i++) gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&x,&y,&l,&r);
            cap[x][y]=r-l;cap[y][x]=0;
            gra[x].push_back(y);
            gra[y].push_back(x);
            now[x]-=l;now[y]+=l;
            fa[i][0]=x;fa[i][1]=y;fa[i][2]=r;
        }
        int sum=0;
        for(int i=1;i<=n;i++)
            if(now[i]>0) gra[n+1].push_back(i),gra[i].push_back(n+1),cap[n+1][i]=now[i],sum+=now[i];
            else if(now[i]<0) gra[i].push_back(n+2),gra[n+2].push_back(i),cap[i][n+2]=-now[i];
        n+=2;
        if(SAP(n-1,n)==sum)
        {
            printf("YES\n");
            for(int i=0;i<m;i++)
                printf("%d\n",fa[i][2]-cap[fa[i][0]][fa[i][1]]);
        }
        else printf("NO\n");
        putchar(10);
    }
    return 0;
}
