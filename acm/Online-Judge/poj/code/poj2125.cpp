#include<cstdio>

#include<cstring>

#include<cmath>

#include<algorithm>

#include<vector>

#include<queue>

using namespace std;



#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <algorithm>

#include <string>

#include <queue>

using namespace std;





/*

#define mo 9999991

#define eps 1e-18

#define ep 1e-8

#define inf 10000000

const int MAXN=1000,MAXM=2000005;

int s,t,dis[MAXN],head[MAXN],gap[MAXN],cnt;

struct EDGE

{

    int to,f,nxt;

}edge[MAXM];



void add_edge(int x,int y,int c)

{

    edge[cnt].to=y;

    edge[cnt].f=c;

    edge[cnt].nxt=head[x];

    head[x]=cnt++;

}

void add(int x,int y,int c)

{

    add_edge(x,y,c);

    add_edge(y,x,0);

}

void ini()

{

    memset(head,-1,sizeof(head));

    memset(dis,0,sizeof(dis));

    memset(gap,0,sizeof(gap));

    cnt=0;

}

int dfs(int x,int flow)

{

    if(x==t)

    return flow;

    int temp=flow;

    int pos=t-1;

    int j;

    for(j=head[x];j!=-1;j=edge[j].nxt)

    {

        int y=edge[j].to;

        int c=edge[j].f;

        if(c>0&&dis[x]==dis[y]+1)

        {

            int temp_flow=dfs(y,min(temp,c));

            temp-=temp_flow;

            edge[j].f-=temp_flow;

            edge[j^1].f+=temp_flow;

            if(temp==0||dis[s]==t)

            return flow-temp;

        }

        if(c>0&&pos>dis[y])

        pos=dis[y];

    }

    if(temp==flow)

    {

        if(!(--gap[dis[x]]))

        dis[s]=t;

        else

        gap[dis[x]=pos+1]++;

    }

    return flow-temp;

}

int sap()

{

    int maxflow=0;

    gap[0]=t;

    while(dis[s]<t)

    {

        maxflow+=dfs(s,inf);

    }

    return maxflow;

}





int n,m,sum;

int wp[101],wd[101];

int pick[101];

bool setsu[2000];

int ans1[300];char ans2[300];

void search()

{

    memset(setsu,0,sizeof(setsu));

    queue <int> q;

    q.push(s);

    setsu[s]=1;

    while(!q.empty()){

        int a=q.front();q.pop();

        for(int p=head[a];p!=-1;p=edge[p].nxt){

            int v=edge[p].to;

            if(!setsu[v] && edge[p].f!=0){

                setsu[v]=1;

                q.push(v);

            }

        }

    }

}

int main()

{

    scanf("%d%d",&n,&m);

    s=2*n+1;t=s+1;

    ini();

    for(int i=1;i<=n;i++){

        scanf("%d",&wp[i]);

        add(i+n,t,wp[i]);

    }

    for(int i=1;i<=n;i++){

        scanf("%d",&wd[i]);

        add(s,i,wd[i]);

    }

    for(int i=1,a,b;i<=m;i++){

        scanf("%d%d",&a,&b);

        add(a,n+b,inf);

    }

    int a=sap();

    search();

    printf("%d\n",a);

    for(int i=1;i<=2*n;i++){

        if(i<=n){

            if(!setsu[i]){

                ans1[++sum]=i;ans2[sum]='-';

            }

        }

        else{

            if(setsu[i]){

                ans1[++sum]=i-n;ans2[sum]='+';

            }

        }

    }

    printf("%d\n",sum);

    for(int i=1;i<=sum;i++){

        printf("%d %c\n",ans1[i],ans2[i]);

    }

    return 0;

}

*/





#include <iostream>

#include <cstdio>

#include <cstring>

#include <cstdlib>

#include <cmath>

#include <algorithm>

#include <string>

#include <queue>

using namespace std;

#define mo 9999991

#define eps 1e-17

#define ep 1e-8

#define inf 10000000

const int MAXN=1000,MAXM=2000000;

struct edge

{

    int y,c,next;

edge(){}

    edge(int y_,int c_,int n_){y=y_,c=c_,next=n_;}

}e[MAXM];

int head[MAXN];

int nn,mm;

int d[MAXN],cont[MAXN];

int pre[MAXN],cur[MAXN];

void init()

{

    memset(head,-1,sizeof(head));

    mm=0;

}

/*

void bfs(int s)

{

    int x,to,tail=1,front=0;

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

}*/

int SAP(int s,int t)

{

    if(s==t) return 0x7fffffff;

    for(int i=1;i<=nn;i++)

        cont[i]=0,cur[i]=head[i],d[i]=0;

    cont[0]=nn;

    pre[s]=-1;

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

int n,m;

int ans1[301];

char ans2[301];

bool setsu[2001];

void search(int s)

{

    queue <int> q;

    q.push(s);

    memset(setsu,0,sizeof(setsu));

    setsu[s]=1;

    while(!q.empty()){

        int a=q.front();q.pop();

        for(int p=head[a];p!=-1;p=e[p].next){

            int v=e[p].y;

            if(!setsu[v] && e[p].c!=0){

                setsu[v]=1;

                q.push(v);

            }

        }

    }

}

int main()

{

    scanf("%d%d",&n,&m);

    init();

    int s=2*n+1;int t=s+1;

    nn=t;

    for(int i=1,a;i<=n;i++){

        scanf("%d",&a);

        add(n+i,t,a);

    }

    for(int i=1,a;i<=n;i++){

        scanf("%d",&a);

        add(s,i,a);

    }

    for(int i=1,a,b;i<=m;i++){

        scanf("%d%d",&a,&b);

        add(a,b+n,inf);

    }

    int ans=SAP(s,t);

    int sum=0;

    search(s);

    for(int i=1;i<=2*n;i++){

        if(i<=n){

            if(!setsu[i]){

                ans1[++sum]=i;ans2[sum]='-';

            }

        }

        else{

            if(setsu[i]){

                ans1[++sum]=i-n;ans2[sum]='+';

            }

        }

    }

    printf("%d\n",ans);

    printf("%d\n",sum);

    for(int i=1;i<=sum;i++){

        printf("%d %c\n",ans1[i],ans2[i]);

    }

    return 0;

}