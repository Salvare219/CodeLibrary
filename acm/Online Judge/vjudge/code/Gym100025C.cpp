#include <bits/stdc++.h>
using namespace std;


vector<int>gra[300050];
priority_queue<pair<int,int> >as;
queue<int>q,q1;
int deg[300050];
int del[300050];
int ans[300050];
pair<int,int>dfs(int x,int p)
{
    int y;
    pair<int,int>f=make_pair(0,x),g;
    for(int i=0;i<gra[x].size();i++)
        if((y=gra[x][i])!=p)
        {
            g=dfs(y,x);
            if(g.first+1>f.first)
                f.first=g.first+1,f.second=g.second;
        }
    return f;
}
int main()
{
    freopen("amoeba.in","r",stdin);
    freopen("amoeba.out","w",stdout);
    int n,a,b,x,y;scanf("%d%d%d",&n,&a,&b);
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
        deg[x]++;deg[y]++;
    }
    for(int i=1;i<=n;i++)
    {
        as.push(make_pair(deg[i],i));
        if(deg[i]==1)q.push(i);
    }
    int st=1;
    while(1)
    {
        int s=0;
        while(1)
        {
            int s1=as.top().first,s2=as.top().second;
            if(s1!=deg[s2])as.pop(),as.push(make_pair(deg[s2],s2));
            else break;
        }
        ans[st++]=as.top().first;
        while(!q.empty())
        {
            int x=q.front(),y;q.pop();
            del[x]=1;
            for(int i=0;i<gra[x].size();i++)
                if(del[y=gra[x][i]]==0)
                {
                    deg[y]--;
                    if(deg[y]==1)
                        q1.push(y),s++;
                }
        }
        if(s<=1)break;
        while(!q1.empty())q.push(q1.front()),q1.pop();
    }
    pair<int,int> f=dfs(1,0);
    f=dfs(f.second,0);
    for(int i=1;i<=f.first;i++)
        ans[i]=max(ans[i],1);
    for(int i=a;i<=b;i++)
        printf("%d%c",ans[i],i==b?10:32);
    return 0;
}
