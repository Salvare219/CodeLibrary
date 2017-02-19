#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;


vector<int>gra[300050];
bool vis[300050];
int ans;
int dfs(int s,int p)
{
    int m1=0,m2=0;
    vis[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(gra[s][i]!=p)
        {
            int t=dfs(gra[s][i],s)+1;
            if(m1<t)m2=m1,m1=t;
            else if(m2<t)m2=t;
        }
    ans=max(m1+m2,ans);
    return m1;
}
int com[300050];
int l[300050];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n,m,q;scanf("%d%d%d",&n,&m,&q);
    int x,y;
    for(int i=1;i<=n;i++)
        com[i]=i;
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
        com[find(x)]=find(y);
    }
    for(int i=1;i<=n;i++)
        if(vis[i]==0)
        {
            ans=0;
            dfs(i,0);
            l[find(i)]=ans;
        }
    int ty;
    for(int i=0;i<q;i++)
    {
        scanf("%d",&ty);
        if(ty==1)
        {
            scanf("%d",&x);
            y=find(x);
            printf("%d\n",l[y]);
        }
        else
        {
            scanf("%d%d",&x,&y);
            int a=find(x),b=find(y);
            if(a!=b)
            {
                int p=(l[a]+1)/2+(l[b]+1)/2+1;
                com[a]=b;
                l[b]=max(l[a],max(l[b],p));
            }
        }
    }
    return 0;
}
