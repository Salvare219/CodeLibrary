#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;

int n,m,p;
bool lin[40][40];
long long dp[1<<11];
int te[50];
long long dfs2(int d,int s)
{
    if(d==n) return 1;
    else
    {
        long long sum=0;
        for(int i=m;i<p;i++)
            if(lin[te[d]][i]&&((1<<(i-m))&s)==0)
                sum+=dfs2(d+1,s|(1<<(i-m)));
        return sum;
    }
}
long long find(int s)
{
    if(dp[s]>=0)return dp[s];
    else
    {
        int c=0;
        for(int i=n;i<m;i++)
            if((1<<(i-n))&s)
                te[c++]=i;
        return dp[s]=dfs2(0,0);
    }
}
long long dfs(int d,int s)
{
    if(d==n)
        return find(s);
    else
    {
        long long sum=0;
        for(int i=n;i<m;i++)
            if(lin[d][i]&&((1<<(i-n))&s)==0)
                sum+=dfs(d+1,s|(1<<(i-n)));
        return sum;
    }
}
int main()
{
    while(~scanf("%d%d%d",&n,&m,&p))
    {
        p+=m+n;m+=n;memset(dp,-1,sizeof(dp));
        int q,x,y;scanf("%d",&q);
        memset(lin,1,sizeof(lin));
        while(q--)scanf("%d%d",&x,&y),lin[x-1][y-1]=lin[y-1][x-1]=0;
        printf("%lld\n",dfs(0,0));
    }
    return 0;
}