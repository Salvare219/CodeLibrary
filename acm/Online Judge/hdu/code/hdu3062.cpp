#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;


vector<int> gra[2005];
bool vis[2005];
int stack[2005],k;
int low[2005],dfn[2005],scc[2005];
int timer,cnt;
void tarjan_scc(int s)
{
    vis[s]=1;
    low[s]=dfn[s]=++timer;
    stack[k++]=s;
    int to;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(dfn[to]==0)
        {
            tarjan_scc(to);
            low[s]=min(low[to],low[s]);
        }
        else if(vis[to]) low[s]=min(dfn[to],low[s]);
    }
    if(dfn[s]==low[s])
    {
        do
        {
            to=stack[--k];
            vis[to]=0;
            scc[to]=cnt;
        }while(stack[k]!=s);
        cnt++;
    }
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n,m;
    int a,b,c,d;
    while(scanf("%d%d",&n,&m)==2)
    {
        n<<=1;
        for(int i=1;i<=n;i++)
            gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a=2*a+1;b=2*b+1;
            gra[a+c].push_back(b+(!d));
            gra[b+d].push_back(a+(!c));
        }
        memset(scc,0,sizeof(scc));
        memset(dfn,0,sizeof(dfn));
        cnt=1;timer=0;
        bool flag=1;
        for(int i=1;i<n;i+=2)
        {
            if(scc[i]==0 && scc[i+1]==0) tarjan_scc(i);
            if(scc[i]==scc[i+1]) 
            {
                flag=0;break;
            }
        }
        if(flag) 
        {
            printf("YES\n");
        }
        else printf("NO\n");
    }
    return 0;
}