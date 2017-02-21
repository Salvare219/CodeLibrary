#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#define INF 0x3fffffff
#define MAXN 700
using namespace std;
typedef int type;
struct Edge
{
    int x,y;
    type w;
}edge[2*MAXN*MAXN];  //注意去除自环
type in[MAXN];
int vis[MAXN],p[MAXN],id[MAXN];
type Minimum_Arborescence(int root,int nn,int mm)
{
    type ans=0;
    int cnt,nod=nn,x,y;
    while(1)
    {
        for(int i=1;i<=nod;i++)in[i]=INF;
        for(int i=0;i<mm;i++)
            if(in[edge[i].y]>edge[i].w&&edge[i].x!=edge[i].y)
            {
                in[edge[i].y]=edge[i].w;
                p[edge[i].y]=edge[i].x;
            }
        in[root]=0;
        for(int i=1;i<=nod;i++)
            if(in[i]==INF)return -1;
        cnt=1;
        for(int i=1;i<=nod;i++)
            id[i]=-1,vis[i]=-1;
        for(int i=1;i<=nod;i++)
        {
            ans+=in[i];x=i;
            while(vis[x]!=i && id[x]==-1 && x!=root)
                vis[x]=i,x=p[x];
            if(x!=root && id[x]==-1)
            {
                for(y=p[x];x!=y;y=p[y])
                    id[y]=cnt;
                id[x]=cnt++;
            }
        }
        if(cnt==1) return ans;
        for(int i=1;i<=nod;i++)
            if(id[i]==-1)id[i]=cnt++;
        for(int i=0;i<mm;i++)
        {
            y=edge[i].y;
            edge[i].x=id[edge[i].x];
            edge[i].y=id[edge[i].y];
            if(edge[i].x!=edge[i].y) edge[i].w-=in[y];
        }
        nod=cnt-1;
        root=id[root];
    }
}
int a[100],sum[100];
int totn,totm;
void addedge(int x,int y,int w)
{
    edge[totm].x=x;
    edge[totm].y=y;
    edge[totm].w=w;
    totm++;
    //cout<<x+1<<' '<<y+1<<' '<<w<<endl;
}
int lab[55][550];
int main()
{
    //freopen("input.txt","r",stdin);
    int n,m;
    while(scanf("%d%d",&n,&m) != EOF)
    {
        if (n==0 && m==0) break;
        sum[0]=0;
        //init();
        int tot=1,root=1;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i]+1;
            for(int j=0;j<=a[i];j++)
                lab[i][j]=++tot;
        }
        totn=sum[n],totm=0;
        for (int i = 1; i <= n; ++i)
        {
            addedge(root,lab[i][0],0);
            for (int j = 1; j <= a[i]; ++j)
            {
                addedge(lab[i][j],lab[i][j-1],0);
            }
        }
        for (int i = 0; i < m; ++i)
        {
            int c,l1,d,l2,money;
            scanf("%d%d%d%d%d",&c,&l1,&d,&l2,&money);
            addedge(lab[c][l1],lab[d][l2],money);
        }
       // cout<<totn<<' '<<totm<<endl;
        int ans=Minimum_Arborescence(root,totn+1,totm);
        printf("%d\n", ans);
    }
    return 0;
}
