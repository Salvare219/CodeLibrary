#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

vector<int>gra[3005];
bool vis[3005];
int stack[3005],k;
int low[3005],scc[3005];
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
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        int x,y;
        for(int i=1;i<=2*n;i++)gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            if(x>0&&y>0)
            {
                gra[x+n].push_back(y);
                gra[y+n].push_back(x);
            }
            else if(x>0&&y<0)
            {
                gra[x+n].push_back(-y+n);
                gra[-y].push_back(x);
            }
            else if(x<0&&y>0)
            {
                gra[-x].push_back(y);
                gra[y+n].push_back(-x+n);
            }
            else
            {
                gra[-x].push_back(-y+n);
                gra[-y].push_back(-x+n);
            }
        }
        memset(vis,0,sizeof(vis));
        memset(scc,0,sizeof(scc));
        cnt=1;timer=0;
        bool flag=1;
        for(int i=1;i<=n;i++)
        {
            if(scc[i]==0 && scc[i+n]==0) tarjan(i);
            if(scc[i]==scc[i+n])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            if(scc[1] && scc[1+n])
            {
                if(scc[1+n]>scc[1]) x=1;
                else x=1+n;
            }
            else
            {
x=1;
            }
            if(x==1+n)puts("no");
            else puts("yes");
        }
        else puts("no");
    }
    return 0;
}