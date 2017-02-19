#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
using namespace std;


int dp[55][50090];
int dfs(int x,int y)
{
    if(x==0&&y==0)return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    int f=1;
    if(y==0)
    {
        if(x>=2)f=min(f,dfs(x-2,2));
        if(x>=1)f=min(f,dfs(x-1,0));
    }
    else if(y==2)
    {
        if(x>=2)f=min(f,dfs(x-2,5));
        if(x>=1)
        {
            f=min(f,dfs(x-1,2));
            f=min(f,dfs(x-1,3));
        }
        f=min(f,dfs(x+1,0));
    }
    else
    {
        if(x>=2)f=min(f,dfs(x-2,y+3));
        if(x>=1)
        {
            f=min(f,dfs(x-1,y));
            f=min(f,dfs(x-1,y+1));
        }
        f=min(f,dfs(x,y-1));
    }
    return dp[x][y]=f^1;
}
int main()
{
    int t,ti=1;scanf("%d",&t);
    memset(dp,0xff,sizeof(dp));
    dp[0][0]=0;
    while(t--)
    {
        int n,x;scanf("%d",&n);
        int c1=0,c2=0,sum=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x==1)c1++;
            else c2++,sum+=x;
        }
        if(c2)sum+=c2-1;
        printf("Case #%d: %s\n",ti++,dfs(c1,sum)?"Alice":"Bob");
    }
    return 0;
}

