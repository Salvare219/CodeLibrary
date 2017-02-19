#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


vector<int>gra[500050];
int pre[500050][20];
int dep[500050];
bool cho[500050];
void dfs(int s,int p)
{
    int t=0;
    pre[s][0]=p;
    while(pre[s][t]) pre[s][t+1]=pre[pre[s][t]][t],t++;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            dep[gra[s][i]]=dep[s]+1;
            dfs(gra[s][i],s);
        }
}
int lca(int x,int y)
{
    int s=19;
    if(dep[x]>dep[y]) swap(x,y);
    while(dep[x]<dep[y])
        y=dep[pre[y][s]]<dep[x]?y:pre[y][s],s--;
    if(x==y) return x;
    else
    {
        s=19;
        while(s!=-1)
        {
            if(pre[x][s]!=pre[y][s])
                x=pre[x][s],y=pre[y][s];
            s--;
        }
        return pre[x][0];
    }
}
void dfs2(int s,int p)
{
    cho[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            if(cho[gra[s][i]]==0)
                dfs2(gra[s][i],s);
        }
}
int xx[500050];
int yy[500050];
int ll[500050];
pair<int,int>ps[500050];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int x,y;
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
            gra[i].clear(),cho[i]=0,pre[i][0]=0;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            gra[x].push_back(y);
            gra[y].push_back(x);
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&x,&y);
            xx[i]=x;
            yy[i]=y;
        }
        dep[1]=1;dfs(1,0);
        for(int i=0;i<m;i++)
            ps[i]=make_pair(dep[ll[i]=lca(xx[i],yy[i])],i);
        sort(ps,ps+m);
        int ans=0;
        for(int i=m-1;i>-1;i--)
        {
            int ind=ps[i].second;
            if(cho[xx[ind]]==0&&cho[yy[ind]]==0)
            {
                dfs2(ll[ind],pre[ll[ind]][0]);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}