#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

using namespace std;





#include<queue>

struct edge

{

    int y,c,next;

    edge(int y1=0,int c1=0,int ne=0){y=y1,c=c1,next=ne;}

}e[805];

int head[805];

int n,m;

int d[805],cont[805];

int pre[805],cur[805];

bool vis[805];

void bfs(int s)

{

    int x,to;

    queue<int> que;

    for(int i=1;i<=n;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;

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

    while(d[s]<n)

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

            y=n;

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

    e[m]=edge(y,c,head[x]);head[x]=m++;

    e[m]=edge(x,0,head[y]);head[y]=m++;

}

int main()

{

    while(scanf("%d%d",&m,&n)==2)

    {

        int x,y,c,te=m;

        for(int i=1;i<=n;i++)

            head[i]=-1;m=0;

        for(int i=0;i<te;i++)

            scanf("%d%d%d",&x,&y,&c),add(x,y,c);

        printf("%d\n",SAP(1,n));

    }

    return 0;

}

