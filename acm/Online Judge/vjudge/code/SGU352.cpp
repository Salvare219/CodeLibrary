#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

vector<pair<int,int> >g1[5000],g2[5000],lca[5000];
vector<int>wg[5000];
int ans[5000],com[5000],dis[5000],h[5000];
int dfn[5000],ed[5000][2],cnt;
bool v[5000];
inline int find(int s)
{
    return s==com[s]?s:com[s]=find(com[s]);
}
void dfs2(int s,int p)
{
    int x,y;
    for(int i=ed[s][0];i<ed[s][1];i++)
        ans[s]=min(ans[s],h[dfn[i]]-dis[s]);
    for(int i=0;i<lca[s].size();i++)
    {
        x=lca[s][i].first;y=lca[s][i].second;
        h[x]=min(h[x],dis[x]+dis[y]+wg[s][i]);
        h[y]=min(h[y],dis[x]+dis[y]+wg[s][i]);
    }
    for(int i=0;i<g1[s].size();i++)
        if((y=g1[s][i].first)!=p)dfs2(y,s);
}
void dfs(int s,int p)
{
    int y;v[s]=1;dfn[cnt]=s;ed[s][0]=cnt++;
    for(int i=0;i<g2[s].size();i++)
        if(v[y=g2[s][i].first])
            lca[find(y)].push_back(make_pair(s,y)),wg[find(y)].push_back(g2[s][i].second);
    for(int i=0;i<g1[s].size();i++)
        if((y=g1[s][i].first)!=p)dis[y]=dis[s]+g1[s][i].second,dfs(y,s),com[y]=s;
    ed[s][1]=cnt;
}
int main()
{
    int n,m,a,b,l,t;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d%d",&a,&b,&l,&t);
        if(t)g1[a].push_back(make_pair(b,l)),g1[b].push_back(make_pair(a,l));
        else g2[a].push_back(make_pair(b,l)),g2[b].push_back(make_pair(a,l));
    }
    for(int i=1;i<=n;i++)com[i]=i,h[i]=ans[i]=200000000;
    cnt=0;dfs(1,0);
    dfs2(1,0);
    for(int i=2;i<=n;i++)
        printf("%d%c",ans[i]<100000000?ans[i]:-1,i==n?10:' ');
    return 0;
}
