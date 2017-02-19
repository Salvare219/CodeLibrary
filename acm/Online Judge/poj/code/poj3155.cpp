#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;



struct edge

{

    int y,next;

    double c;

    edge(int y_=0,double c_=0.0,int n_=0){y=y_,c=c_,next=n_;}

}e[800005];

int head[2005];

int nn,mm;

int d[2005],cont[2005],q[2005];

int pre[2005],cur[2005];

bool vis[2005];

const double eps=1e-17;

void bfs(int s)

{

    int x,to,tail=1,front=0;

    for(int i=1;i<=nn;i++) vis[i]=cont[i]=0,cur[i]=head[i],d[i]=0x3fffffff;

    d[s]=0;cont[0]=1;q[0]=s;vis[s]=1;

    while(front<tail)

        for(int i=head[x=q[front++]];i!=-1;i=e[i].next)

            if(!vis[to=e[i].y] && e[i^1].c>eps)

            {

                d[to]=d[x]+1;

                vis[to]=1;

                q[tail++]=to;

                cont[d[to]]++;

            }

}

double SAP(int s,int t)

{

	if(s==t) return 0x7fffffff;

    bfs(t);pre[s]=-1;

    int x=s,y,len=0,back;

    double ans=0.0,flow;

    while(d[s]<nn)

    {

        y=-1;

        for(int i=cur[x];i!=-1;i=e[i].next)

            if(e[i].c>eps && d[x]==d[e[i].y]+1)

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

void add(int x,int y,double c)

{

    e[mm]=edge(y,c,head[x]);head[x]=mm++;

    e[mm]=edge(x,0,head[y]);head[y]=mm++;

}

pair<int,int>te[2000];

int n,m;

bool ok(double mid)

{

    mm=0;

    int s=nn-1,t=nn;

    for(int i=1;i<=nn;i++)head[i]=-1;

    for(int i=0;i<m;i++)

    {

        add(s,n+i+1,1.0);

        add(n+i+1,te[i].first,1e10);

        add(n+i+1,te[i].second,1e10);

    }

    for(int i=1;i<=n;i++)

        add(i,t,mid);

    return m>SAP(s,t);

}

vector<int>ans;

bool v[500];

void dfs(int s)

{

    v[s]=1;

    for(int i=head[s];~i;i=e[i].next)

        if(v[e[i].y]==0&&e[i].c>eps)

        {

            if(e[i].y<=n)ans.push_back(e[i].y);

            dfs(e[i].y);

        }

}

int main()

{

//    freopen("1.txt","r",stdin);

    int x,y;

    scanf("%d%d",&n,&m);

    nn=n+m+2;

    for(int i=0;i<m;i++)

        scanf("%d%d",&x,&y),te[i]=make_pair(x,y);

    double l=0.0,r=10000.0,mid;

    while(r-l>1e-8)

    {

        mid=(l+r)/2;

        if(ok(mid))l=mid;

        else r=mid;

    }

    ok(l);

    dfs(nn-1);

    if(ans.size()==0)printf("1\n1\n");

    else

    {

        printf("%d\n",ans.size());

        sort(ans.begin(),ans.end());

        for(int i=0;i<ans.size();i++)

            printf("%d\n",ans[i]);

    }

    return 0;

}



