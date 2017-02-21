#include<bits/stdc++.h>
using namespace std;

vector<int> gra[160005];
int d[3005][3005];
int n,m;
bool v[3005];
inline void BFS(int s,int dis[])
{
    queue<int>q;
    for(int i=1;i<=n;i++)v[i]=0;
    v[s]=1;dis[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<gra[x].size();i++)
        {
            int y=gra[x][i];
            if(v[y]==0)
            {
                dis[y]=dis[x]+1;
                v[y]=1;
                q.push(y);
            }
        }
    }
}
int main()
{
    //freopen("1.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d",&x,&y);
        gra[x].push_back(y);
        gra[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        BFS(i,d[i]);
    int s1,t1,s2,t2,l1,l2;
    scanf("%d%d%d%d%d%d",&s1,&t1,&l1,&s2,&t2,&l2);
    int ans=-1;
    if(d[s1][t1]<=l1&&d[s2][t2]<=l2)
        ans=max(ans,m-d[s1][t1]-d[s2][t2]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int d1=d[s1][i]+d[i][j]+d[j][t1];
            int d2=d[s2][i]+d[i][j]+d[j][t2];
            if(d1<=l1&&d2<=l2)
                ans=max(ans,m-(d1+d2-d[i][j]));
            d1=d[s1][i]+d[i][j]+d[j][t1];
            d2=d[s2][j]+d[j][i]+d[i][t2];
            if(d1<=l1&&d2<=l2)
                ans=max(ans,m-(d1+d2-d[i][j]));
        }
    if(ans<0)puts("-1");
    else printf("%d\n",ans);
    return 0;
}
