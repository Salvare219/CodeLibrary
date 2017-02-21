#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,m;
vector<int> gra[2005];
bool vis[2005];
int stack[2005],k;
int low[2005],scc[2005];
int timer,cnt;
void tarjan(int s)
{
    vis[s]=1;
    int to,temp=low[s]=++timer;
    stack[k++]=s;
    for(int i=0;i<gra[s].size();i++)
    {
        to=gra[s][i];
        if(vis[to]==0) tarjan(to);
        low[s]=min(low[to],low[s]);
    }
    if(temp==low[s])
    {
        do
        {
            to=stack[--k];
            low[to]=0x3fffffff;
            scc[to]=cnt;
        }while(stack[k]!=s);
        cnt++;
    }
}
int main()
{
//    freopen("1.txt","r",stdin);
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            int x;
            scanf("%d",&x);
            if(x)gra[i].push_back(j);
        }
    memset(vis,0,sizeof(vis));
    cnt=1;timer=0;
    for(int i=0;i<n;i++)
        if(vis[i]==0)tarjan(i);
    bool f=1;
    for(int i=0;i<n;i++)
        if(scc[i]!=scc[0])f=0;
    puts(f?"YES":"NO");
    return 0;
}
