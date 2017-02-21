#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;


vector<pair<int,int> >gra[1050];
int n,m;
int dis[1050];
bool inq[1050];
bool spfa_dfs(int s)
{
    int to,w;inq[s]=1;
    for(int i=0;i<gra[s].size();i++)
        if(dis[s]+(w=gra[s][i].second)<dis[to=gra[s][i].first])
        {
            dis[to]=dis[s]+w;
            if(inq[to])return 1;
            spfa_dfs(to);
        }
    inq[s]=0;
}
int main()
{
    while(scanf("%d%d",&n,&m)&&n)
    {
        int x,y,z;
        for(int i=0;i<n;i++)gra[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);x--;y--;
            gra[x].push_back(make_pair(y,z));
            gra[y].push_back(make_pair(x,z));
        }
        for(int i=1;i<n;i++)dis[i]=1<<29;
        spfa_dfs(0);
        printf("%d\n",dis[n-1]);
    }
    return 0;
}
