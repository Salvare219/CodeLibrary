#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;


char maz[55][55];
int sg[55][55];
int dfs(int x,int y)
{
    if(sg[x][y]!=-1) return sg[x][y];
    bool vis[2000]={0};
    if(x && y)
    {
        for(int i=0;i<x;i++)
            for(int j=0;j<y;j++)
                vis[dfs(i,y)^dfs(x,j)]=1;
    }
    if(x==0)
    {
        for(int i=0;i<y;i++)
            vis[dfs(0,i)]=1;
    }
    if(y==0)
    {
        for(int i=0;i<x;i++)
            vis[dfs(i,0)]=1;
    }
    for(int i=0;;i++)
        if(vis[i]==0)
            return sg[x][y]=i;
}
int main()
{
    int n,m;
    memset(sg,-1,sizeof(sg));
    sg[0][0]=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 && m==0) break;
        int sum=0;
        for(int i=0;i<n;i++)
            scanf("%s",maz[i]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(maz[i][j]=='#')
                    sum^=dfs(i,j);
        if(sum) printf("John\n");
        else printf("Jack\n");
    }
    return 0;
}
