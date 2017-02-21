#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
#define maxn 209
#define maxm 20000
#define INF 1e9

struct AA
{
    int vv[50];
    vector<int>gra[50];
    vector<int>w1[50],w2[50];
    int solv(int n,int m,int u[],int v[],int d[],int b[])
    {
        int lim=1<<n;
        for(int i=0;i<n;i++)
        {
            gra[i].clear();
            w1[i].clear();
            w2[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            gra[u[i]-1].push_back(v[i]-1);
            w1[u[i]-1].push_back(d[i]);
            w2[u[i]-1].push_back(d[i]+b[i]);
        }
        for(int i=0;i<lim;i++)
        {
            memset(vv,0,sizeof(vv));
            for(int j=0;j<n;j++)
                if((1<<j)&i)
                    vv[j]=1;
            int sum=0;
            for(int j=0;j<n;j++)
                if(vv[j])
                {
                    for(int k=0;k<gra[j].size();k++)
                        if(vv[gra[j][k]]==0)
                            sum+=w1[j][k];
                }
                else
                {
                    for(int k=0;k<gra[j].size();k++)
                        if(vv[gra[j][k]])
                            sum-=w2[j][k];
                }
            if(sum>0)
                return 0;
        }
        return 1;
    }
}A;
struct BB
{
    struct Edge
    {
        int v,cap,next;
    }edge[maxm];
    int n,tot,src,des;
    int head[maxn],h[maxn],gap[maxn],B[maxn];
    void addedge(int u,int v,int cap)
    {
        edge[tot].v=v;
        edge[tot].cap=cap;
        edge[tot].next=head[u];
        head[u]=tot++;
        edge[tot].v=u;
        edge[tot].cap=0;
        edge[tot].next=head[v];
        head[v]=tot++;
    }
    int dfs(int u,int cap)
    {
        if(u==des)return cap;
        int minh=n-1;
        int lv=cap,d;
        for(int e=head[u];e!=-1;e=edge[e].next)
        {
            int v=edge[e].v;
            if(edge[e].cap>0)
            {
                if(h[v]+1==h[u])
                {
                    d=min(lv,edge[e].cap);
                    d=dfs(v,d);
                    edge[e].cap-=d;
                    edge[e^1].cap+=d;
                    lv-=d;
                    if(h[src]>=n)return cap-lv;
                    if(lv==0)
                        break;
                }
                minh=min(minh,h[v]);
            }
        }
        if(lv==cap)
        {
            --gap[h[u]];
            if(gap[h[u]]==0)
                h[src]=n;
            h[u]=minh+1;
            ++gap[h[u]];
        }
        return cap-lv;
    }
    int sap()
    {
        int flow=0;
        memset(gap,0,sizeof(gap));
        memset(h,0,sizeof(h));
        gap[0]=n;
        while(h[src]<n)flow+=dfs(src,INF);
        return flow;
    }
    int solv(int nn,int mm,int uu[],int vv[],int dd[],int bb[])
    {
        int N=nn,M=mm;
        memset(head,-1,sizeof(head));
        memset(B,0,sizeof(B));
        tot=0;src=0;des=N+1;n=des+1;
        for(int i=1;i<=M;i++)
        {
            int u=uu[i-1];
            int v=vv[i-1];
            int b=dd[i-1];
            int l=bb[i-1];
            addedge(u,v,l);
            B[v]+=b;B[u]-=b;
        }
        int sum=0;
        for(int i=1;i<=N;i++)
        {
            if(B[i]>0)
            {
                addedge(src,i,B[i]);
                sum+=B[i];
            }
            else if(B[i]<0)
            {
                addedge(i,des,-B[i]);
            }
        }
        int flow=sap();
        if(flow==sum)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}B;
struct P
{
    int scc[202],dfn[202],low[202], ss[202];
    int num, cnt, o;
    bool vis[202];
    vector <int> edge[202];
    void init() {
        o = cnt = num =0;
        memset(dfn,0,sizeof(dfn));
        memset(vis,0,sizeof(vis));
    }
    void tarjan(int x) {
        dfn[x] = low[x] = ++num;
        ss[++o] = x; vis[x] = 1;
        for(int i = 0; i < edge[x].size(); i++) {
            int v = edge[x][i];
            if(!dfn[v]) {
                tarjan(v);
                low[x] = min(low[x], low[v]);
            } else if(vis[v]) {
                low[x] = min(low[x], dfn[v]);
            }
        }
        if(dfn[x] == low[x]) {
            cnt++; int y = -1;
            while(x!=y) {
                y = ss[o--]; vis[y] = 0; scc[y] = cnt;
            }
        }
    }
    bool aox[202][202];
    int n, m;
    struct node {
        int u, v, a, b;
    }box[400];
    int rands(int &nn,int &mm,int uu[],int vv[],int dd[],int bb[])
    {
        for(int ii = 1; ii <= 1; ii++) {
            n = 4; m = rand() % 10;
            memset(aox,0,sizeof(aox));
            for(int i = 1; i <= n; i++) edge[i].clear();

            for(int i = 1; i <= m; i++) {
                int u = rand() % n + 1; int v = rand() % n + 1;
                if(u == v || aox[u][v]) {
                    i--; continue;
                }
                aox[u][v] = 1;
                edge[u].push_back(v);
                box[i].u = u; box[i].v = v; box[i].a = rand() % 10 + 1; box[i].b = rand() % 10 + 1;
            }

            init();
            bool can = 1;
            tarjan(1);
            for(int i = 1; i <= n; i++) {
                if(!dfn[i]) {
                    can = 0;
                    break;
                }
            }
            if(!can) {ii--; continue;}
            int a = scc[1];
            for(int i = 1; i <= n; i++) {
                if(a != scc[i]) {
                    can = 0;
                    break;
                }
            }
            if(!can) {ii--; continue;}

            nn=n;mm=m;//printf("%d %d\n", n, m);
            for(int i = 1; i <= m; i++)
            {
                uu[i-1]=box[i].u;
                vv[i-1]=box[i].v;
                dd[i-1]=box[i].a;
                bb[i-1]=box[i].b;
            }
        }
        return 0;
    }
}C;


int u[5500],v[5500],d[5500],b[5500];
int main()
{
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for(int i=0;i<m;i++)
            scanf("%d%d%d%d",u+i,v+i,d+i,b+i);
        printf("Case #%d: ",ti++);
        puts(B.solv(n,m,u,v,d,b)?"happy":"unhappy");
    }
    return 0;
}


/*
int u[55],v[55],d[55],b[55];
int main()
{
    //freopen("3.txt","w",stdout);
    int cnt=0;
    while(1)
    {
        int n,m;cnt++;
        C.rands(n,m,u,v,d,b);
        int aa=A.solv(n,m,u,v,d,b);
        int bb=B.solv(n,m,u,v,d,b);
        if(cnt%100==0)
            puts("F");
        if(aa!=bb)
        {
            printf("%d %d\n",n,m);
            for(int i=0;i<m;i++)
                printf("%d %d %d %d\n",u[i],v[i],d[i],b[i]);
            break;
        }
    }
    return 0;
}*/
/*
4 9
3 2 5 3
1 3 8 6
3 4 3 6
2 3 5 5
1 4 4 1
4 2 9 8
4 1 3 6
3 1 4 8
2 4 3 3
*/
