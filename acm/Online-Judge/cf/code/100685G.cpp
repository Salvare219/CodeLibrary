#include<bits/stdc++.h>
using namespace std;


vector<int>gra[100050],wic[100050];
int pre[100050][20];
int dep[100050];
int dw[100050],up[100050];
void dfs(int s,int p)
{
    int y;
    pre[s][0]=p;
    for(int i=1;i<20;i++)pre[s][i]=pre[pre[s][i-1]][i-1];
    up[s]=min(up[s],dep[s]);
    dw[s]=min(dw[s],dep[s]);
    for(int i=0;i<wic[s].size();i++)
        if((y=wic[s][i])!=p)
            dw[y]=min(dw[y],dw[s]);
        else
            up[s]=min(up[s],up[y]);
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i])!=p)
        {
            dep[y]=dep[s]+1;
            dfs(y,s);
        }
}
int lca(int x,int y)
{
    int s=19;
    if(dep[x]>dep[y]) swap(x,y);
    while(dep[x]<dep[y]) y=dep[pre[y][s]]<dep[x]?y:pre[y][s],s--;
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
int main()
{
    int n,q;scanf("%d",&n);
    for(int i=1;i<=n;i++)
        up[i]=dw[i]=10000000;
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
        wic[x].push_back(y);
    }
    dep[1]=1;
    dfs(1,0);
    scanf("%d",&q);
    while(q--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        int d=dep[lca(x,y)];
        int s1=up[x],s2=dw[y];
        if(s1<=d&&s2<=d)puts("Yes");
        else puts("No");
    }
    return 0;
}
