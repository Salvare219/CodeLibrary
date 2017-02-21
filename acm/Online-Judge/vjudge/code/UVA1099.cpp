#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int s[16],sum[1<<15];
bool dp[105][1<<15],vis[105][1<<15];
bool dfs(int x,int s)
{
    if(vis[x][s])return dp[x][s];vis[x][s]=1;
    if((s-1)&s)
    {
        int y=sum[s]/x;
        for(int i=(s-1)&s;i;i=(i-1)&s)
        {
            if(sum[i]%y==0&&dfs(sum[i]/y,i)&&dfs(sum[i^s]/y,i^s))return dp[x][s]=1;
            if(sum[i]%x==0&&dfs(min(x,sum[i]/x),i)&&dfs(min(x,sum[i^s]/x),i^s))return dp[x][s]=1;
        }
        return dp[x][s]=0;
    }
    else return dp[x][s]=1;
}
int main()
{
    int n,x,y,ti=1;
    while(scanf("%d",&n)&&n)
    {
        scanf("%d%d",&x,&y);
        for(int i=0;i<n;i++)
            scanf("%d",s+i);
        int lim=1<<n;memset(vis,0,sizeof(vis));
        for(int i=0;i<lim;i++)
            for(int j=sum[i]=0;j<n;j++)
                if((1<<j)&i)sum[i]+=s[j];
        printf("Case %d: ",ti++);
        if(sum[lim-1]!=x*y)puts("No");
        else puts(dfs(min(x,y),lim-1)?"Yes":"No");
    }
    return 0;
}