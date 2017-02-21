#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
using namespace std;

struct p
{
    int x,y,w;
    bool operator<(const p&a)const
    {
        return w<a.w;
    }
}e[2005*2005];
int a[2005][2005];
int dis[2005][2005];
vector<pair<int,int> >gra[2005];
void dfs(int st,int s,int p)
{
    int y;
    for(int i=0;i<gra[s].size();i++)
        if((y=gra[s][i].first)!=p)
        {
            dis[st][y]=dis[st][s]+gra[s][i].second;
            dfs(st,y,s);
        }
}
bool ok(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(dis[i][j]!=a[i][j])
                return 0;
    return 1;
}
int com[2005];
int find(int s)
{
    return com[s]==s?s:com[s]=find(com[s]);
}
int main()
{
    //freopen("1.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int k=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(i<j&&a[i][j]>0)
            {
                e[k].x=i;
                e[k].y=j;
                e[k++].w=a[i][j];
            }
        }
    sort(e,e+k);
    for(int i=0;i<n;i++)com[i]=i;
    int p=1,z=0;
    while(p<n&&z<k)
    {
        int x=find(e[z].x),y=find(e[z].y);
        if(x!=y)
        {
            p++;
            com[x]=y;
            gra[e[z].x].push_back(make_pair(e[z].y,e[z].w));
            gra[e[z].y].push_back(make_pair(e[z].x,e[z].w));
        }
        z++;
    }
    if(p<n)
        puts("NO");
    else
    {
        for(int i=0;i<n;i++)
            dfs(i,i,-1);
        puts(ok(n)?"YES":"NO");
    }
    return 0;
}
