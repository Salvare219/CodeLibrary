#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
struct priority_min
{
    int d[300005],p[300005],f[300005],sz;
    void push(int s,int x)
    {
        int y=sz++;
        while((y>>1)&&d[p[y>>1]]>x)
            p[y]=p[y>>1],f[p[y]]=y,y>>=1;
        d[s]=x;p[y]=s;f[s]=y;
    }
    void pop(int s)
    {
        if(f[s]==--sz)return;
        int x=d[p[sz]],y=f[s],z;
        while(y>>1)p[y]=p[y>>1],f[p[y]]=y,y>>=1;
        while((z=y<<1)<sz&&d[p[y]]<x)
        {
            if(z+1<sz&&d[p[z]]>d[p[z+1]])z++;
            p[y]=p[z];f[p[y]]=y;y=z;
        }
        p[y]=p[sz];f[p[y]]=y;
    }
}q;
vector<pair<int,int> >gra[300005];
bool vis[300005];
int Dijkstra(int s,int t)
{
    int dis,x,y,w;
    for(int i=0;i<n;i++)vis[i]=0;
    vis[s]=q.sz=1;q.push(s,0);
    while(q.sz!=1)
    {
        x=q.p[1];dis=q.d[x];q.pop(x);
        if(x==t)return dis;
        for(int j=0;j<gra[x].size();j++)
        {
            y=gra[x][j].first;w=gra[x][j].second;
            if(vis[y]==0)vis[y]=1,q.push(y,dis+w);
            else if(q.d[y]>dis+w)q.pop(y),q.push(y,dis+w);
        }
    }
    return -1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int x,y,z;
        for(int i=0;i<n;i++)gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            gra[x].push_back(make_pair(y,z));
            gra[y].push_back(make_pair(x,z));
        }
        scanf("%d%d",&x,&y);
        printf("%d\n",Dijkstra(x,y));
    }
    return 0;
}