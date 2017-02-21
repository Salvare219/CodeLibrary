#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int> > v[100005];
int n,m;
int cc[100005];
int vis[100005];
queue<int> q;

bool j(int c)
{
    while(!q.empty())
        q.pop();
    memset(vis,0,sizeof(vis));
    int x,y,i,j;
    int f;
    vis[1]=2;
    q.push(1);
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        for(i=0,j=v[x].size();i<j;i++)
        {
            y=v[x][i].first;
            if(vis[x]==1&&v[x][i].second>c)
                continue;
            f=2;
            if(vis[x]==1||v[x][i].second>c)
                f=1;
            if(vis[y]>=f)
                continue;
            vis[y]=f;
            q.push(y);
            if(y==n)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int i,l,r,mm,a,b,c;
    scanf("%d%d",&n,&m);
    if(n==1)
        return puts("0");
    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        v[a].push_back(make_pair(b,c));
        v[b].push_back(make_pair(a,c));
        cc[i]=c;
    }
    cc[i]=0;
    sort(cc,cc+m+1);
    l=0;r=m;
    while(l<r)
    {
        mm=(l+r)/2;
        if(j(cc[mm]))
            r=mm;
        else
            l=mm+1;
    }
    printf("%d\n",r==m?-1:cc[r]);
    return 0;
}
