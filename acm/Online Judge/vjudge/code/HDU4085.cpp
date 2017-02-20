#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;


int w[105][105];
int d[105][105];
int dp[105][1<<10];
int cnt[50];
int dp2[1<<10];
int v[105];
int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<35;i++)
        cnt[i]=__builtin_popcount(i);
    while(t--)
    {
        int n,m,k;scanf("%d%d%d",&n,&m,&k);
        int x,y,z;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                w[i][j]=1<<20;
            w[i][i]=0;
        }
        int sum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);sum+=z;
            w[x][y]=w[y][x]=min(w[x][y],z);
        }
        for(int z=1;z<=n;z++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    w[i][j]=min(w[i][j],w[i][z]+w[z][j]);
        int lim=1<<(2*k);
        for(int i=1;i<=n;i++)
            for(int j=0;j<lim;j++)
                dp[i][j]=1<<20;
        for(int i=1;i<=k;i++)
            dp[i][1<<i-1]=dp[n-i+1][1<<k+i-1]=0;
        queue<int>q;
        for(int s=1;s<lim;s++)
        {
            for(int i=1;i<=n;i++)
                for(int f=s;f;f=(f-1)&s)
                {
                    dp[i][s]=min(dp[i][s],dp[i][f]+dp[i][f^s]);
                    if(dp[i][s]<(1<<20)&&v[i]==0)
                        q.push(i),v[i]=1;
                }
            while(!q.empty())
            {
                int x=q.front();
                v[x]=0;q.pop();
                for(int i=1;i<=n;i++)
                    if(dp[i][s]>dp[x][s]+w[x][i])
                    {
                        dp[i][s]=dp[x][s]+w[x][i];
                        if(v[i]==0)
                            q.push(i),v[i]=1;
                    }
            }
            //for(int i=1;i<=n;i++)
            //    for(int j=1;j<=n;j++)
            //        dp[i][s]=min(dp[i][s],dp[j][s]+w[i][j]);
        }
        int l=(1<<k)-1;
        for(int i=0;i<lim;i++)
        {
            dp2[i]=1<<20;
            for(int j=1;j<=n;j++)
                dp2[i]=min(dp2[i],dp[j][i]);
        }
        for(int i=0;i<lim;i++)
            if(cnt[i>>k]==cnt[i&l])
                for(int j=i;j;j=i&(j-1))
                    if(cnt[j>>k]==cnt[j&l])
                        dp2[i]=min(dp2[i],dp2[j]+dp2[j^i]);
        if(dp2[lim-1]<=sum)printf("%d\n",dp2[lim-1]);
        else puts("No solution");
    }
    return 0;
}
