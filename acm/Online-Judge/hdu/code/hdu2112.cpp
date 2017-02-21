#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,m;
struct priority_min
{
    int d[10050],p[10050],f[10050],sz;
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
vector<pair<int,int> >gra[10050];
int dij(int s,int t)
{
    int dis,x,y,w;q.sz=1;
    for(int i=1;i<=n;i++)
        if(i!=s)q.push(i,0x3fffffff);
        else q.push(i,0);
    for(int i=1;i<n;i++)
    {
        x=q.p[1];dis=q.d[x];q.pop(x);
        if(x==t)break;
        for(int j=0;j<gra[x].size();j++)
            if(q.d[y=gra[x][j].first]>dis+(w=gra[x][j].second))
            {
                q.pop(y);
                q.push(y,dis+w);
            }
    }
    if(q.d[t]<0x3fffffff)return q.d[t];
    else return -1;
}
bool inque[155];
int now[155];
#include<queue>
int spfa(int s,int e)
{
    int x,w,to;
    queue<int> que;
    memset(inque,0,sizeof(inque));
    for(int i=1;i<=n;i++) now[i]=0x3fffffff;
    que.push(s);now[s]=0;
    while(!que.empty())
    {
        x=que.front();que.pop();
        inque[x]=0;
        for(int i=0;i<gra[x].size();i++)
        {
            to=gra[x][i].first;
            w=gra[x][i].second;
            if(now[to]>now[x]+w)
            {
                now[to]=now[x]+w;
                if(inque[to]) continue;
                inque[to]=1;
                que.push(to);
            }
        }
    }
    if(now[e]<0x3fffffff) return now[e]; //终点为e
    else return -1;
}
#include<iostream>
#include<map>
#include<string>
map<string,int>mp;
string a,b;
int main()
{
    while(scanf("%d",&m)&&m!=-1)
    {
        int x,y,z;mp.clear();
        for(int i=1;i<=150;i++)gra[i].clear();
        cin>>a>>b;
        bool f=0;
        if(a==b) f=1;
        mp[a]=1;mp[b]=2;n=3;
        for(int i=0;i<m;i++)
        {
            cin>>a>>b>>z;
            if(mp[a])x=mp[a];
            else x=mp[a]=++n;
            if(mp[b])y=mp[b];
            else y=mp[b]=++n;
            gra[x].push_back(make_pair(y,z));
            gra[y].push_back(make_pair(x,z));
        }
        if(f) printf("0\n");
        else printf("%d\n",spfa(1,2));
    }
    return 0;
}